#ifndef UTIL_H_20171116_0952_
#define UTIL_H_20171116_0952_

#include "IExecute.h"
#include "Sort.h"

// ユーティリティ
class Util {
public:
	// 実行時間の計測
	static long long GetTime(IExecute *obj, int times = 10);

	// 配列がソート済みのときtrueを返す
	static bool Ordered(Sort *sort);

private:
	// 実行時間の計測のときのデフォルト繰り返し回数
	static const int kDefaultTimes = 10;
};

#endif // UTIL_H_20171116_0952_
