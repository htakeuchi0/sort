#include "BubbleSort.h"

BubbleSort::BubbleSort(size_t size):
	Sort(size) {
}

BubbleSort::BubbleSort(int *arr, size_t size):
	Sort(arr, size) {
}

// �o�u���\�[�g�̎��s
bool BubbleSort::Execute() {
	for (size_t i = size_ - 1; i >= 1; i--) {		  // ���L�Q��
		for (size_t j = 0; j < i; j++) {			  // array_[0..i]�͈̔͂Ō���
			if (array_[j] > array_[j + 1]) {		  // �ד��m���r���āA�E�̂ق�����������΃u�N�u�N����
				int tmp = array_[j];
				array_[j] = array_[j + 1];
				array_[j + 1] = tmp;
			}
		}
	}
	return true;
}
