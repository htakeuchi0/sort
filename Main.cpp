#include <iostream>

#include "Main.h"

void SortTest(Sort *sort) {
	// 並び替え
	std::cout << "ソートを開始します：" << std::endl;
	sort->Show();

	if (sort->Execute()) {						// 正しく並び替えられた場合のみ表示
		std::cout << "ソート後：" << std::endl;
		sort->Show();
	}
}

void TimeTest(Sort *sort) {
	auto time = Util::GetTime(sort);
	std::cout << time << "[ms]" << std::endl;
}

int main() {
	const int NUM_SORT = 7;
	const int NUM_SIZE = 100;

	Sort *sort[NUM_SORT];

	std::string sort_name[] =
		{"Bucket", "Radix", "Bubble", "Insert", "Selection", "Heap", "Quick"};

	size_t size_arr[NUM_SIZE];
	for (int i = 0; i < NUM_SIZE; i++) {
		size_arr[i] = 200 * (i + 1);
	}	

	size_t size = size_arr[0];

	BucketSort bucket_sort(size, ArrayType::kDistinct);
	RadixSort radix_sort(size);

	BubbleSort bubble_sort(size);
	InsertSort insert_sort(size);
	SelectionSort selection_sort(size);

	HeapSort heap_sort(size);
	QuickSort quick_sort(size);

	sort[0] = &bucket_sort;
	sort[1] = &radix_sort;
	sort[2] = &bubble_sort;
	sort[3] = &insert_sort;
	sort[4] = &selection_sort;
	sort[5] = &heap_sort;
	sort[6] = &quick_sort;

	for (int i = 0; i < NUM_SORT; i++) {
		std::cout << sort_name[i] << std::flush;
		for (int j = 0; j < NUM_SIZE; j++) {
			if (sort[i]) {
				sort[i]->SetSize(size_arr[j]);
			}
			auto time = Util::GetTime(sort[i]);
			std::cout << ", " << time << std::flush;
		}
		std::cout << std::endl;
	}
}
