#pragma once
#ifndef ER_h
#define ER_h
#include <iostream>
#include "Person.h"
#include "Medical.h"
#include "Doctor.h"
#include "Nurse.h"
#include "Random.h"
#include <queue>
using namespace std;

Random random;

class ER {
private:
	vector<Medical *> staff;
	priority_queue <Person *> lowpriority; //this needs to change to priority queue
	priority_queue <Person *> highpriority;
	
	int clock;//current time in minutes
	int maxTime; //how long to run simulation
	int hurtRateHour; //rate of people arriving per hour
	int totaltime = 0, numserved = 0;

public:
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
						lowpriority.pop();
					}
				}
				else if (staff[i]->getMax_Severity() == 10) {				//if its a Nurse, only check low priority
					if (!lowpriority.empty())
					{
						staff[i]->helper.push(lowpriority.top());
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
			newpatient1->setSeverity(random.next_int(19) + 1);			//assigns severity.  does 19+1 to guarantee no severities of 0
			newpatient1->setTimeIn(clock);								//sets start time
			if (newpatient1->getSeverity() > 10)						//sends to highpriority if higher than 10
				highpriority.push(newpatient1);
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
