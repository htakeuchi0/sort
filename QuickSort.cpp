#include "QuickSort.h"

QuickSort::QuickSort(size_t size):
	Sort(size) {
}

QuickSort::QuickSort(int *arr, size_t size):
	Sort(arr, size) {
}

// クイックソートの実行。テンプレート引数RECの値によって再帰ありかなしか選べる。
bool QuickSort::Execute() {
	QuickRecursiveOn(array_, 0, static_cast<int>(size_) - 1);
	return true;
}

// 再帰ありクイックソート
void QuickSort::QuickRecursiveOn(int *array, int left, int right) {
	if (left >= right) return;		// 要素がなければ終了

	int pivot;						// pivotの用意
	int mid = (left + right) >> 1;	// leftとrightの中間

	// left, mid, rightの中間値をpivotとする
	// 最悪計算量O(n^2)を誘発する状況を回避するための工夫
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

	// 配列を二つに分割
	int i = left - 1, j = right + 1;	// ++i, --jと書くためにスタートをずらしておく
	while(i < j) {						// 念のため。たぶんwhile(true)でもOK
		while (array[++i] < pivot)		// 左側でpivotより小さいなら問題ないのでスルー
			;							// そうでないときストップ

		while (array[--j] > pivot)		// 右側でpivotより大きいなら問題ないのでスルー
			;							// そうでないときストップ

		if (i >= j) break;				// 出会った・通り過ぎたら分割完了

		// イレギュラー達を入れ替えて、左に小さい値、右に大きい値が集まるようにする。
		int tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
	}

	// 再帰処理。(平均)外部記憶領域 O(log n) はこの再帰の所為
	// 通り過ぎ対策で行き過ぎたi, jを引き戻す
	// i == jならばちょうどpivotで出会っているためpivotを除いて二分できる
	QuickRecursiveOn(array, left, --i);	
	QuickRecursiveOn(array, ++j , right);	
}
