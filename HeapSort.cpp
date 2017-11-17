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

	for (int i = 0; i < size_; i++) {
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
	for (size_t n = size_; n >= 1; n--) {
		size_t t = n >> 1, i = t;

		while (i >= 1) {
			// 子がいない場合
			if (t << 1 > n) {
				t = --i;
				continue;
			}

			// 右の子がいない場合(上のif文に入ったらここまで来られないので、子は必ずいる)
			if (((t << 1) | 1 ) > n) {
				if (array_[t] >= array_[t << 1]) t = --i;	// ヒープになっている
				else {										// (左の)子の方が大きい
					int tmp = array_[t];
					array_[t] = array_[t << 1];
					array_[t << 1] = tmp;

					t = --i;								// 次のステップへ
				}
				continue;
			}

			// 左右に子がいる場合	
			if (array_[t] >= array_[t << 1] && array_[t] >= array_[(t << 1) | 1]) {	// ヒープになっている
				t = --i;
			}
			else if (array_[t << 1] >= array_[(t << 1) | 1]) {	// 左の子の方が大きい
				int tmp = array_[t];
				array_[t] = array_[t << 1];
				array_[t << 1] = tmp;

				t = t << 1;									// 左の子を親として反復を続ける
			}
			else {											// 右の子の方が大きい
				int tmp = array_[t];
				array_[t] = array_[(t << 1) | 1];
				array_[(t << 1) | 1] = tmp;

				t = (t << 1) | 1;							// 右の子を親として反復を続ける
			}
		} // while(i >= i)
		
		// ヒープのルートと最後の要素を交換
		int tmp = array_[1];
		array_[1] = array_[n];
		array_[n] = tmp;
	}
	return true;
}
