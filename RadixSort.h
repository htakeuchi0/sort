#ifndef RADIXSORT_H_20160508_2111_
#define RADIXSORT_H_20160508_2111_

#include<vector>
#include<cmath>
#include "Sort.h"

// 基数ソート。ソートの性質上、符号なし整数だけ実装
class RadixSort : public Sort {
public:
	// コンストラクタ(乱数生成)
	RadixSort(size_t size);
	RadixSort(size_t size, ArrayType type);

	// コンストラクタ(配列指定)
	RadixSort(int *arr, size_t size);
	bool Execute();
};
#endif // #ifndef RADIXSORT_H_20160508_2111_
