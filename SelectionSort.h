#ifndef SELECTSORT_H_20160508_2137_
#define SELECTSORT_H_20160508_2137_

#include "Sort.h"

// 単純選択法
class SelectionSort : public Sort {
public:
	// コンストラクタ(乱数生成)
	SelectionSort(size_t size);

	// コンストラクタ(配列指定)
	SelectionSort(int *arr, size_t size);

	bool Execute();
};

#endif // #ifndef SELECTSORT_H_20160508_2137_
