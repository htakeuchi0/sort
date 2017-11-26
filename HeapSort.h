#ifndef HEAPSORT_H_20160510_2203_
#define HEAPSORT_H_20160510_2203_

#include "Sort.h"

// ヒープソート
class HeapSort : public Sort {
public:
	// コンストラクタ
	// サイズを指定して乱数配列を生成する
	HeapSort(size_t size);

	// コンストラクタ
	// 配列サイズとタイプを指定して配列を生成する
	HeapSort(size_t size, ArrayType type);

	// コンストラクタ
	// 指定された配列をコピーして配列を生成する
	HeapSort(int *arr, size_t size);

	// ヒープソートの実行
	bool Execute();

	// 配列のコピーを返す
	virtual void Array(int *arr) const;

	// 配列のサイズを設定する
	// 与えられた大きさの配列を再生成する
	virtual bool SetSize(size_t size);

	// 配列の表示
	virtual void Show() const;

private:
	// 配列の要素をずらす
	void SlideArray();

	// 空要素を表す
	static const int kEmpty = -1;
};

#endif // #ifndef HEAPSORT_H_20160510_2203_
