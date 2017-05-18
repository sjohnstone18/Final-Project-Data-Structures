#include  "ER.h"
#include <fstream>
#include <string>
using namespace std;

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
	ER* simulation = new ER(5, 5, 5, 60);
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
	
	







	return 0;
}