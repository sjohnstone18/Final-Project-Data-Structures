#ifndef Person_h
#define Person_h
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Person{
private:
	string name;
	int severity=0;
	vector<int> history;
	int timein;

public:
	bool operator<(const Person& better) const {
		return severity < better.severity;
	}

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
	void sethistory() {
		history.push_back(severity);
	}
	Person(string nm) {
		name = nm;
		history.clear();
		severity = 0;
	}

};

class Compare {
public:
	bool operator()(Person* p1, Person* p2)
	{
		return p1->getSeverity() < p2->getSeverity();
	}
};


#endif 
