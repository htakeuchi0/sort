#include "BubbleSort.h"

// コンストラクタ
// サイズを指定して乱数配列を生成する
BubbleSort::BubbleSort(size_t size):
	Sort(size) {
}

// コンストラクタ
// 配列サイズとタイプを指定して配列を生成する
BubbleSort::BubbleSort(size_t size, ArrayType type):
	Sort(size, type){
}

// コンストラクタ
// 指定された配列をコピーして配列を生成する
BubbleSort::BubbleSort(int *arr, size_t size):
	Sort(arr, size) {
}

// バブルソートの実行
bool BubbleSort::Execute() {
	for (size_t i = size_ - 1; i >= 1; i--) {
		for (size_t j = 0; j < i; j++) {
			// 隣同士を比較して、右のほうが小さければ交換
			if (array_[j] > array_[j + 1]) {  
				int tmp = array_[j];
				array_[j] = array_[j + 1];
				array_[j + 1] = tmp;
			}
		}
	}
	return true;
}
