#ifndef RADIXSORT_H_20160508_2111_
#define RADIXSORT_H_20160508_2111_

#include<vector>
#include<cmath>
#include "Sort.h"

// ��\�[�g�B�\�[�g�̐�����A�����Ȃ�������������
class RadixSort : public Sort {
public:
	// �R���X�g���N�^(��������)
	RadixSort(size_t size);

	// �R���X�g���N�^(�z��w��)
	RadixSort(int *arr, size_t size);
	bool Execute();
};
#endif // #ifndef RADIXSORT_H_20160508_2111_