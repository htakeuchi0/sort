#ifndef BUBBLESORT_H_20160508_2137_
#define BUBBLESORT_H_20160508_2137_

#include "Sort.h"

// �o�u���\�[�g
class BubbleSort : public Sort {
public:
	// �R���X�g���N�^(��������)
	BubbleSort(size_t size);

	// �R���X�g���N�^(�z��w��)
	BubbleSort(int *arr, size_t size);
	bool Execute();
};
#endif // #ifndef BUBBLESORT_H_20160508_2137_