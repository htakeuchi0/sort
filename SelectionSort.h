#ifndef SELECTSORT_H_20160508_2137_
#define SELECTSORT_H_20160508_2137_

#include "Sort.h"

// 単純選択法
class SelectionSort : public Sort {
public:
	// コンストラクタ
	// サイズを指定して乱数配列を生成する
	SelectionSort(size_t size);

	// コンストラクタ
	// 配列サイズとタイプを指定して配列を生成する
	SelectionSort(size_t size, ArrayType type);

	// コンストラクタ
	// 指定された配列をコピーして配列を生成する
	SelectionSort(int *arr, size_t size);

	// 単純選択法の実行
	bool Execute();
};

#endif // #ifndef SELECTSORT_H_20160508_2137_
