#ifndef BUCKETSORT_H_20160508_2007_
#define BUCKETSORT_H_20160508_2007_

#include "Sort.h"
#include <iostream>

// �o�P�b�g�\�[�g
class BucketSort : public Sort {
public:
	// �R���X�g���N�^(��������)
	BucketSort(size_t size);

	// �R���X�g���N�^(�z��w��)
	BucketSort(int *arr, size_t size);
	bool Execute();

private:
	static const unsigned int EMPTY = static_cast<unsigned int>(-1);	// EMPTY�l
};
#endif // #ifndef BUCKETSORT_H_20160508_2007_
