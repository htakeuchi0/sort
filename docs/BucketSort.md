# BucketSortクラス

## 概要
バケットソートを実行する機能をもつクラスです。  

## コンストラクタ
| |名前|説明|
|---|----|----|
|+|BucketSort(size_t size)|配列サイズを指定して、ソートするための乱数配列を生成します。|
|+|BucketSort(size_t size, ArrayType type)|配列サイズと配列タイプを指定して、ソートするための配列を生成します。|
|+|BucketSort(int *arr, size_t size)|配列とそのサイズを指定して、ソートするための配列のコピーを生成します。|

### BucketSort::BucketSort(size_t size) コンストラクタ
配列サイズを指定して、ソートするための乱数配列を生成します。  

#### 構文
```c++
BucketSort(size_t size);
```

#### 引数  
##### size
配列のサイズ。  

-----

### BucketSort::BucketSort(size_t size, ArrayType type) コンストラクタ
配列サイズと配列タイプを指定して、ソートするための配列を生成します。  

#### 構文
```c++
BucketSort(size_t size, ArrayType type);
```

#### 引数  
##### size
配列のサイズ。  

##### type
配列のタイプ。  
詳しくは、[ArrayType列挙型](./ArrayType.md)参照。

-----

### BucketSort::BucketSort(int *arr, size_t size) コンストラクタ
配列とそのサイズを指定して、ソートするための配列のコピーを生成します。  

#### 構文
```c++
BucketSort(int *arr, size_t size);
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

### BucketSort::Execute() メソッド
バケットソートを実行する関数です。  
値が重複していた要素が存在する場合、エラーを返し終了します。

#### 構文
```c++
bool Execute();
```

#### 引数  
なし。

#### 戻り値  
成功したときだけtrue。
