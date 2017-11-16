#ifndef QUICKSORT_H_20160508_2155_
#define QUICKSORT_H_20160508_2155_

#include "Sort.h"

// �N�C�b�N�\�[�g�B
class QuickSort : public Sort {
public:
	// �R���X�g���N�^(��������)
	QuickSort(size_t size);

	// �R���X�g���N�^(�z��w��)
	QuickSort(int *arr, size_t size);
	bool Execute();

private:
	void QuickRecursiveOn(int *array, int start, int end);	// �ċA����
};
#endif //#ifndef QUICKSORT_20160508_2155_
