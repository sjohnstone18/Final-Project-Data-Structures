#include  "ER.h"
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
	do {
		simulation->update();
	} while (simulation->isdone() == false);
	
	







	return 0;
}