#ifndef STALIST_H
#define STALIST_H
#include "Node.h"
#include<iostream>
using namespace std;
template <class ElemType> class Node;

template <class ElemType>
class StaList
{
protected:
    int maxLength;//允许的最大元素个数（包括空闲结点）
    int head;
    int avail;
    Node<ElemType> *sll;
public:
    StaList(const int &size=0):head(-1),avail(0),maxLength(size),sll(NULL)
    {
        if(size!=0) sll=new Node<ElemType> [size+1];
        if(sll==NULL) return;
        else
        {
            int i;
            head=0;
            for(i=0;i<size;i++)
            {
                sll[i].next=i+1;
            }
            sll[i].next=-1;
            avail=sll[head].next;
            sll[head].next=-1;
        }
    }
    StaList(ElemType *v,const int &n,const int &size):head(-1),avail(0),maxLength(size),sll(NULL)//用数组来构造静态链表
    {
        if(n>size) return;
        if(v==NULL) return;
        if(size!=0) sll=new Node<ElemType> [size+1];
        if(sll==NULL) return;
        else
        {
            int i;
            head=0;
            for(i=0;i<size;i++)
            {
                sll[i].next=i+1;
            }
            sll[i].next=-1;
            avail=sll[head].next;
            sll[head].next=-1;
            for(int j=n-1;j>=0;j--)
            {
                InsertElemBefore(v[j]);
            }
        }
    }
    virtual ~StaList()
    {
        if(sll!=NULL) delete [] sll;
        head=-1;avail=0;maxLength=0;
    }
    int GetLength() const//返回链表的实际长度
    {
        if(sll==NULL) return 0;
        int _count=0;
        int i=head;
        while(sll[i].next!=-1)
        {
            _count++;
            i=sll[i].next;
        }
        return _count;
    }
    int GetMaxLength() const//返回链表允许的最大长度
    {
        return maxLength;
    }
    int GetRemainedLength() const//返回还剩下多少可用空间
    {
        return GetMaxLength()-GetLength();
    }
    bool IsEmpty() const//判断链表是否为空
    {
        return GetLength()==0;
    }
    void InsertElemBefore(const ElemType &e)//在链表首部插入元素
    {
        if(avail!=-1)
        {
            int i;
            i=avail;
            sll[i].data=e;
            avail=sll[i].next;
            sll[i].next=sll[head].next;
            sll[head].next=i;
        }
    }
    int GetLastElem(const int &i) const//返回物理内存上下标为i的元素的前一个元素的物理下标
    {
        if(i==head) return -1;
        int p=head;
        while(sll[p].next!=-1)
        {
            if(sll[p].next==i) return p;
            p=sll[p].next;
        }
        return -1;
    }
    int TransformIndex(const int &a) const//将逻辑上的第a个元素转化为实际物理内存上的数组下标
    {
        if(a>GetLength()) return -1;
        int i=head;
        int _count=0;
        while(_count<a)
        {
            i=sll[i].next;
            _count++;
        }
        return i;
    }
    void DeleteElem(const int &j)//删除物理上下标为j的结点
    {
        int p=GetLastElem(j);//获取j的前一个元素下标
        sll[p].next=sll[j].next;
        sll[j].next=avail;
        avail=j;
    }
    void DeleteElem2(const int &i)//删除逻辑上的第i个结点
    {
        int j=TransformIndex(i);//令j为i对应的物理内存下标
        int p=GetLastElem(j);//获取j的前一个元素下标
        sll[p].next=sll[j].next;
        sll[j].next=avail;
        avail=j;
    }
    void Clear()//清除数据，不清除头结点
    {
        if(sll[head].next!=-1)
        {
            for(int i=0;i<GetLength();i++)
            {
                DeleteElem(i);
            }
        }
    }
    void Show() const//输出链表
    {
        if(sll!=NULL)
        {
            int i=head;
            while(sll[i].next!=-1)
            {
                i=sll[i].next;
                cout<<sll[i].data<<" ";
            }
        }
    }
};
#endif // STALIST_H
