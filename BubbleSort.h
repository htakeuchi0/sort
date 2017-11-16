#ifndef BUBBLESORT_H_20160508_2137_
#define BUBBLESORT_H_20160508_2137_

#include "Sort.h"

// バブルソート
class BubbleSort : public Sort {
public:
	// コンストラクタ(乱数生成)
	BubbleSort(size_t size);

	// コンストラクタ(配列指定)
	BubbleSort(int *arr, size_t size);
	bool Execute();
};
#endif // #ifndef BUBBLESORT_H_20160508_2137_