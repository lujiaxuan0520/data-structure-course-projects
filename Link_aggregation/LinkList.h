#ifndef __LK_LIST_H__
#define __LK_LIST_H__

#include "Assistance.h"				// 辅助软件包
#include "Node.h"					// 结点类

// 单链表类
template <class ElemType>
class LinkList
{
protected:
//  单链表的数据成员
	Node<ElemType> *head;				// 头结点指针
	int length;							// 单链表长度

public:
//  单链表的函数成员
	LinkList();							// 无参数的构造函数
	virtual ~LinkList();				// 析构函数
	void Clear();						// 将单链表清空
	int LocateElem(const ElemType &e) const;	         // 元素定位
	void DeleteElem(int position, ElemType &e);		 // 删除元素
	Status InsertElem(const ElemType &e);	             // 在表尾插入元素
	Node<ElemType>* GetHead() const;
	void Show() const;
};


// 单链表类的实现部分


template <class ElemType>
LinkList<ElemType>::LinkList()
// 操作结果：构造一个空链表
{
	head = new Node<ElemType>;		// 构造头结点
	assert(head);                   // 构造头结点失败，终止程序运行
	length = 0;						// 初始化单链表长度为0
}

template <class ElemType>
LinkList<ElemType>::~LinkList()
// 操作结果：销毁单链表
{
	Clear();			// 清空单链表
	delete head;		// 释放头结点所指空间
}

template <class ElemType>
void LinkList<ElemType>::Clear()
// 操作结果：清空单链表,删除单链表中所有元素结点
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
// 元素定位
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
// 操作结果：删除单链表的第i个位置的元素, 并用e返回其值,
//	i的取值范围为1≤i≤length,
//	i合法时函数返回SUCCESS,否则函数返回RANGE_ERROR
{
	if (i < 1 || i > length)
		return ;   // i范围错
 	else	{
		Node<ElemType> *p = head, *q;
		int count;
		for (count = 1; count < i; count++)
		  p = p->next;	      // p指向第i-1个结点
		q = p->next;	      // q指向第i个结点
		p->next = q->next;	  // 删除结点
		e = q->data;		  // 用e返回被删结点元素值
		length--;			  // 删除成功后元素个数减1
		delete q;			  // 释放被删结点
	}
}

template <class ElemType>
Status LinkList<ElemType>::InsertElem(const ElemType &e)
// 操作结果：在单链表的表尾位置插入元素e
{
	Node<ElemType> *p, *q;
	q = new Node<ElemType>(e, NULL);    // 生成新结点q
    assert(q);                          // 申请结点失败，终止程序运行
	for (p = head; p->next != NULL; p = p->next) ;	// p指向表尾结点
    p->next = q;                        // 在单链表的表尾位置插入新结点
	length++;							// 插入成功后，单链表长度加1
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

