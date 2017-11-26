#ifndef BUBBLESORT_H_20160508_2137_
#define BUBBLESORT_H_20160508_2137_

#include "Sort.h"

// バブルソート
class BubbleSort : public Sort {
public:
	// コンストラクタ
	// サイズを指定して乱数配列を生成する
	BubbleSort(size_t size);

	// コンストラクタ
	// 配列サイズとタイプを指定して配列を生成する
	BubbleSort(size_t size, ArrayType type);

	// コンストラクタ
	// 指定された配列をコピーして配列を生成する
	BubbleSort(int *arr, size_t size);

	// バブルソートの実行
	bool Execute();
};
#endif // #ifndef BUBBLESORT_H_20160508_2137_
