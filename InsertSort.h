#ifndef INSERTSORT_H_20160508_2155_
#define INSERTSORT_H_20160508_2155_

#include "Sort.h"

// �P���}���@
class InsertSort : public Sort {
public:
	// �R���X�g���N�^(��������)
	InsertSort(size_t size);

	// �R���X�g���N�^(�z��w��)
	InsertSort(int *arr, size_t size);
	bool Execute();
};

#endif //#ifndef INSERT_H_20160508_2155_