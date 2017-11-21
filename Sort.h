#ifndef SORT_H_20160508_1144_
#define SORT_H_20160508_1144_

#include "IExecute.h"
#include <random>

enum ArrayType {
	kNormal,
	kDistinct,
	kOrdered,
	kNone,
};

// ソートのための抽象クラス
class Sort : public IExecute {
public:
	// コンストラクタ(乱数生成)
	Sort(size_t size);

	// コンストラクタ(乱数生成)
	Sort(size_t size, ArrayType type);

	// コンストラクタ(配列指定)
	Sort(int *arr, size_t size);

	// デストラクタ
	virtual ~Sort();

	// ソートの実行
	virtual bool Execute() = 0;

	// リセット
	virtual bool Initialize();

	// アクセサ(getterのみ)
	virtual size_t Size() const;
	void SetSize(size_t size);
	virtual void Array(int *arr) const;

	// 配列の表示
	virtual void Show() const;

	// 実行速度を測る場合、アクセサ呼び出しのオーバーヘッド回避のため
	// データメンバの可視性をprotectedとし、アクセサ経由でなく直接アクセスする
protected:
	size_t size_;
	int *array_;	
	int *org_array_;
	ArrayType type_;

private :
	void OrdinaryConstructor();
	void DistinctConstructor();
	void OrderedConstructor();
};
#endif // #ifndef SORT_H_20160508_1144_
