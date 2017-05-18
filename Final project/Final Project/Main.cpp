#include  "ER.h"
#include <fstream>
#include <string>
using namespace std;

int menu(int u) {
	do {
		cout << "SIMULATION STATS:" << endl;
		cout << "-----------------" << endl;
		cout << "1) Find patient" << endl;
		cout << "2) General stats" << endl;
		cout << "3) Exit" << endl;
		cout << "Select: ";
		cin >> u;
	} while (u != 1 && u != 2 && u != 3);
	return u;
}

void opt1(ER* sim) {
	string name;
	cout << "Enter a patient name: ";
	cin >> name;
	

	bool found = false;
	for (int i = 0; i < 2000; i++) {
		if (sim->population[i]->getName() == name)
		{
			cout << "Patient history:" << endl;
			for (int i = 0; i < sim->population[i]->getHistory().size(); i++) {
				cout << "Visit #" << (i + 1) << " severity: " << sim->population[i]->getHistory()[i];
			}
			found = true;
		}
	}
	if (found == false) {
		cout << "Could not find patient." << endl;
	}
}

void opt2(ER* sim) {
	for (int i = 0; i < 2000; i++) {
		if (!sim->population[i]->getHistory().empty()) {
			cout << sim->population[i]->getName() << endl;
			for (int j = 0; i < sim->population[i]->getHistory().size(); j++) {
				cout << "Visit #" << (j + 1) << " severity: " << sim->population[i]->getHistory()[j];
			}
			cout << endl;
		}
	}
}


int main() {
	
	
	int maxtime, docs, nurses, rate;

	cout << "Welcome to Tyler and Sam's Emergency Room simulator\nPlease enter the length of the simulation: ";
	//cin >> maxtime;
	cout << "Please enter the number of Doctors: ";
	//cin >> docs;
	cout << "Please enter the Number of Nurses: ";
	//cin >> nurses;
	cout << "Please enter the rate of Patients arriving in patients per hour: ";
	//cin >>rate;
	//ER* simulation = new ER(docs, nurses, maxtime, rate);
	ER* simulation = new ER(5, 5, 5, 60000);
	ifstream file1;
	ifstream file2;
	file1.open("..\\residents_of_273ville.txt");
	if (file1.fail()) {
		cout << "ERROR file1 failed: ";
		return 0;
	}
	file2.open("..\\surnames_of_273ville.txt");
	if (file2.fail()) {
		cout << "ERROR file2 failed";
		return 0;
	}

	string first, last, name;
	int i = 0;
		while (file1 >> first && file2 >> last && i<2000) {
			name = first + " " + last;
			simulation->population[i] = new Person(name);
			i++;
		}


	file1.close();
	file2.close();
	cout << "finished population creation. \n";
	do {
		simulation->update();
	} while (simulation->isdone() == false);
	
	int user = 0;
	do {
		user = menu(0);
		if (user == 1) {
			opt1(simulation);
		}
		if (user == 2) {
			opt2(simulation);
		}
		if (user == 3) {
			break;
		}
	} while (user);




	return 0;
}