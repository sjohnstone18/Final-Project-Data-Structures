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



class ER {
private:
	vector<Medical *> staff;
	vector <Person *> lowpriority; //this needs to change to priority queue
	vector <Person *> highpriority;
	Person* population[2000];
	int clock;//current time in minutes
	int maxTime; //how long to run simulation
	int hurtRateHour; //rate of people arriving per hour

public:
	ER(int Docs, int Nurses, int maxtime, int rate) {
		for (int i = 0; i < Docs; i++)
		{
			staff.push_back(new Doctor);
		}
		for (int i = 0; i < Nurses; i++) {
			staff.push_back(new Nurse);
		}
		maxTime = maxtime;
		hurtRateHour = rate;
	}

	void update()
	{
		for (int i = 0; i < staff.size(); i++) {
			if (staff[i]->helper.empty()) {								//If any of the staff are not helping anyone, fetch next person
				if (typeid(staff[i]) == typeid(Doctor)) {			//if its a doctor, check high priority first. 
					if (!highpriority.empty())
					{
						staff[i]->helper.push(highpriority.front());
						highpriority.erase(highpriority.begin());
					}
					else if (!lowpriority.empty())
					{
						staff[i]->helper.push(lowpriority.front());
						lowpriority.erase(lowpriority.begin());
					}
				}
				if (typeid(staff[i]) == typeid(Nurse)) {				//if its a Nurse, only check low priority
					if (!lowpriority.empty())
					{
						staff[i]->helper.push(lowpriority.front());
						lowpriority.erase(lowpriority.begin());
					}
				}
			}
		}																//end of Doctor update system
																		//start of new pateint entering
		Random *random = new Random();
		if (random->next_int(60) > 45) {
			Person* newpatient1 = population[random->next_int(2000)];	//picks person from the array of population
			newpatient1->setSeverity(random->next_int(19) + 1);			//assigns severity.  does 19+1 to guarantee no severities of 0
			newpatient1->setTimeIn(clock);								//sets start time
			if (newpatient1->getSeverity() > 10)						//sends to highpriority if higher than 10
				highpriority.push_back(newpatient1);
			else
				lowpriority.push_back(newpatient1);
		}
		if (random->next_int(60) > 45) {								//DOES 2 TO REDUCE TO PREVENT 60 PER HOUR TURNINGINTO EXACTLY 1/MIN, AND ALLOWS FOR 2 IN 1 MINUTE
			Person* newpatient1 = population[random->next_int(2000)];	
			newpatient1->setSeverity(random->next_int(19) + 1);			
			newpatient1->setTimeIn(clock);								
			if (newpatient1->getSeverity() > 10)						
				highpriority.push_back(newpatient1);
			else
				lowpriority.push_back(newpatient1);
		}

		clock++;
	}



};


#endif // !ER.h
