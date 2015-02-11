#include "RNG.h"
#include <cstdlib>
#include <ctime>

#define SMALL_RANGE 0.2
#define BIG_RANGE 0.5
#define DEFAULT_THRESHOLD 50
#define MAX 100


int RNG::LowerBoundGen(int value, float range)
{
	return (value - (range * value));
};

int RNG::UpperBoundGen(int value, float range)
{
	return ((value + (range * value)) - LowerBoundGen(value, range) + 1);
};

int RNG::SmallRange(int seed)
{
	int number = (std::rand() % UpperBoundGen(seed, SMALL_RANGE)) + LowerBoundGen(seed, SMALL_RANGE);
	return number;
};

int RNG::BigRange(int seed)
{
	int number = (std::rand() % UpperBoundGen(seed, BIG_RANGE)) + LowerBoundGen(seed, BIG_RANGE);
	return number;
};

bool RNG::FortuneLoop(int value, int threshold)
{
	int number;
	for (int i = 0; i < value; i++)
	{
		number = (std::rand() % MAX) + 1;
		if (number > threshold + value)
			return true;
	}
	return false;
}

bool RNG::FortuneLoop(int value)
{
	return FortuneLoop(value, DEFAULT_THRESHOLD);
}

int RNG::NumberFromTo(int lower_bound, int upper_bound)
{
	int number = (std::rand() % (upper_bound - lower_bound + 1)) + lower_bound;
	return number;
}

RNG::RNG()
{
	srand(time(NULL));
}