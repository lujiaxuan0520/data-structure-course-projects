#ifndef TWOSTACK_H
#define TWOSTACK_H
#include "LinkStack.h"
template <class ElemType>
class TwoStack
{
private:
    LinkStack<ElemType> s1,s2;
public:
    Status In(const ElemType &e)
    {
        return s1.Push(e);
    }
    Status Out(ElemType &e)
    {
        ElemType temp;
        if(s1.IsEmpty())
        {
            return UNDER_FLOW;
        }
        else
        {
            while(!s1.IsEmpty())
            {
                s1.Pop(temp);
                s2.Push(temp);
            }
            s2.Pop(e);
            while(!s2.IsEmpty())
            {
                s2.Pop(temp);
                s1.Push(temp);
            }
            return SUCCESS;
        }
    }
    bool IsEmpty() const
    {
        if(s1.IsEmpty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void Show() const
    {
        s1.Traverse(Write<int>);
        cout<<endl;
    }

};

#endif // TWOSTACK_H
