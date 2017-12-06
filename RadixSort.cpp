#include "RadixSort.h"
#include <iostream>

// コンストラクタ
// サイズを指定して乱数配列を生成する
RadixSort::RadixSort(size_t size):
	Sort(size) {
}

// コンストラクタ
// 配列サイズとタイプを指定して配列を生成する
RadixSort::RadixSort(size_t size, ArrayType type):
	Sort(size, type) {
}

// コンストラクタ
// 指定された配列をコピーして配列を生成する
RadixSort::RadixSort(int *arr, size_t size):
	Sort(arr, size) {
}

// コピーコンストラクタ
RadixSort::RadixSort(const RadixSort& radix_sort):
	Sort(radix_sort) {
}

// 基数ソート。16進数で行う。
// バケットソートと違い、一つのバケツに複数の要素がはいる。
bool RadixSort::Execute() {
	const int kPow = 4;				// 基数は2の何乗か。
	const int kRadix = 1 << kPow;	// 基数
	const int kMask = kRadix - 1;	// 1桁を取り出すためのマスク

	// 配列の最大値を取得
	int max_element = 0;
	for (size_t i = 0; i < size_; i++) {
		max_element = max_element < array_[i] ? array_[i] : max_element;
	}

	// 最大値が16進数で何桁かを表す。log_2(x)/log_2(2^kPow)+1 = log_2(x)/kPow + 1
	const int num_digit = static_cast<int>(std::log2(size_)/kPow) + 1;

	// array_の要素を振り分けるための配列
	unsigned int radix_array[kRadix][size_];

	// radix_array[i][]の要素数
	size_t num_elements[kRadix];

	// 初期化
	for (int i = 0; i < kRadix; i++) {
		radix_array[i][0] = 0;
		num_elements[i] = 0;
	}

	// シフト量
	int shift = 0;

	// 各桁に対して安定ソートを実行
	for (int digit = 1; digit <= num_digit; digit++) {
		// 初期化
		for (int i = 0; i < kRadix; i++) {
			for (size_t j = 0; j < num_elements[i]; j++) {
				radix_array[i][j] = 0;
			}
			num_elements[i] = 0;
		}

		// 上位桁を参照するためにビットシフトしてマスクkMaskをかけて取り出す。
		// radix_arrayの要素に振り分ける
		for (size_t i = 0; i < size_; i++) {
			int index = (array_[i] >> shift) & kMask;
			radix_array[index][num_elements[index]++] = array_[i];
		}

		// radix_arrayの要素をarray_に戻すためのindex変数
		size_t idx = 0;												

		// radix_arrayの要素をarray_に戻す。
		// 安定ソートになるように先頭から取り出して戻す。
		for (size_t i = 0; i < kRadix; i++) {
			for (size_t j = 0; j < num_elements[i]; j++) {
				array_[idx++] = radix_array[i][j];
			}
		}
		shift += kPow;
	}
	return true;
}
