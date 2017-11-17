#ifndef SORT_H_20160508_1144_
#define SORT_H_20160508_1144_

#include "IExecute.h"
#include <random>

// �\�[�g�̂��߂̒��ۃN���X
class Sort : public IExecute {
public:
	// �R���X�g���N�^(��������)
	Sort(size_t size);

	// �R���X�g���N�^(�z��w��)
	Sort(int *arr, size_t size);

	// �f�X�g���N�^
	virtual ~Sort();

	// �\�[�g�̎��s
	virtual bool Execute() = 0;

	// ���Z�b�g
	virtual bool Initialize();

	// �A�N�Z�T(getter�̂�)
	virtual size_t Size() const;
	virtual void Array(int *arr) const;

	// �z��̕\��
	virtual void Show() const;

	// ���s���x�𑪂�ꍇ�A�A�N�Z�T�Ăяo���̃I�[�o�[�w�b�h����̂���
	// �f�[�^�����o�̉�����protected�Ƃ��A�A�N�Z�T�o�R�łȂ����ڃA�N�Z�X����
protected:
	size_t size_;
	int *array_;	

	// ���̃N���X�ł����g��Ȃ����߁Aprivate�ɂ���
private:
	int *org_array_;
};
#endif // #ifndef SORT_H_20160508_1144_
