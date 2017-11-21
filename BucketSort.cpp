#include "BucketSort.h"

BucketSort::BucketSort(size_t size):
	Sort(size) {
}

BucketSort::BucketSort(size_t size, ArrayType type):
	Sort(size, type) {
}

BucketSort::BucketSort(int *arr, size_t size):
	Sort(arr, size) {
}

// バケットソートの実行
bool BucketSort::Execute() {
	// 最大値の決定
	int max = *array_;
	for (size_t i = 0; i < size_; i++) {
		if (array_[i] > max) max = array_[i];
	}

	// バケツの用意。最大値がmaxなら、0も含めて(max+1)個の要素をもつ配列が必要。
	size_t lenBucket = max + 1;
	unsigned int *bucket = new unsigned int[lenBucket];
	for (size_t i = 0; i < lenBucket; i++) {
		bucket[i] = EMPTY;			// すべてEMPTYで初期化
	}

	// バケツに投げ込む
	for (size_t i = 0; i < size_; i++) {
		unsigned int value = array_[i];

		// 値が衝突している場合はエラーを返す
		if (value == EMPTY) {
			std::cerr << "値が重複しています。処理を終了します。" << std::endl;
			delete[] bucket;
			return false;
		}

		bucket[value] = value;
	}

	// バケツから取り出す
	int idx = 0;
	for (size_t i = 0; i < lenBucket; i++) {
		if(bucket[i] != EMPTY) {
			array_[idx++] = bucket[i];
		}
	}
	delete[] bucket;
	return true;
}
