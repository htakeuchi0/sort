#ifndef SORT_H_20160508_1144_
#define SORT_H_20160508_1144_

#include "IExecute.h"
#include <random>

// 配列の種類
enum ArrayType {
	kRandom,		// 乱数配列
	kDistinct,		// 乱数配列(要素がすべて異なる)
	kOrdered,		// ソート済み
	kConstant,		// 定数配列(サイズ変更を受け付けない)
};

// ソートのための抽象クラス
class Sort : public IExecute {
public:
	// コンストラクタ
	// サイズを指定して乱数配列を生成する
	Sort(size_t size);

	// コンストラクタ
	// 配列サイズとタイプを指定して配列を生成する
	Sort(size_t size, ArrayType type);

	// コンストラクタ
	// 指定された配列をコピーして配列を生成する
	Sort(int *arr, size_t size);

	// コピーコンストラクタ
	Sort(const Sort& sort);

	// デストラクタ
	virtual ~Sort();

	// ソートの実行
	virtual bool Execute() = 0;

	// 初期化する
	virtual bool Initialize();

	// 配列のサイズを返す
	virtual size_t Size() const;

	// 配列のコピーを返す
	virtual void Array(int *arr) const;

	// 配列のサイズを設定する
	// 与えられた大きさの配列を再生成する
	virtual bool SetSize(size_t size);

	// 配列のタイプを取得する
	virtual ArrayType Type() const;

	// 配列の表示
	virtual void Show() const;

// 実行速度を測るときの、アクセサ呼び出しにおけるオーバーヘッド回避のため
// データメンバの可視性をprotectedとし、アクセサ経由でなく直接アクセスする
protected:
	// 配列のサイズ
	size_t size_;

	// 配列
	int *array_;	

	// もとの配列
	int *org_array_;
	
	// 配列のタイプ
	ArrayType type_;

private :
	// 一様乱数配列を生成する
	void GenerateRandomArray();

	// すべての要素が異なる乱数配列を生成する
	void GenerateDistinctArray();

	// すでにソートされている配列を生成する
	void GenerateOrderedArray();
};
#endif // #ifndef SORT_H_20160508_1144_
