#include "InsertSort.h"

InsertSort::InsertSort(size_t size):
	Sort(size) {
}

InsertSort::InsertSort(int *arr, size_t size):
	Sort(arr, size) {
}

// �P���}���@�̎��s
bool InsertSort::Execute() {
	for (size_t i = 0; i < size_; i++) {		// ���L�Q�� 
		for (size_t j = i - 1; j >= 0; j--) {	// �\�[�g�ς݂̕�������납�瑖��
			// array_[i]���\�[�g�ςݕ���array_[0..i-1]�̓K�؂ȏꏊ�ɑ}��
			if (array_[i] < array_[j]) {			// ������
				int tmp = array_[i];			// �}���̂��߂Ɉꎞ�ۑ�
				for (size_t k = i; k > j; k--) {
					array_[k] = array_[k - 1];	// ���炷
				}
				array_[j] = tmp;					// �}��
				break;
			}
		}
	}
	return true;
}
