#ifndef QUICKSORT_H_20160508_2155_
#define QUICKSORT_H_20160508_2155_

#include "Sort.h"

// クイックソート。
class QuickSort : public Sort {
public:
	// コンストラクタ(乱数生成)
	QuickSort(size_t size);

	// コンストラクタ(配列指定)
	QuickSort(int *arr, size_t size);
	bool Execute();

private:
	void QuickRecursiveOn(int *array, int start, int end);	// 再帰あり
};
#endif //#ifndef QUICKSORT_20160508_2155_
