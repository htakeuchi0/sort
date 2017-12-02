# QuickSortクラス

## 概要
ヒープソートを実行する機能をもつクラスです。  
子ノードへのアクセスを簡単にするため、コンストラクタで、配列の要素が[1]〜[n]に保存されるようにします。  
ただし、nは要素数を表します。  
このとき、```array_[i]```の子ノードは、存在すれば```array_[i << 1]```と```array_[(i << 1)| 1]```になります。

## コンストラクタ
| |名前|説明|
|---|----|----|
|+|QuickSort(size_t size)|配列サイズを指定して、ソートするための乱数配列を生成します。|
|+|QuickSort(size_t size, ArrayType type)|配列サイズと配列タイプを指定して、ソートするための配列を生成します。|
|+|QuickSort(int *arr, size_t size)|配列とそのサイズを指定して、ソートするための配列のコピーを生成します。|

### QuickSort::QuickSort(size_t size) コンストラクタ
配列サイズを指定して、ソートするための乱数配列を生成します。  

#### 構文
```c++
QuickSort(size_t size);
```

#### 引数  
##### size
配列のサイズ。  

-----

### QuickSort::QuickSort(size_t size, ArrayType type) コンストラクタ
配列サイズと配列タイプを指定して、ソートするための配列を生成します。  

#### 構文
```c++
QuickSort(size_t size, ArrayType type);
```

#### 引数  
##### size
配列のサイズ。  

##### type
配列のタイプ。  
詳しくは、ArrayType列挙型参照。

-----

### QuickSort::QuickSort(int *arr, size_t size) コンストラクタ
配列とそのサイズを指定して、ソートするための配列のコピーを生成します。  

#### 構文
```c++
QuickSort(int *arr, size_t size);
```

#### 引数  
##### arr
ソートのためにコピーする配列。

##### size
第1引数arrが指す配列のサイズ。  

-----

## メソッド
| |名前|説明|
|---|----|----|
|+|Execute()|ソートを実行します。|
|-|QuickRecursive(int start, int end)|インデックスstartからendまでの配列の要素に対してクイックソートを実行します。|

### QuickSort::Execute() メソッド  
クイックソートを実行する関数です。  

#### 構文
```c++
bool Execute();
```

#### 引数  
なし。

#### 戻り値  
成功したときだけtrue。

--------------------------------

### QuickSort::QuickRecursive(int start, int end) メソッド
インデックスstartからendまでの配列の要素に対してクイックソートを実行します。  
このメソッドを再帰的に呼び出すことで、配列全体のソートを実行します。

#### 構文
```c++
void QuickRecursive(int start, int end);
```

#### 引数  
##### start
ソート対象の配列の最小のインデックス。

##### end
ソート対象の配列の最大のインデックス。

#### 戻り値  
なし。
