#include "RadixSort.h"

RadixSort::RadixSort(size_t size):
	Sort(size) {
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
	const int lg = static_cast<int>(std::log2(size_)/POW + 0.5);			// 16進数で何桁か？log_2(x)/log_2(2^POW) = log_2(x)/POW。切り上げのために+0.5
	
	std::vector<unsigned int> *radixArray = new std::vector<unsigned int>[RADIX];	// RADIX進数の場合、必要なバケツの数はRADIX個

	int tmp = 1;													// 上位桁を抜き出すために利用
	for (int rad = 0; rad <= lg; rad++) {							// 桁数分反復
		radixArray->clear();										// バケツを空に
		for (size_t i = 0; i < size_; i++) {
			radixArray[array_[i] >> tmp & MASK].push_back(array_[i]);	// 上位桁を参照するためにビットシフトしてMASKをかけて取り出す。それをバケツにenqueue(バケツにenqueueって…)
		}

		size_t idx = 0;												// バケツの中身をarray_に戻すためのindex変数
		for (size_t i = 0; i < RADIX; i++) {
			for (size_t j = 0; j < radixArray[i].size(); j++) {		// 各バケツに入っているリストの長さ分
				array_[idx++] = radixArray[i][j];					// 先入れ先出しなので、これはdequeueに相当
			}
		}
		tmp = tmp << (POW - 1);										// 次の反復で上位桁を見るために2^POW倍する
	}
	delete[] radixArray;
	return true;
}
