#pragma once
#ifndef Medical_h
#define Medical_h
#include <iostream>
#include "Person.h"
#include "Random.h"
#include <queue>
using namespace std;

extern Random random;

class Medical {
protected:
	int maxSeverity; //this and timerange differ between doctors and nurses, but not betweeen doctors.  
	int timeRange;
	int realtime;  // this is how long this pateint will take.  updates when taking in a patient.  1-10 for nurses, 1-20 for doctors
	int num_served; // increments when finished helping someone
	int totaltime;//sum of what everyone helped by this doc has waited.  

public:
	int getNum_Served() {
		return num_served;
	}
	int getMax_Severity() {
		return maxSeverity;
	}
	int getRealtime() {
		return realtime;
	}
queue<Person*> helper;
void addTime(int time) {
	totaltime += time;
}
void incPatients() {
	num_served++;
}
void setRealtime() {
	realtime = random.next_int(timeRange - 1) + 1;
}
void clearPatient() {
	helper.front()->sethistory();
	helper.front()->setSeverity(0);
	helper.front()->setTimeIn(0);
	if (!helper.empty())
		helper.pop();

	}

	



};


#endif // !Medical.h
