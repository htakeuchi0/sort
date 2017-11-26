#include "Util.h"
#include <chrono>
#include <iostream>

// 実行時間の計測
long long Util::GetTime(IExecute *obj, int times){
	if (times <= 0) {
		times = Util::kDefaultTimes;
	}

	if(obj == nullptr){
		std::cerr << "実行できません" << std::endl;
		return 0L;
	}

	// 初期化にかかる時間
	auto start = std::chrono::system_clock::now();
	for (int i = 0; i < times; i++) {
		obj->Initialize();
	}
	auto end = std::chrono::system_clock::now();
	auto dur_for_init = end - start;

	// 初期化＋実行時間
	start = std::chrono::system_clock::now();
	bool succeeded = false;
	for (int i = 0; i < times; i++) {
		obj->Initialize();
		succeeded |= obj->Execute();
	}
	end = std::chrono::system_clock::now();
	auto dur = end - start;

	// 初期化にかかった時間を除く
	dur -= dur_for_init;
	
	// 失敗したときエラーを返す
	if (!succeeded) {
		std::cerr << "実行中にエラーが発生しました" << std::endl;
		return 0L;
	}

	// 1回あたりの実行時間を求める
	auto msec = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count() / times;
	return msec;
}

// 配列がソート済みのときtrueを返す
bool Util::Ordered(Sort *sort) {
	size_t size = sort->Size();
	int *arr = new int[size];
	sort->Array(arr);

	bool ordered = true;
	for (size_t i = 1; i < size; i++){
		ordered &= arr[i - 1] <= arr[i];	
	}
	delete[] arr;
	arr = nullptr;

	return ordered;
}
