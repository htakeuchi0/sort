# BubbleSortクラス

## 概要
バブルソートを実行する機能をもつクラスです。  
本来であれば、バブルソートが何かということを知る必要はありません。  
学習後は頭から消し去ることをお勧めします [1]。  

### 構文  
```c++
class BubbleSort : public Sort
```

## コンストラクタ
| |名前|説明|
|---|----|----|
|+|BubbleSort(size_t size)|配列サイズを指定して、ソートするための乱数配列を生成します。|
|+|BubbleSort(size_t size, ArrayType type)|配列サイズと配列タイプを指定して、ソートするための配列を生成します。|
|+|BubbleSort(int *arr, size_t size)|配列とそのサイズを指定して、ソートするための配列のコピーを生成します。|

### BubbleSort::BubbleSort(size_t size) コンストラクタ
配列サイズを指定して、ソートするための乱数配列を生成します。  

#### 構文
```c++
BubbleSort(size_t size);
```

#### 引数  
##### size
配列のサイズ。  

-----

### BubbleSort::BubbleSort(size_t size, ArrayType type) コンストラクタ
配列サイズと配列タイプを指定して、ソートするための配列を生成します。  

#### 構文
```c++
BubbleSort(size_t size, ArrayType type);
```

#### 引数  
##### size
配列のサイズ。  

##### type
配列のタイプ。  
詳しくは、[ArrayType列挙型](./ArrayType.md)参照。

-----

### BubbleSort::BubbleSort(int *arr, size_t size) コンストラクタ
配列とそのサイズを指定して、ソートするための配列のコピーを生成します。  

#### 構文
```c++
BubbleSort(int *arr, size_t size);
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


### BubbleSort::Execute() メソッド
バブルソートを実行する関数です。  
以上です。  

#### 構文
```c++
bool Execute();
```

#### 引数  
なし。

#### 戻り値  
成功したときだけtrue。

-----

## 参考文献
[1] W.H.Press, et.al., NUMERICAL RECIPES in C〔日本語版〕, 技術評論社, 東京, 2012.
