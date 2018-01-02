#ifndef TWOSEQSTACK_H
#define TWOSEQSTACK_H
#include "Assistance.h"
template<class ElemType>
class TwoSeqStack
{
protected:
    int top1,top2;										// ջ��ָ��
	int maxSize;									// ջ���������
	ElemType *elems;
public:
    TwoSeqStack(int size = DEFAULT_SIZE)
    {
        maxSize = size;						// ջ���������
        if (elems != NULL) delete []elems;	// �ͷ����д洢�ռ�
        elems = new ElemType[maxSize];		// �����µĴ洢�ռ�
        top1 = -1;	top2=maxSize;
    }
    virtual ~TwoSeqStack()
    {
        delete []elems;
    }
    void Clear()
    {
        top1 = -1;
        top2=maxSize;
    }
    Status Push(const ElemType &e,int N)
    {
        if(top1==top2-1)
        {
            return OVER_FLOW;
        }
        else
        {
            if(N==1)
            {
                top1++;
                elems[top1]=e;
            }
            else
            {
                top2--;
                elems[top2]=e;
            }
            return SUCCESS;
        }
    }
    Status Pop(ElemType &e,int N)
    {
        if(IsEmpty(N))
        {
            return UNDER_FLOW;
        }
        else
        {
            if(N==1)
            {
                top1--;
                e=elems[top1];
            }
            else
            {
                top2++;
                e=elems[top2];
            }
            return SUCCESS;
        }
    }
    bool IsEmpty(int N) const
    {
        if(N==1)
        {
            if(top1==-1) return true;
            else
                return false;
        }
        else
        {
            if(top2==maxSize) return true;
            else
                return false;
        }
    }

};
#endif // TWOSEQSTACK_H
