#include "BucketSort.h"

BucketSort::BucketSort(size_t size):
	Sort(size) {
}

BucketSort::BucketSort(int *arr, size_t size):
	Sort(arr, size) {
}

// �o�P�b�g�\�[�g�̎��s
bool BucketSort::Execute() {
	// �ő�l�̌���
	int max = *array_;
	for (size_t i = 0; i < size_; i++) {
		if (array_[i] > max) max = array_[i];
	}

	// �o�P�c�̗p�ӁB�ő�l��max�Ȃ�A0���܂߂�(max+1)�̗v�f�����z�񂪕K�v�B
	size_t lenBucket = max + 1;
	unsigned int *bucket = new unsigned int[lenBucket];
	for (size_t i = 0; i < lenBucket; i++) {
		bucket[i] = EMPTY;			// ���ׂ�EMPTY�ŏ�����
	}

	// �o�P�c�ɓ�������
	for (size_t i = 0; i < size_; i++) {
		unsigned int value = array_[i];

		// �l���Փ˂��Ă���ꍇ�̓G���[��Ԃ�
		if (value == EMPTY) {
			std::cerr << "�l���d�����Ă��܂��B�������I�����܂��B" << std::endl;
			delete[] bucket;
			return false;
		}

		bucket[value] = value;
	}

	// �o�P�c������o��
	int idx = 0;
	for (size_t i = 0; i < lenBucket; i++) {
		if(bucket[i] != EMPTY) {
			array_[idx++] = bucket[i];
		}
	}
	delete[] bucket;
	return true;
}
