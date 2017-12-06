#ifndef QUICKSORT_H_20160508_2155_
#define QUICKSORT_H_20160508_2155_

#include "Sort.h"

// クイックソート
class QuickSort : public Sort {
public:
	// コンストラクタ
	// サイズを指定して乱数配列を生成する
	QuickSort(size_t size);

	// コンストラクタ
	// 配列サイズとタイプを指定して配列を生成する
	QuickSort(size_t size, ArrayType type);

	// コンストラクタ
	// 指定された配列をコピーして配列を生成する
	QuickSort(int *arr, size_t size);

	// コピーコンストラクタ
	QuickSort(const QuickSort& quick_sort);

	// クイックソートの実行
	bool Execute();

private:
	// 再帰クイックソート
	void QuickRecursive(int start, int end);
};
#endif //#ifndef QUICKSORT_20160508_2155_
