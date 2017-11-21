#ifndef BUCKETSORT_H_20160508_2007_
#define BUCKETSORT_H_20160508_2007_

#include "Sort.h"
#include <iostream>

// バケットソート
class BucketSort : public Sort {
public:
	// コンストラクタ(乱数生成)
	BucketSort(size_t size);
	BucketSort(size_t size, ArrayType type);

	// コンストラクタ(配列指定)
	BucketSort(int *arr, size_t size);
	bool Execute();

private:
	static const unsigned int EMPTY = static_cast<unsigned int>(-1);	// EMPTY値
};
#endif // #ifndef BUCKETSORT_H_20160508_2007_
