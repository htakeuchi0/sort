#include "QuickSort.h"

// コンストラクタ
// サイズを指定して乱数配列を生成する
QuickSort::QuickSort(size_t size):
	Sort(size) {
}

// コンストラクタ
// 配列サイズとタイプを指定して配列を生成する
QuickSort::QuickSort(size_t size, ArrayType type):
	Sort(size, type) {
}

// コンストラクタ
// 指定された配列をコピーして配列を生成する
QuickSort::QuickSort(int *arr, size_t size):
	Sort(arr, size) {
}

// コピーコンストラクタ
QuickSort::QuickSort(const QuickSort& quick_sort) :
	Sort(quick_sort) {
}

// クイックソートの実行
bool QuickSort::Execute() {
	QuickRecursive(0, static_cast<int>(size_) - 1);
	return true;
}

// 再帰ありクイックソート
void QuickSort::QuickRecursive(int left, int right) {
	if (left >= right) return;		// 要素がなければ終了

	int pivot;						// pivotの用意
	int mid = (left + right) >> 1;	// leftとrightの中間

	// left, mid, rightの中間値をpivotとする
	// 最悪計算量O(n^2)を誘発する状況を回避するための工夫
	if(array_[left] <= array_[mid]) {
		if(array_[mid] <= array_[right]) pivot = array_[mid];
		else {	// start <= mid && end < mid
			if(array_[left] <= array_[right]) pivot = array_[right];
			else pivot = array_[left];	
		}
	} else {	// mid < start 
		if(array_[right] <= array_[mid]) pivot = array_[mid];
		else {	// mid < start && mid < end
			if(array_[left] <= array_[right]) pivot = array_[left];
			else pivot = array_[left];
		}
	}

	// 配列を二つに分割
	int i = left - 1, j = right + 1;	// ++i, --jと書くためにスタートをずらしておく
	while(i < j) {						
		while (array_[++i] < pivot)		// 左側でpivotより小さいなら問題ないのでスルー
			;							// そうでないときストップ

		while (array_[--j] > pivot)		// 右側でpivotより大きいなら問題ないのでスルー
			;							// そうでないときストップ

		if (i >= j) break;				// 出会った・通り過ぎたら分割完了

		// イレギュラー達を入れ替えて、左に小さい値、右に大きい値が集まるようにする。
		int tmp = array_[i];
		array_[i] = array_[j];
		array_[j] = tmp;
	}

	// 再帰処理。(平均)外部記憶領域 O(log n) はこの再帰の所為
	// 通り過ぎ対策で行き過ぎたi, jを引き戻す
	// i == jならばちょうどpivotで出会っているためpivotを除いて二分できる
	QuickRecursive(left, --i);	
	QuickRecursive(++j , right);	
}
