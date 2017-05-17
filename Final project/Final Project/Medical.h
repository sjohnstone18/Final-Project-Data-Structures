#pragma once
#ifndef Medical_h
#define Medical_h
#include <iostream>
#include "Person.h"
#include <queue>
using namespace std;



class Medical {
protected:
	int maxSeverity;
	
	int timeRange;
	int num_served;

public:
	int getNum_Served() {
		return num_served;
	}
	int getMax_Severity() {
		return maxSeverity;
	}
queue<Person*> helper;







};


#endif // !Medical.h
