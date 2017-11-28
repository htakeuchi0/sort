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
