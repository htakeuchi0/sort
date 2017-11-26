#include "InsertSort.h"
#include <iostream>

// コンストラクタ
// サイズを指定して乱数配列を生成する
InsertSort::InsertSort(size_t size):
	Sort(size) {
}

// コンストラクタ
// 配列サイズとタイプを指定して配列を生成する
InsertSort::InsertSort(size_t size, ArrayType type):
	Sort(size, type) {
}

// コンストラクタ
// 指定された配列をコピーして配列を生成する
InsertSort::InsertSort(int *arr, size_t size):
	Sort(arr, size) {
}

// 単純挿入法の実行
bool InsertSort::Execute() {
	for (int i = 1; i < static_cast<int>(size_); i++) {
		int j = i;

		// ソート済みの部分を後ろから走査
		while (--j >= 0) {
			// array_[j]をソート済み部分array_[0..i-1]の適切な場所に挿入
			if (array_[i] > array_[j]) {
				break;
			}
		}
		j++;

		// 配列の要素をずらして挿入
		int tmp = array_[i];
		for (int k = i; k > j; k--) {
			array_[k] = array_[k - 1];
		}
		array_[j] = tmp;
	}
	return true;
}
