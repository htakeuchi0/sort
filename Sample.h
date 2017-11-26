#ifndef SOURCE_H_20171116_2348_
#define SOURCE_H_20171116_2348_

#include "Sort.h"
#include "BubbleSort.h"
#include "BucketSort.h"
#include "InsertSort.h"
#include "QuickSort.h"
#include "RadixSort.h"
#include "SelectionSort.h"
#include "HeapSort.h"
#include "Util.h"

// ソートのテスト
// 実行前と後を表示
void SortTest(Sort *sort);

// ソートの実行時間の計測
// CSV形式で標準出力する
void TimeTest(int num_size);
#endif // SOURCE_H_20171116_2348_
