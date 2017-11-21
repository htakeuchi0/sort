#include "InsertSort.h"
#include <iostream>

InsertSort::InsertSort(size_t size):
	Sort(size) {
}

InsertSort::InsertSort(int *arr, size_t size):
	Sort(arr, size) {
}

// 単純挿入法の実行
bool InsertSort::Execute() {
	for (int i = 1; i < static_cast<int>(size_); i++) {		// 下記参照 
		int j = i;

		while (--j >= 0) {	// ソート済みの部分を後ろから走査
			// array_[j]をソート済み部分array_[0..i-1]の適切な場所に挿入
			if (array_[i] > array_[j]) {			// 見つけた
				break;
			}
		}
		j++;

		int tmp = array_[i];			// 挿入のために一時保存
		for (int k = i; k > j; k--) {
			array_[k] = array_[k - 1];	// ずらす
		}
		array_[j] = tmp;					// 挿入
	}
	return true;
}
