#pragma once
#ifndef Nurse_h
#define Nurse_h
#include <iostream>
#include "Person.h"
#include "Medical.h"
#include <queue>
using namespace std;


class Nurse : public Medical {


public:
	Nurse() {
		maxSeverity = 10;
		timeRange = 10;
		num_served = 0;
	}



};

#endif
