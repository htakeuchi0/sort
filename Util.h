#ifndef UTIL_H_20171116_0952_
#define UTIL_H_20171116_0952_

#include "IExecute.h"

class Util {
public:
	static long long GetTime(IExecute *obj, int times = 10);
};

#endif // UTIL_H_20171116_0952_