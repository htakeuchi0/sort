#ifndef INSERTSORT_H_20160508_2155_
#define INSERTSORT_H_20160508_2155_

#include "Sort.h"

// 単純挿入法
class InsertSort : public Sort {
public:
	// コンストラクタ(乱数生成)
	InsertSort(size_t size);

	// コンストラクタ(配列指定)
	InsertSort(int *arr, size_t size);
	bool Execute();
};

#endif //#ifndef INSERT_H_20160508_2155_