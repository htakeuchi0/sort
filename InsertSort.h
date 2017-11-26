#ifndef INSERTSORT_H_20160508_2155_
#define INSERTSORT_H_20160508_2155_

#include "Sort.h"

// 単純挿入法
class InsertSort : public Sort {
public:
	// コンストラクタ
	// サイズを指定して乱数配列を生成する
	InsertSort(size_t size);

	// コンストラクタ
	// 配列サイズとタイプを指定して配列を生成する
	InsertSort(size_t size, ArrayType type);

	// コンストラクタ
	// 指定された配列をコピーして配列を生成する
	InsertSort(int *arr, size_t size);

	// ソートの実行
	bool Execute();
};

#endif //#ifndef INSERT_H_20160508_2155_
