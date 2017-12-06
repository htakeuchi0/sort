#ifndef BUCKETSORT_H_20160508_2007_
#define BUCKETSORT_H_20160508_2007_

#include "Sort.h"
#include <iostream>

// バケットソート
class BucketSort : public Sort {
public:
	// コンストラクタ
	// サイズを指定して乱数配列を生成する
	BucketSort(size_t size);

	// コンストラクタ
	// 配列サイズとタイプを指定して配列を生成する
	BucketSort(size_t size, ArrayType type);

	// コンストラクタ
	// 指定された配列をコピーして配列を生成する
	BucketSort(int *arr, size_t size);

	// コピーコンストラクタ
	BucketSort(const BucketSort& bucket_sort);

	// バケットソートの実行
	bool Execute();

private:
	// 空要素を表す
	static const unsigned int kEmpty = static_cast<unsigned int>(-1);
};
#endif // #ifndef BUCKETSORT_H_20160508_2007_
