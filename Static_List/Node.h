#ifndef NODE_H
#define NODE_H
#include "StaList.h"
template <class ElemType>
struct Node
{
protected:
	ElemType data;			   	// ������
	int next;		    // ָ����

public:
	Node();						// �޲����Ĺ��캯��
	Node(ElemType e, int i);	// ��֪������Ԫ��ֵ��ָ�뽨���ṹ
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
