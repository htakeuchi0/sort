#include "Util.h"
#include <chrono>
#include <iostream>

long long Util::GetTime(IExecute *obj, int times){
	if (times <= 0) {
		times = 10;
	}

	if(obj == nullptr){
		return 0L;
	}

	auto start = std::chrono::system_clock::now();
	bool succeeded = false;
	for (int i = 0; i < times; i++) {
		obj->Reset();
		succeeded |= obj->Execute();
	}
	auto end = std::chrono::system_clock::now();
	auto dur = end - start;

	if (!succeeded) {
		std::cerr << "ŽÀs’†‚ÉƒGƒ‰[‚ª”­¶‚µ‚Ü‚µ‚½" << std::endl;
	}

	auto msec = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count() / times;
	return msec;
}
