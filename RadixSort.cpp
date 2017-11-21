#include "RadixSort.h"
#include <iostream>

RadixSort::RadixSort(size_t size):
	Sort(size) {
}

RadixSort::RadixSort(size_t size, ArrayType type):
	Sort(size, type) {
}

RadixSort::RadixSort(int *arr, size_t size):
	Sort(arr, size) {
}

// 基数ソートの実装。10進数より2進数ベースのほうが嬉しい。ここでは16進数で実装。
// 単純なバケットソートと違い、一つのバケツに複数の要素がはいることになる。
// 本来はキューで管理したいが面倒なんでSTL(std::vector)を活用。
bool RadixSort::Execute() {
	const int POW = 4;												// 16は2のPOW=4乗
	const int RADIX = 1 << POW;										// 2^POW = 2^4 = 16のこと
	const int MASK = RADIX - 1;										// あまり計算のために利用。RADIXが16ならMASK=15=(1111)_2。
	const int lg = static_cast<int>(std::log2(size_)/POW) + 1;			// 16進数で何桁か？log_2(x)/log_2(2^POW)+1 = log_2(x)/POW + 1
	
	unsigned int radixArray[RADIX][size_];	// RADIX進数の場合、必要なバケツの数はRADIX個
	int numElements[RADIX];
	for (int i = 0; i < RADIX; i++) {
		radixArray[i][0] = 0;
		numElements[i] = 0;
	}

	int tmp = 0;													// 上位桁を抜き出すために利用
	for (int rad = 1; rad <= lg; rad++) {							// 桁数分反復
		for (int i = 0; i < RADIX; i++) {
			for (int j = 0; j < numElements[i]; j++) {
				radixArray[i][j] = 0;
			}
			numElements[i] = 0;
		}

		for (size_t i = 0; i < size_; i++) {
			int index = (array_[i] >> tmp) & MASK;
			radixArray[index][numElements[index]++] = array_[i];	// 上位桁を参照するためにビットシフトしてMASKをかけて取り出す。それをバケツにenqueue(バケツにenqueueって…)
		}

		size_t idx = 0;												// バケツの中身をarray_に戻すためのindex変数
		for (size_t i = 0; i < RADIX; i++) {
			for (int j = 0; j < numElements[i]; j++) {		// 各バケツに入っているリストの長さ分
				array_[idx++] = radixArray[i][j];					// 先入れ先出しなので、これはdequeueに相当
			}
		}
		tmp += POW;										// 次の反復で上位桁を見るために2^POW倍する
	}
	return true;
}
