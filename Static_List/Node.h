#ifndef NODE_H
#define NODE_H
#include "StaList.h"
template <class ElemType>
struct Node
{
protected:
	ElemType data;			   	// 数据域
	int next;		    // 指针域

public:
	Node();						// 无参数的构造函数
	Node(ElemType e, int i);	// 已知数数据元素值和指针建立结构
	friend class StaList<ElemType>;
};

template <class ElemType>
Node<ElemType>::Node()
{
    next=-1;
}
template <class ElemType>
Node<ElemType>::Node(ElemType e,int i)
{
    data=e;
    next=i;
}


#endif // NODE_H
