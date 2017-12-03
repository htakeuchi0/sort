# InsertSortクラス

## 概要
挿入ソートを実行する機能をもつクラスです。  

## コンストラクタ
| |名前|説明|
|---|----|----|
|+|InsertSort(size_t size)|配列サイズを指定して、ソートするための乱数配列を生成します。|
|+|InsertSort(size_t size, ArrayType type)|配列サイズと配列タイプを指定して、ソートするための配列を生成します。|
|+|InsertSort(int *arr, size_t size)|配列とそのサイズを指定して、ソートするための配列のコピーを生成します。|

### InsertSort::InsertSort(size_t size) コンストラクタ
配列サイズを指定して、ソートするための乱数配列を生成します。  

#### 構文
```c++
InsertSort(size_t size);
```

#### 引数  
##### size
配列のサイズ。  

-----

### InsertSort::InsertSort(size_t size, ArrayType type) コンストラクタ
配列サイズと配列タイプを指定して、ソートするための配列を生成します。  

#### 構文
```c++
InsertSort(size_t size, ArrayType type);
```

#### 引数  
##### size
配列のサイズ。  

##### type
配列のタイプ。  
詳しくは、[ArrayType列挙型](./ArrayType.md)参照。

-----

### InsertSort::InsertSort(int *arr, size_t size) コンストラクタ
配列とそのサイズを指定して、ソートするための配列のコピーを生成します。  

#### 構文
```c++
InsertSort(int *arr, size_t size);
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

### InsertSort::Execute() メソッド
挿入ソートを実行する関数です。  
比較的ソートされている配列をソートする場合、挿入回数が少なくなり、効果的に並び替えられるとされています。  
その効果をより高めるため、ソート済みの部分を後ろから走査して、挿入箇所を探します。  

#### 構文
```c++
bool Execute();
```

#### 引数  
なし。

#### 戻り値  
成功したときだけtrue。
