#ifndef Person_h
#define Person_h
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Person{
private:
	string name;
	int severity;
	vector<int> history;
	int timein;

public:
	string getName() {
		return name;
	}
	int getSeverity() {
		return severity;
	}
	vector<int> getHistory() {
		return history;
	}
	int getTimeIn() {
		return timein;
	}
	void setSeverity(int sev) {
		severity = sev;
	}
	void setTimeIn(int ti) {
		timein = ti;
	}

	Person(string nm) {
		name = nm;
		history.clear();
		severity = 0;
	}

};

#endif 
