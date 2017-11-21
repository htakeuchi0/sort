#include "HeapSort.h"
#include <iostream>

HeapSort::HeapSort(size_t size) :
	Sort(size)
{
	SlideArray();
}

HeapSort::HeapSort(int *arr, size_t size):
	Sort(arr, size)
{
	SlideArray();
}

void HeapSort::Array(int *arr) const {
	if (arr == nullptr || array_ == nullptr) {
		return;
	}

	for (size_t i = 0; i < size_; i++) {
		arr[i] = array_[i + 1];
	}
}

void HeapSort::SlideArray() {
	int *arr = new int[size_];
	for (size_t i = 0; i < size_; i++) {
		arr[i] = array_[i];
	}

	delete[] array_;

	array_ = new int[size_ + 1];

	array_[0] = -1;
	for (size_t i = 0; i < size_; i++) {
		array_[i + 1] = arr[i];
	}

	delete[] arr;
}

void HeapSort::Show() const {
	if (array_ == nullptr) {
		return;
	}

	for (size_t i = 0; i < size_; i++) {
		std::cout << array_[i + 1] << ", ";
	}
	std::cout << std::endl;
}

// ヒープソートの実行。再帰を使えばすっきり書けると思われるが
// その場合は外部記憶領域が必要となり、ヒープソートの利点をつぶしてしまう気がするので、ここでは非再帰で実装。
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
