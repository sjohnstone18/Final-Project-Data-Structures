#ifndef RANDOM_H_
#define RANDOM_H_

#include <cstdlib>
#include <ctime>

class Random {
	public:
		Random() {
			srand((unsigned int)std::time(0));
		}


};



#endif