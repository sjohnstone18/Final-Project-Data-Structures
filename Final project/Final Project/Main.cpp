#include  "ER.h"
#include <fstream>
#include <string>
using namespace std;

int main() {
	
	
	int maxtime, docs, nurses, rate;

	cout << "Welcome to Tyler and Sam's Emergency Room simulator\nPlease enter the length of the simulation: ";
	cin >> maxtime;
	cout << "Please enter the number of Doctors: ";
	cin >> docs;
	cout << "Please enter the Number of Nurses: ";
	cin >> nurses;
	cout << "Please enter the rate of Patients arriving in patients per hour: ";
	cin >>rate;
	ER* simulation = new ER(docs, nurses, maxtime, rate);
	
	ifstream file1;
	ifstream file2;
	file1.open("C:\\Users\\sjohn\\Desktop\\Final-Project-Data-Structures\\Final project\\residents_of_273ville.txt");
	if (file1.fail()) {
		std::cout << "ERROR file1 failed: ";
		return 0;
	}
	file2.open("C:\\Users\\sjohn\\Desktop\\Final-Project-Data-Structures\\Final project\\surnames_of_273ville.txt");
	if (file2.fail()) {
		cout << "ERROR file2 failed";
		return 0;
	}
	string word;
	word.clear();
	bool dofirst = true;
	for(int i= 0; i<2000; i++) {
		if (dofirst == true) {
			char character = file1.get();
			if (isalpha(character))//only does actions if it is a lettered word; adds letters to word
			{
				word = word + character;
			}
			else if (isspace(character))
			{
				word = word + " ";
				dofirst = false;
			}

		}
		else {
			char character = file2.get();
			if (isalpha(character))//only does actions if it is a lettered word; adds letters to word
			{
				word = word + character;
			}
			else if (isspace(character))
			{
				simulation->population[i] = new Person(word);
				dofirst = true;
			}
		}
	}
	file1.close();
	file2.close();
	cout << "finished population creation. \n";
	do {
		simulation->update();
	} while (simulation->isdone() == false);
	
	







	return 0;
}