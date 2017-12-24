#ifndef LINKSTACK_H
#define LINKSTACK_H
#include "Node.h"
#include "Assistance.h"
using namespace std;
template<class ElemType>
class Node;
template <class ElemType>
class LinkStack
{
private:
    Node<ElemType> *top;
public:
    LinkStack()
    {
        top=NULL;
    }
    LinkStack(const LinkStack<ElemType> &s)
    {
        top=NULL;
        *this=s;
    }
    LinkStack<ElemType> &operator=(const LinkStack<ElemType> &s)
    {
        if(this==*s) return;
        top=new Node<ElemType>(s.top->data,NULL);
        Node<ElemType> *p=s.top->next,*q=top;
        while(p!=NULL)
        {
            q->next=new Node<ElemType>(p->data,NULL);
            p=p->next;
            q=q->next;
        }
        return *this;
    }
    virtual ~LinkStack()
    {
        Clear();
    }
    int GetLength() const
    {
        int count=0;
        Node<ElemType> *p;
        for(p=top;p!=NULL;p=p->next)
        {
            count++;
        }
        return count;
    }
    bool IsEmpty() const
    {
        if(GetLength()==0) return true;
        else return false;
    }
    void Clear()
    {
        Node<ElemType> *p;
        while(top!=NULL)
        {
            p=top;
            top=top->next;
            delete p;
        }
    }
    Status Push(const ElemType &e)
    {
        Node<ElemType> *p=new Node<ElemType>(e,top);
        if(p!=NULL)
        {
            top=p;
            return SUCCESS;
        }
        else
        {
            return OVER_FLOW;
        }
    }
    Status Top(ElemType &e) const
    {
        if(!IsEmpty())
        {
            e=top->data;
            return SUCCESS;
        }
        else
        {
            return UNDER_FLOW;
        }
    }
    Status Pop(ElemType &e)
    {
        if(!IsEmpty())
        {
            Node<ElemType> *p=top;
            e=top->data;
            top=top->next;
            delete p;
            return SUCCESS;
        }
        else
        {
            return UNDER_FLOW;
        }
    }

};
#endif // LINKSTACK_H
