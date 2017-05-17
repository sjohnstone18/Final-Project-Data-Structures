#pragma once
#ifndef ER_h
#define ER_h
#include <iostream>
#include "Person.h"
#include "Medical.h"
#include "Doctor.h"
#include "Nurse.h"
#include <queue>
using namespace std;



class ER {
private:
	vector<Medical *> staff;
	vector <Person *> lowpriority; //this needs to change to priority queue
	vector <Person *> highpriority;
	int clock;//current time
	int maxTime; //how long to run simulation

public:
	ER(int Docs, int Nurses, int maxtime, int rate) {
		for (int i = 0; i < Docs; i++)
		{
			staff.push_back(new Doctor);
		}
		for (int i = 0; i < Nurses; i++) {
			staff.push_back(new Nurse);
		}

	}

	void update() {
		for (int i = 0; i < staff.size(); i++) {
			if (staff[i]->helper.empty) {								//If any of the staff are not helping anyone, fetch next person
				if (typeid(staff[i]) == typeid(Doctor)) {			//if its a doctor, check high priority first. 
					if (!highpriority.empty)
					{
						staff[i]->helper.push(highpriority.front());
						highpriority.erase(highpriority.front);
					}
					else if (!lowpriority.empty)
					{
						staff[i]->helper.push(lowpriority.front());
						lowpriority.erase(lowpriority.front);
					}
				}
				if (typeid(staff[i]) == typeid(Nurse)) {				//if its a Nurse, only check low priority
					if (!lowpriority.empty)
					{
						staff[i]->helper.push(lowpriority.front());
						lowpriority.erase(lowpriority.front);
					}
				}
			}
		}


		clock++;
	}



};


#endif // !ER.h
