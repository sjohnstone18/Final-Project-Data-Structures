#pragma once
#ifndef Doctor_h
#define Doctor_h
#include <iostream>
#include "Person.h"
#include "Medical.h"
#include <queue>
using namespace std;


class Doctor : public Medical {


public:
	Doctor() {
		maxSeverity = 20;
		timeRange = 20;
		num_served = 0;
		totaltime;
		realtime = 0;
	}



};














#endif // !Medical.h
