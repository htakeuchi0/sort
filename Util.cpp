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

	// 初期化＋実行時間
	auto start = std::chrono::system_clock::now();
	bool succeeded = false;
	for (int i = 0; i < times; i++) {
		obj->Initialize();
		succeeded |= obj->Execute();
	}
	auto end = std::chrono::system_clock::now();
	auto dur = end - start;

	// 初期化にかかった時間
	start = std::chrono::system_clock::now();
	for (int i = 0; i < times; i++) {
		obj->Initialize();
	}
	end = std::chrono::system_clock::now();
	dur -= end - start;
	
	if (!succeeded) {
		std::cerr << "実行中にエラーが発生しました" << std::endl;
		return 0L;
	}

	auto msec = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count() / times;
	return msec;
}
