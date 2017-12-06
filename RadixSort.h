#ifndef RADIXSORT_H_20160508_2111_
#define RADIXSORT_H_20160508_2111_

#include<vector>
#include<cmath>
#include "Sort.h"

// 基数ソート
class RadixSort : public Sort {
public:
	// コンストラクタ
	// サイズを指定して乱数配列を生成する
	RadixSort(size_t size);

	// コンストラクタ
	// 配列サイズとタイプを指定して配列を生成する
	RadixSort(size_t size, ArrayType type);

	// コンストラクタ
	// 指定された配列をコピーして配列を生成する
	RadixSort(int *arr, size_t size);

	// コピーコンストラクタ
	RadixSort(const RadixSort& radix_sort);
	
	// 基数ソートの実行
	bool Execute();
};
#endif // #ifndef RADIXSORT_H_20160508_2111_
