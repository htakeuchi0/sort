#ifndef IEXECUTE_H_20171116_0952_
#define IEXECUTE_H_20171116_0952_

// 何かを実行する機能をもつインタフェース
class IExecute {
public:
	// 初期化
	virtual bool Initialize() = 0;

	// 実行
	virtual bool Execute() = 0;
};

#endif // IEXECUTE_H_20171116_0952_
