# SelectionSortクラス

## 概要
選択ソートを実行する機能をもつクラスです。  

## コンストラクタ
| |名前|説明|
|---|----|----|
|+|SelectionSort(size_t size)|配列サイズを指定して、ソートするための乱数配列を生成します。|
|+|SelectionSort(size_t size, ArrayType type)|配列サイズと配列タイプを指定して、ソートするための配列を生成します。|
|+|SelectionSort(int *arr, size_t size)|配列とそのサイズを指定して、ソートするための配列のコピーを生成します。|

### SelectionSort::SelectionSort(size_t size) コンストラクタ
配列サイズを指定して、ソートするための乱数配列を生成します。  

#### 構文
```c++
SelectionSort(size_t size);
```

#### 引数  
##### size
配列のサイズ。  

-----

### SelectionSort::SelectionSort(size_t size, ArrayType type) コンストラクタ
配列サイズと配列タイプを指定して、ソートするための配列を生成します。  

#### 構文
```c++
SelectionSort(size_t size, ArrayType type);
```

#### 引数  
##### size
配列のサイズ。  

##### type
配列のタイプ。  
詳しくは、[ArrayType列挙型](./ArrayType.md)参照。

-----

### SelectionSort::SelectionSort(int *arr, size_t size) コンストラクタ
配列とそのサイズを指定して、ソートするための配列のコピーを生成します。  

#### 構文
```c++
SelectionSort(int *arr, size_t size);
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

### SelectionSort::Execute() メソッド
選択ソートを実行する関数です。  

#### 構文
```c++
bool Execute();
```

#### 引数  
なし。

#### 戻り値  
成功したときだけtrue。
