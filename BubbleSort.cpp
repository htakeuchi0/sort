#include "BubbleSort.h"

BubbleSort::BubbleSort(size_t size):
	Sort(size) {
}

BubbleSort::BubbleSort(int *arr, size_t size):
	Sort(arr, size) {
}

// バブルソートの実行
bool BubbleSort::Execute() {
	for (size_t i = size_ - 1; i >= 1; i--) {		  // 下記参照
		for (size_t j = 0; j < i; j++) {			  // array_[0..i]の範囲で交換
			if (array_[j] > array_[j + 1]) {		  // 隣同士を比較して、右のほうが小さければブクブク交換
				int tmp = array_[j];
				array_[j] = array_[j + 1];
				array_[j + 1] = tmp;
			}
		}
	}
	return true;
}
