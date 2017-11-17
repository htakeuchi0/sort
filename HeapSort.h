#ifndef HEAPSORT_H_20160510_2203_
#define HEAPSORT_H_20160510_2203_

#include "Sort.h"

// ヒープソート
class HeapSort : public Sort {
public:
	// コンストラクタ(乱数生成)
	HeapSort(size_t size);

	// コンストラクタ(配列指定)
	HeapSort(int *arr, size_t size);

	bool Execute();
	virtual void Array(int *arr) const;

	// 配列の表示
	virtual void Show() const;

private:
	void SlideArray();
};

#endif // #ifndef HEAPSORT_H_20160510_2203_
