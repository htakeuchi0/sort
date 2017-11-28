# 概要
ソートアルゴリズムを学ぶためのプロジェクトです。  
Sortクラスや、そのクラスを継承するQuickSortクラスなどが定義されています。  
例えば、以下のコードで、サイズが10の乱数配列をクイックソートで並び替えたときのソート前・ソート後の配列を表示できます。
```c++
size_t size = 10;            // 配列サイズ
QuickSort quick_sort(size);

std::cout << "ソート前: " << std::flush;
quick_sort.Show();
std::cout << std::endl;

quick_sort.Execute();        // クイックソートを実行

std::cout << "ソート後: " << std::flush;
quick_sort.Show();
std::cout << std::endl;
```
実行時間を計測するユーティリティも用意しています。  
例えば、以下のコードで、サイズが10000の配列に対するバブルソートとクイックソートの実行時間を比較できます。
```c++
size_t size = 10000;        // 配列サイズ
Sort *sort;

BubbleSort bubble_sort(size);
QuickSort quick_sort(size);

std::cout << "バブルソート: " << std::flush;
sort = &bubble_sort;
auto time = Util::GetTime(sort);
std::cout << time << "[ms]" << std::endl;
std::cout << std::endl;

std::cout << "クイックソート: " << std::flush;
sort = &quick_sort;
auto time = Util::GetTime(sort);
std::cout << time << "[ms]" << std::endl;
```

# 詳細
## クラス
クラス図は以下の通りです。  
この図はAstah communityで作成しました。
![sort_class](/image/sort_class.png)

## サンプルプログラムの使い方
Sample.cppがサンプルプログラムです。  
サンプルプログラムは、各アルゴリズムのソート前・ソート後の表示や、実行時間の表示ができます。  
例えば、gnuplotが使える環境ならば、以下のようにすると、配列サイズを変えながらソートを実行したときの実行時間のグラフが表示されます。  
また、figure.epsにグラフが出力されます。
```
$ make
$ ./Sample times 20 > file.csv
$ gnuplot -e "file='file.csv'; outfile='figure.eps'" tools/execution_time.plt
```
作成者の環境では、file.csvは次のようになりました。
```
# Table: Execution Time [ms]
# Size, Bucket, Radix, Bubble, Insert, Selection, Heap, Quick
200, 0, 0, 0, 0, 0, 0, 0
400, 0, 0, 0, 0, 0, 0, 0
600, 0, 0, 0, 0, 0, 0, 0
800, 0, 0, 1, 0, 0, 0, 0
1000, 0, 0, 2, 1, 1, 0, 0
1200, 0, 0, 3, 1, 1, 0, 0
1400, 0, 0, 4, 2, 2, 0, 0
1600, 0, 0, 5, 3, 3, 0, 0
1800, 0, 0, 7, 4, 4, 0, 0
2000, 0, 0, 9, 5, 5, 0, 0
2200, 0, 0, 11, 6, 6, 0, 0
2400, 0, 0, 13, 7, 7, 0, 0
2600, 0, 0, 15, 8, 8, 0, 0
2800, 0, 0, 18, 10, 9, 0, 0
3000, 0, 0, 21, 12, 11, 0, 0
3200, 0, 0, 24, 13, 12, 0, 0
3400, 0, 0, 28, 14, 14, 0, 0
3600, 0, 0, 32, 16, 16, 0, 0
3800, 0, 0, 36, 19, 17, 0, 0
4000, 0, 0, 40, 20, 19, 0, 0
```

また、グラフは次のようになりました。  
配列サイズが大きくなると、バブルソート、選択ソート、挿入ソートの実行時間が増大することがわかります。  
これらソートの計算量のオーダが<i>O(n<sup>2</sup>)</i>であることも観察できます。  

<img src="/image/figure.png" alter="figure" width=75%/>
