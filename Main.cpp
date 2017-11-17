#include <iostream>

#include "Main.h"

void SortTest(Sort *sort) {
	// 並び替え
	std::cout << "ソートを開始します：" << std::endl;
	sort->Show();

	if (sort->Execute()) {						// 正しく並び替えられた場合のみ表示
		std::cout << "\nソート後：" << std::endl;
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
