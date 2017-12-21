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
    int maxLength;//��������Ԫ�ظ������������н�㣩
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
    StaList(ElemType *v,const int &n,const int &size):head(-1),avail(0),maxLength(size),sll(NULL)//�����������쾲̬����
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
    int GetLength() const//���������ʵ�ʳ���
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
    int GetMaxLength() const//���������������󳤶�
    {
        return maxLength;
    }
    int GetRemainedLength() const//���ػ�ʣ�¶��ٿ��ÿռ�
    {
        return GetMaxLength()-GetLength();
    }
    bool IsEmpty() const//�ж������Ƿ�Ϊ��
    {
        return GetLength()==0;
    }
    void InsertElemBefore(const ElemType &e)//�������ײ�����Ԫ��
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
    int GetLastElem(const int &i) const//���������ڴ����±�Ϊi��Ԫ�ص�ǰһ��Ԫ�ص������±�
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
    int TransformIndex(const int &a) const//���߼��ϵĵ�a��Ԫ��ת��Ϊʵ�������ڴ��ϵ������±�
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
    void DeleteElem(const int &j)//ɾ���������±�Ϊj�Ľ��
    {
        int p=GetLastElem(j);//��ȡj��ǰһ��Ԫ���±�
        sll[p].next=sll[j].next;
        sll[j].next=avail;
        avail=j;
    }
    void DeleteElem2(const int &i)//ɾ���߼��ϵĵ�i�����
    {
        int j=TransformIndex(i);//��jΪi��Ӧ�������ڴ��±�
        int p=GetLastElem(j);//��ȡj��ǰһ��Ԫ���±�
        sll[p].next=sll[j].next;
        sll[j].next=avail;
        avail=j;
    }
    void Clear()//������ݣ������ͷ���
    {
        if(sll[head].next!=-1)
        {
            for(int i=0;i<GetLength();i++)
            {
                DeleteElem(i);
            }
        }
    }
    void Show() const//�������
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
