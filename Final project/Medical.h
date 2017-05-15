#pragma once
#ifndef Medical_h
#define Medical_h
#include <iostream>
#include "Person.h"
#include <queue>
using namespace std;



class Medical {
private:
	int maxSeverity;
	queue<Person*> helper;
	int timeRange;
	int num_served;

public:
	int getNum_Served() {
		return num_served;
	}
	int getMax_Severity() {
		return maxSeverity;
	}








};


#endif // !Medical.h
