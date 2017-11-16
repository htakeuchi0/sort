#ifndef IEXECUTE_H_20171116_0952_
#define IEXECUTE_H_20171116_0952_

class IExecute {
public:
	virtual bool Reset() = 0;
	virtual bool Execute() = 0;
};

#endif // IEXECUTE_H_20171116_0952_
