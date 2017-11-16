#include "QuickSort.h"

QuickSort::QuickSort(size_t size):
	Sort(size) {
}

QuickSort::QuickSort(int *arr, size_t size):
	Sort(arr, size) {
}

// �N�C�b�N�\�[�g�̎��s�B�e���v���[�g����REC�̒l�ɂ���čċA���肩�Ȃ����I�ׂ�B
bool QuickSort::Execute() {
	QuickRecursiveOn(array_, 0, static_cast<int>(size_) - 1);
	return true;
}

// �ċA����N�C�b�N�\�[�g
void QuickSort::QuickRecursiveOn(int *array, int left, int right) {
	if (left >= right) return;		// �v�f���Ȃ���ΏI��

	int pivot;						// pivot�̗p��
	int mid = (left + right) >> 1;	// left��right�̒���

	// left, mid, right�̒��Ԓl��pivot�Ƃ���
	// �ň��v�Z��O(n^2)��U������󋵂�������邽�߂̍H�v
	if(array[left] <= array[mid]) {
		if(array[mid] <= array[right]) pivot = array[mid];
		else {	// start <= mid && end < mid
			if(array[left] <= array[right]) pivot = array[right];
			else pivot = array[left];	
		}
	} else {	// mid < start 
		if(array[right] <= array[mid]) pivot = array[mid];
		else {	// mid < start && mid < end
			if(array[left] <= array[right]) pivot = array[left];
			else pivot = array[left];
		}
	}

	// �z����ɕ���
	int i = left - 1, j = right + 1;	// ++i, --j�Ə������߂ɃX�^�[�g�����炵�Ă���
	while(i < j) {						// �O�̂��߁B���Ԃ�while(true)�ł�OK
		while (array[++i] < pivot)		// ������pivot��菬�����Ȃ���Ȃ��̂ŃX���[
			;							// �����łȂ��Ƃ��X�g�b�v

		while (array[--j] > pivot)		// �E����pivot���傫���Ȃ���Ȃ��̂ŃX���[
			;							// �����łȂ��Ƃ��X�g�b�v

		if (i >= j) break;				// �o������E�ʂ�߂����番������

		// �C���M�����[�B�����ւ��āA���ɏ������l�A�E�ɑ傫���l���W�܂�悤�ɂ���B
		int tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
	}

	// �ċA�����B(����)�O���L���̈� O(log n) �͂��̍ċA�̏���
	// �ʂ�߂��΍�ōs���߂���i, j�������߂�
	// i == j�Ȃ�΂��傤��pivot�ŏo����Ă��邽��pivot�������ē񕪂ł���
	QuickRecursiveOn(array, left, --i);	
	QuickRecursiveOn(array, ++j , right);	
}
