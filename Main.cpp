#include <iostream>

#include "Main.h"

void SortTest(Sort *sort) {
	// ���ёւ�
	std::cout << "�\�[�g���J�n���܂��F" << std::endl;
	sort->Show();

	if (sort->Execute()) {						// ���������ёւ���ꂽ�ꍇ�̂ݕ\��
		std::cout << "\n�\�[�g��F" << std::endl;
		sort->Show();
	}
}

void TimeTest(Sort *sort) {
	auto time = Util::GetTime(sort);
	std::cout << time << "[ms]" << std::endl;
}

int main() {
	size_t size = 10000;
	Sort *sort = new QuickSort(size);

	TimeTest(sort);

	delete sort;
	sort = nullptr;
}
