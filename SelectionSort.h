#ifndef SELECTSORT_H_20160508_2137_
#define SELECTSORT_H_20160508_2137_

#include "Sort.h"

// �P���I��@
class SelectionSort : public Sort {
public:
	// �R���X�g���N�^(��������)
	SelectionSort(size_t size);

	// �R���X�g���N�^(�z��w��)
	SelectionSort(int *arr, size_t size);

	bool Execute();
};

#endif // #ifndef SELECTSORT_H_20160508_2137_
