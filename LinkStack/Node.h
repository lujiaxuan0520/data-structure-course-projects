#ifndef NODE_H
#define NODE_H
#include "LinkStack.h"

template<class ElemType>
class Node
{
private:
    ElemType data;
    Node<ElemType> *next;
public:
    Node(const ElemType &d=0,Node<ElemType> *p=NULL)
    {
        data=d;
        next=p;
    }
    friend class LinkStack<ElemType>;
};

#endif // NODE_H
