#ifndef RNG_H_ 
#define RNG_H_

#include "weapons.h"


class RNG
{
public:
	RNG();
	int SmallRange(int seed);
	int BigRange(int seed);
	int LowerBoundGen(int value, float range);
	int UpperBoundGen(int value, float range);
	bool FortuneLoop(int skill_level, int threshold);
	bool FortuneLoop(int skill_level);
	int NumberFromTo(int lower_bound, int upper_bound);
};

#endif