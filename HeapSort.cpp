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

// �q�[�v�\�[�g�̎��s�B�ċA���g���΂������菑����Ǝv���邪
// ���̏ꍇ�͊O���L���̈悪�K�v�ƂȂ�A�q�[�v�\�[�g�̗��_���Ԃ��Ă��܂��C������̂ŁA�����ł͔�ċA�Ŏ����B
bool HeapSort::Execute() {
	for (size_t n = size_; n >= 1; n--) {
		size_t t = n >> 1, i = t;

		while (i >= 1) {
			// �q�����Ȃ��ꍇ
			if (t << 1 > n) {
				t = --i;
				continue;
			}

			// �E�̎q�����Ȃ��ꍇ(���if���ɓ������炱���܂ŗ����Ȃ��̂ŁA�q�͕K������)
			if (((t << 1) | 1 ) > n) {
				if (array_[t] >= array_[t << 1]) t = --i;	// �q�[�v�ɂȂ��Ă���
				else {										// (����)�q�̕����傫��
					int tmp = array_[t];
					array_[t] = array_[t << 1];
					array_[t << 1] = tmp;

					t = --i;								// ���̃X�e�b�v��
				}
				continue;
			}

			// ���E�Ɏq������ꍇ	
			if (array_[t] >= array_[t << 1] && array_[t] >= array_[(t << 1) | 1]) {	// �q�[�v�ɂȂ��Ă���
				t = --i;
			}
			else if (array_[t << 1] >= array_[(t << 1) | 1]) {	// ���̎q�̕����傫��
				int tmp = array_[t];
				array_[t] = array_[t << 1];
				array_[t << 1] = tmp;

				t = t << 1;									// ���̎q��e�Ƃ��Ĕ����𑱂���
			}
			else {											// �E�̎q�̕����傫��
				int tmp = array_[t];
				array_[t] = array_[(t << 1) | 1];
				array_[(t << 1) | 1] = tmp;

				t = (t << 1) | 1;							// �E�̎q��e�Ƃ��Ĕ����𑱂���
			}
		} // while(i >= i)
		
		// �q�[�v�̃��[�g�ƍŌ�̗v�f������
		int tmp = array_[1];
		array_[1] = array_[n];
		array_[n] = tmp;
	}
	return true;
}
