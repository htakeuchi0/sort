#include "SelectionSort.h"

// コンストラクタ
// サイズを指定して乱数配列を生成する
SelectionSort::SelectionSort(size_t size):
	Sort(size) {
}

// コンストラクタ
// 配列サイズとタイプを指定して配列を生成する
SelectionSort::SelectionSort(size_t size, ArrayType type):
	Sort(size, type) {
}

// コンストラクタ
// 指定された配列をコピーして配列を生成する
SelectionSort::SelectionSort(int *arr, size_t size):
	Sort(arr, size) {
}

// 単純選択法の実行
bool SelectionSort::Execute() {
	for (size_t i = 0; i < size_; i++) {		// どこから調べるか
		int min = array_[i];					// array[i..length-1]での暫定最小値
		size_t minIdx = i;						// 暫定最小値の添え字
		
		// array[i..length-1]における最小値を調べる
		for (size_t j = i + 1; j < size_; j++) {	
			if (array_[j] < min) min = array_[minIdx = j];	// 最小値の添え字も保存
		}

		// 最小値とarray[i]を交換
		int tmp = array_[i];				
		array_[i] = array_[minIdx];
		array_[minIdx] = tmp;
	}

	return true;
}
