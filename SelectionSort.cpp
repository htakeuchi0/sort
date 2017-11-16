#include "SelectionSort.h"

SelectionSort::SelectionSort(size_t size):
	Sort(size) {
}

SelectionSort::SelectionSort(int *arr, size_t size):
	Sort(arr, size) {
}

// �P���I��@�̎���
bool SelectionSort::Execute() {
	for (size_t i = 0; i < size_; i++) {		// �ǂ����璲�ׂ邩
		int min = array_[i];					// array[i..length-1]�ł̎b��ŏ��l
		size_t minIdx = i;						// �b��ŏ��l�̓Y����
		
		// array[i..length-1]�ɂ�����ŏ��l�𒲂ׂ�
		for (size_t j = i + 1; j < size_; j++) {	
			if (array_[minIdx = j] < min) min = array_[j];	// �ŏ��l�̓Y�������ۑ�
		}

		// �ŏ��l��array[i]������
		int tmp = array_[i];				
		array_[i] = array_[minIdx];
		array_[minIdx] = tmp;
	}

	return true;
}
