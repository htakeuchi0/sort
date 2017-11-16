#ifndef HEAPSORT_H_20160510_2203_
#define HEAPSORT_H_20160510_2203_

#include "Sort.h"

// �q�[�v�\�[�g
class HeapSort : public Sort {
public:
	// �R���X�g���N�^(��������)
	HeapSort(size_t size);

	// �R���X�g���N�^(�z��w��)
	HeapSort(int *arr, size_t size);

	bool Execute();
	virtual void Array(int *arr) const;

	// �z��̕\��
	virtual void Show() const;

private:
	void SlideArray();
};

#endif // #ifndef HEAPSORT_H_20160510_2203_
