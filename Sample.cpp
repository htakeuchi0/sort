#include <iostream>
#include <cstring>

#include "Sample.h"

// ソートのテスト
// 実行前と後を表示
void SortTest(Sort *sort) {
	// 並び替え
	std::cout << "ソート前：" << std::endl;
	sort->Show();
	std::cout << std::endl;

	if (sort->Execute()) {
		std::cout << "ソート後：" << std::endl;
		sort->Show();
	}
	else {
		std::cout << "ソートに失敗しました" << std::endl;
	}
}

// ソートの実行時間の計測
// CSV形式で標準出力する
void TimeTest(int num_size = 100) {
	const int kNumSort = 7;		// ソートの種類
	const int kNumSize = num_size;	// 実行する配列サイズの種類

	// ソートクラスのインスタンスのポインタ配列
	Sort *sort[kNumSort];

	// ソート名称
	std::string sort_name[] =
		{"Bucket", "Radix", "Bubble", "Insert", "Selection", "Heap", "Quick"};

	// 配列サイズの定義
	size_t size_arr[kNumSize];
	for (int i = 0; i < kNumSize; i++) {
		size_arr[i] = 200 * (i + 1);
	}	

	// サイズ
	size_t size = size_arr[0];

	// ソート
	BucketSort bucket_sort(size, ArrayType::kDistinct);
	RadixSort radix_sort(size);
	BubbleSort bubble_sort(size);
	InsertSort insert_sort(size);
	SelectionSort selection_sort(size);
	HeapSort heap_sort(size);
	QuickSort quick_sort(size);

	// 配列へ各インスタンスのアドレスを登録
	sort[0] = &bucket_sort;
	sort[1] = &radix_sort;
	sort[2] = &bubble_sort;
	sort[3] = &insert_sort;
	sort[4] = &selection_sort;
	sort[5] = &heap_sort;
	sort[6] = &quick_sort;

	// タイトル
	std::cout << "# Table: Execution Time [ms]" << std::endl;
	std::cout << "# Size" << std::flush;
	for (int i = 0; i < kNumSort; i++) {
		std::cout << ", " << sort_name[i] << std::flush;
	}
	std::cout << std::endl;

	// 出力用配列
	long long output_array[kNumSize][kNumSort + 1];
	for (int i = 0; i < kNumSize; i++) {
		output_array[i][0] = size_arr[i];
	}

	// ソートを実行して配列に格納
	for (int i = 0; i < kNumSort; i++) {
		// サイズを指定して時間を計測
		for (int j = 0; j < kNumSize; j++) {
			if (sort[i] != nullptr) {
				sort[i]->SetSize(size_arr[j]);
			}
			auto time = Util::GetTime(sort[i]);
			output_array[j][i + 1] = time;
		}
	}

	for (int i = 0; i < kNumSize; i++) {
		std::cout << output_array[i][0] << std::flush;
		for (int j = 1; j < kNumSort + 1; j++) {
			std::cout  << ", " << output_array[i][j] << std::flush;	
		}
		std::cout << std::endl;
	}
}

// 実験用メインメソッド
int main(int argc, char **argv) {
	// デフォルト
	const int kNumSizeType = 20;
	const char *kType = "quick";
	const int kArraySize = 10;

	// ヘルプ用文字列
	std::string help = "使い方:\n"
	"  Sample times [NUM]\n\n"
	"説明:\n"
	"  時間計測モード。\n\n" 
	"引数:\n"
	"  NUM\tNUMは計測する配列のサンプル数を指定する。\n"
	"\tサイズが200,400,...,200*NUMの配列に対するソートの実行時間を計測する。\n"
	"\t省略すると" + std::to_string(kNumSizeType) + "が指定される。\n\n"
	"使い方:\n"
	"  Sample show [TYPE [NUM]]\n\n"
	"説明:\n"
	"  ソート表示モード。\n\n" 
	"引数：\n"
	"  TYPE\tソートアルゴリズムの種類を指定する。省略した場合は" + kType + "になる。\n"
	"\tTYPE::=bubble|bucket|heap|insert|quick|radix|selection\n"
	"  NUM\tNソートする配列のサイズを指定する。省略した場合は" + std::to_string(kArraySize) + "になる。\n";
	
	// 引数がある場合
	if (argc > 1) {
		// 時間計測
		if (std::strcmp(argv[1], "times") == 0) {
			// 時間計測のサイズの種類
			int num_size;

			// 引数がある場合サイズの種類を設定
			if (argc > 2) {
				num_size = std::atoi(argv[2]);	
			}
			else {
				num_size = kNumSizeType;
			}

			// 時間計測
			TimeTest(num_size);
		}
		// ソート表示
		else if (std::strcmp(argv[1], "show") == 0) {
			// 配列サイズ
			int size;
			if (argc > 3) {
				size = std::atoi(argv[3]);	
			}
			else {
				size = kArraySize;
			}

			// ソートの種類
			Sort *sort;
			const char *type;

			if (argc > 2){
				type = argv[2];
			}
			else {
				type = kType;
			}

			if (std::strcmp(type, "bubble") == 0) {
				sort = new BubbleSort(size);
			}
			else if (std::strcmp(type, "bucket") == 0) {
				sort = new BucketSort(size, ArrayType::kDistinct);
			}
			else if (std::strcmp(type, "heap") == 0) {
				sort = new HeapSort(size);
			}
			else if (std::strcmp(type, "insert") == 0) {
				sort = new HeapSort(size);
			}
			else if (std::strcmp(type, "quick") == 0) { 
				sort = new QuickSort(size);
			}
			else if (std::strcmp(type, "radix") == 0) {
				sort = new RadixSort(size);
			}
			else if (std::strcmp(type, "selection") == 0) {
				sort = new SelectionSort(size);
			}
			else {
				type = kType;
				sort = new  QuickSort(size);
			}
			// ソートの実行
			std::cout << "アルゴリズム＝\"" << type << "\"" << std::endl;
			std::cout << std::endl;
			SortTest(sort);
		
			// メモリの解放
			delete sort;
			sort = nullptr;
		}
		// 引数が不正の場合はhelpを表示
		else {
			std::cout << help << std::endl;
		}
	}
	// 引数がない場合はhelpを表示
	else {
		std::cout << help << std::endl;
	}
}
