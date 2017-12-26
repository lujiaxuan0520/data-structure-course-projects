#ifndef __NODE_H__
#define __NODE_H__
#include "LinkList.h"
using namespace std;
template <class ElemType>
class LinkList;

template <class ElemType>
struct Node
{
private:
	ElemType data;
	Node<ElemType> *next;
public:
	Node();
	Node(ElemType e, Node<ElemType> *link = NULL);
	void Show() const
	{
	    cout<<data;
	}
	friend class LinkList<ElemType>;
};
template<class ElemType>
Node<ElemType>::Node()
{
   next = NULL;
}

template<class ElemType>
Node<ElemType>::Node(ElemType e, Node<ElemType> *link)
{
   data = e;
   next = link;
}

#endif

