#include "HeapSort.h"
#include <iostream>

// コンストラクタ
// サイズを指定して乱数配列を生成する
HeapSort::HeapSort(size_t size) :
	Sort(size)
{
	SlideArray();
}

// コンストラクタ
// 配列サイズとタイプを指定して配列を生成する
HeapSort::HeapSort(size_t size, ArrayType type):
	Sort(size, type)
{
	SlideArray();
}

// コンストラクタ
// 指定された配列をコピーして配列を生成する
HeapSort::HeapSort(int *arr, size_t size):
	Sort(arr, size)
{
	SlideArray();
}

// 配列のコピーを返す
void HeapSort::Array(int *arr) const {
	if (arr == nullptr || array_ == nullptr) {
		return;
	}

	for (size_t i = 0; i < size_; i++) {
		arr[i] = array_[i + 1];
	}
}

// 配列のサイズを設定する
// 与えられた大きさの配列を再生成する
bool HeapSort::SetSize(size_t size) {
	bool isSuccess = Sort::SetSize(size);

	// 成功したときだけ配列をずらす
	if(isSuccess) {
		SlideArray();
	}

	return isSuccess;
}

// 配列の表示
void HeapSort::Show() const {
	if (array_ == nullptr) {
		return;
	}

	for (size_t i = 0; i < size_; i++) {
		std::cout << array_[i + 1] << ", ";
	}
	std::cout << std::endl;
}

// ヒープソートの実行
bool HeapSort::Execute() {
	int size = static_cast<int>(size_);

	for (int n = size >> 1; n >= 1; n--) {
		int i = n;
		while (i <= size >> 1) {
			int node = array_[i];
			int index = i << 1;
			int right_index = index | 1;
			int large_child = array_[index];

			if (right_index <= size) {
				int right = array_[right_index];

				if (large_child < right) {
					large_child = right;
					index = right_index;
				}
			}

			if (node >= large_child) {
				break;
			}

			int tmp = array_[i];
			array_[i] = array_[index];
			array_[index] = tmp;

			i = index;
		}
	}
		
	int n = size;
	while (n >= 2){
		// ヒープのルートと最後の要素を交換
		int tmp = array_[1];
		array_[1] = array_[n];
		array_[n] = tmp;

		int i = 1;
		--n;

		while (i <= n >> 1) {
			int node = array_[i];
			int index = i << 1;
			int right_index = index | 1;
			int large_child = array_[index];

			if (right_index <= n) {
				int right = array_[right_index];

				if (large_child < right) {
					large_child = right;
					index = right_index;
				}
			}

			if (node >= large_child) {
				break;
			}

			int tmp = array_[i];
			array_[i] = array_[index];
			array_[index] = tmp;

			i = index;
		}
	}
	return true;
}

// 配列の要素をずらす
void HeapSort::SlideArray() {
	int *arr = new int[size_];
	for (size_t i = 0; i < size_; i++) {
		arr[i] = array_[i];
	}

	delete[] array_;

	array_ = new int[size_ + 1];

	array_[0] = HeapSort::kEmpty;
	for (size_t i = 0; i < size_; i++) {
		array_[i + 1] = arr[i];
	}

	delete[] arr;
}
