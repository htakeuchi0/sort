#include "RadixSort.h"

RadixSort::RadixSort(size_t size):
	Sort(size) {
}

RadixSort::RadixSort(int *arr, size_t size):
	Sort(arr, size) {
}

// ��\�[�g�̎����B10�i�����2�i���x�[�X�̂ق����������B�����ł�16�i���Ŏ����B
// �P���ȃo�P�b�g�\�[�g�ƈႢ�A��̃o�P�c�ɕ����̗v�f���͂��邱�ƂɂȂ�B
// �{���̓L���[�ŊǗ����������ʓ|�Ȃ��STL(std::vector)�����p�B
bool RadixSort::Execute() {
	const int POW = 4;												// 16��2��POW=4��
	const int RADIX = 1 << POW;										// 2^POW = 2^4 = 16�̂���
	const int MASK = RADIX - 1;										// ���܂�v�Z�̂��߂ɗ��p�BRADIX��16�Ȃ�MASK=15=(1111)_2�B
	const int lg = static_cast<int>(std::log2(size_)/POW + 0.5);			// 16�i���ŉ������Hlog_2(x)/log_2(2^POW) = log_2(x)/POW�B�؂�グ�̂��߂�+0.5
	
	std::vector<unsigned int> *radixArray = new std::vector<unsigned int>[RADIX];	// RADIX�i���̏ꍇ�A�K�v�ȃo�P�c�̐���RADIX��

	int tmp = 1;													// ��ʌ��𔲂��o�����߂ɗ��p
	for (int rad = 0; rad <= lg; rad++) {							// ����������
		radixArray->clear();										// �o�P�c�����
		for (size_t i = 0; i < size_; i++) {
			radixArray[array_[i] >> tmp & MASK].push_back(array_[i]);	// ��ʌ����Q�Ƃ��邽�߂Ƀr�b�g�V�t�g����MASK�������Ď��o���B������o�P�c��enqueue(�o�P�c��enqueue���āc)
		}

		size_t idx = 0;												// �o�P�c�̒��g��array_�ɖ߂����߂�index�ϐ�
		for (size_t i = 0; i < RADIX; i++) {
			for (size_t j = 0; j < radixArray[i].size(); j++) {		// �e�o�P�c�ɓ����Ă��郊�X�g�̒�����
				array_[idx++] = radixArray[i][j];					// ������o���Ȃ̂ŁA�����dequeue�ɑ���
			}
		}
		tmp = tmp << (POW - 1);										// ���̔����ŏ�ʌ������邽�߂�2^POW�{����
	}
	delete[] radixArray;
	return true;
}
