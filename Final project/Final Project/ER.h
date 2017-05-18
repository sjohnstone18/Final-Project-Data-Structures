#pragma once
#ifndef ER_h
#define ER_h
#include <iostream>
#include <queue>
#include "Random.h"
#include "Person.h"
#include "Medical.h"
#include "Doctor.h"
#include "Nurse.h"


using namespace std;

Random random;

class ER {
private:
	vector<Medical *> staff;
	priority_queue <Person *, vector<Person*>, Compare> lowpriority; //this needs to change to priority queue
	priority_queue <Person *, vector<Person*>, Compare> highpriority;
	
	int clock;//current time in minutes
	int maxTime; //how long to run simulation
	int hurtRateHour; //rate of people arriving per hour
	int totaltime = 0, numserved = 0;

public:
	int getTotaltime() {
		return totaltime;
	}
	int getNumberServed() {
		return numserved;
	}
	Person* population[2000];
	ER(int Docs, int Nurses, int maxtime, int rate) {
		for (int i = 0; i < Docs; i++)
		{
			staff.push_back(new Doctor);
		}
		for (int i = 0; i < Nurses; i++) {
			staff.push_back(new Nurse);
		}
		clock = 0;
		maxTime = maxtime;
		hurtRateHour = rate;
	}
	bool isdone() {
		if (clock >= maxTime)
			return true;
		else
			return false;

	}
	void update()
	{
		for (int i = 0; i < staff.size(); i++) {
			if (staff[i]->helper.empty()) {								//If any of the staff are not helping anyone, fetch next person
				if (staff[i]->getMax_Severity() == 20) {			//if its a doctor, check high priority first. 
					if (!highpriority.empty())
					{
						staff[i]->helper.push(highpriority.top());
						staff[i]->setRealtime();
						highpriority.pop();
					}
					else if (!lowpriority.empty())
					{
						staff[i]->helper.push(lowpriority.top());
						staff[i]->setRealtime();
						lowpriority.pop();
					}
				}
				else if (staff[i]->getMax_Severity() == 10) {				//if its a Nurse, only check low priority
					if (!lowpriority.empty())
					{
						staff[i]->helper.push(lowpriority.top());
						staff[i]->setRealtime();
						lowpriority.pop();
					}
				}
			}
		}																//end of Doctor update system
																		//start of new patient entering
	
		//int randon = random->next_int(hurtRateHour);
		//int perp = random->next_int(2000);
		//int sev = random->next_int(19) + 1;
		if (random.next_int(60) < hurtRateHour) {
			Person* newpatient1 = population[random.next_int(2000)];	//picks person from the array of population
			int rand1 = random.next_int(10);
			if (rand1 < 1) {
				int rand2 = random.next_int(5);
				newpatient1->setSeverity(rand2 + 16);
			}
			else if (rand1 < 3) {
				int rand3 = random.next_int(5);
				newpatient1->setSeverity(rand3 + 11);
			}
			else {
				int rand4 = random.next_int(10);
				newpatient1->setSeverity(rand4 + 1);
			}
	
			newpatient1->setTimeIn(clock);								//sets start time
			if (newpatient1->getSeverity() > 10) {						//sends to highpriority if higher than 10
				highpriority.push(newpatient1);
			}
			else
				lowpriority.push(newpatient1);
		}
		for (int i = 0; i < staff.size(); i++) {
			if (!staff[i]->helper.empty()) {
				if (clock - staff[i]->helper.front()->getTimeIn() > staff[i]->getRealtime()) {
					staff[i]->addTime(clock - staff[i]->helper.front()->getTimeIn());
					staff[i]->clearPatient();
					staff[i]->incPatients();

				}
			}
		}






		clock++;
	}
	void calcItALL() {
		for (int i = 0; i < staff.size(); i++) {
			totaltime += staff[i]->gettotaltime();
			numserved += staff[i]->getNum_Served();

		}
	}

};


#endif // !ER.h
