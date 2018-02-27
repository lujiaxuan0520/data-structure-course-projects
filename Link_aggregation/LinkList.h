#ifndef __LK_LIST_H__
#define __LK_LIST_H__

#include "Assistance.h"				// ���������
#include "Node.h"					// �����

// ��������
template <class ElemType>
class LinkList
{
protected:
//  ����������ݳ�Ա
	Node<ElemType> *head;				// ͷ���ָ��
	int length;							// ��������

public:
//  ������ĺ�����Ա
	LinkList();							// �޲����Ĺ��캯��
	virtual ~LinkList();				// ��������
	void Clear();						// �����������
	int LocateElem(const ElemType &e) const;	         // Ԫ�ض�λ
	void DeleteElem(int position, ElemType &e);		 // ɾ��Ԫ��
	Status InsertElem(const ElemType &e);	             // �ڱ�β����Ԫ��
	Node<ElemType>* GetHead() const;
	void Show() const;
};


// ���������ʵ�ֲ���


template <class ElemType>
LinkList<ElemType>::LinkList()
// �������������һ��������
{
	head = new Node<ElemType>;		// ����ͷ���
	assert(head);                   // ����ͷ���ʧ�ܣ���ֹ��������
	length = 0;						// ��ʼ����������Ϊ0
}

template <class ElemType>
LinkList<ElemType>::~LinkList()
// ������������ٵ�����
{
	Clear();			// ��յ�����
	delete head;		// �ͷ�ͷ�����ָ�ռ�
}

template <class ElemType>
void LinkList<ElemType>::Clear()
// �����������յ�����,ɾ��������������Ԫ�ؽ��
{
    Node<ElemType> *p = head->next;
	while (p != NULL) {
		head->next = p->next;
        delete p;
		p = head->next;
	}
	length = 0;
}

template <class ElemType>
int LinkList<ElemType>::LocateElem(const ElemType &e) const
// Ԫ�ض�λ
{
    Node<ElemType> *p = head->next;
    int count = 1;
	while (p != NULL && p->data != e) {
	    count++;
		p = p->next;
	}
    return  (p != NULL) ? count : 0;
}

template <class ElemType>
void LinkList<ElemType>::DeleteElem(int i, ElemType &e)
// ���������ɾ��������ĵ�i��λ�õ�Ԫ��, ����e������ֵ,
//	i��ȡֵ��ΧΪ1��i��length,
//	i�Ϸ�ʱ��������SUCCESS,����������RANGE_ERROR
{
	if (i < 1 || i > length)
		return ;   // i��Χ��
 	else	{
		Node<ElemType> *p = head, *q;
		int count;
		for (count = 1; count < i; count++)
		  p = p->next;	      // pָ���i-1�����
		q = p->next;	      // qָ���i�����
		p->next = q->next;	  // ɾ�����
		e = q->data;		  // ��e���ر�ɾ���Ԫ��ֵ
		length--;			  // ɾ���ɹ���Ԫ�ظ�����1
		delete q;			  // �ͷű�ɾ���
	}
}

template <class ElemType>
Status LinkList<ElemType>::InsertElem(const ElemType &e)
// ����������ڵ�����ı�βλ�ò���Ԫ��e
{
	Node<ElemType> *p, *q;
	q = new Node<ElemType>(e, NULL);    // �����½��q
    assert(q);                          // ������ʧ�ܣ���ֹ��������
	for (p = head; p->next != NULL; p = p->next) ;	// pָ���β���
    p->next = q;                        // �ڵ�����ı�βλ�ò����½��
	length++;							// ����ɹ��󣬵������ȼ�1
	return SUCCESS;
}

template <class ElemType>
Node<ElemType>* LinkList<ElemType>::GetHead() const
{
    return head;
}

template <class ElemType>
void LinkList<ElemType>::Show() const
{
    Node<ElemType> *p=head;
    for (int i = 0; i < length; i++)
    {
        p = p->next;
        cout<<p->data<<" ";
    }
    cout<<endl;
}

#endif

