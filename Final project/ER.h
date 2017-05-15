#pragma once
#ifndef ER_h
#define ER_h
#include <iostream>
#include "Person.h"
#include "Medical.h"
#include <queue>
using namespace std;



class ER {
private:
	vector<Medical *> staff;
	vector <Person *> waiting; //this needs to change to priority queue
	int clock;//current time
	int maxTime; //how long to run simulation

public:
	                   ER(int Docs, int Nurses, int maxtime, int rate, )





};


#endif // !ER.h
