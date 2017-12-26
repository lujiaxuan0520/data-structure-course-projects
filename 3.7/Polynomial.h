#ifndef _POLYNOMIAL_H
#define _POLYNOMIAL_H
#include "Assistance.h"				// 辅助软件包
#include "Node.h"					// 结点类

class Polynomial
{
protected:
	LinkList<Polyitem> polyList;
public:
	Polynomial():polyList(){};
	~Polynomial(){};
	Polynomial(const Polynomial &copy);
	int Length()const;
	bool IsZero() const;
	void SetZero();
	void Display();
	void InsItem(const Polyitem &item);
	Polynomial(const LinkList<Polyitem> &copyLinkList);
	Polynomial &operator=(const Polynomial &copy);
	double calc(double x);
	void Derivative();
};
Polynomial::Polynomial(const Polynomial &copy)
{
	polyList=copy.polyList;
}
int Polynomial::Length() const
{
	return polyList.length;
}
bool Polynomial::IsZero() const
{
	if(polyList.length==0)
		return true;
	else
		return false;
}
void Polynomial::SetZero()
{
	polyList.Clear();
}
void Polynomial::Display()
{
	Node<Polyitem> *p = polyList.head->next;
	while (p != polyList.head)
	{
		if(p->data.expn!=0&&p->data.coef!=0)      //指数不为0 系数不为0
			cout<<p->data.coef<<"x^"<<p->data.expn;
		if(p->data.expn==0&&p->data.coef!=0)       //指数为0 系数不为0
			cout<<p->data.coef;
		p = p->next;
		if(p!=polyList.head&&p->data.coef>0) cout<<'+';
	}
}
void Polynomial::InsItem(const Polyitem &item)
{
	if(item.coef!=0)
	{
	Node<Polyitem> *p = polyList.head->next,*pguard = polyList.head,*q;
	int flag=1;
	Polyitem temp;
	while (p != polyList.head)
	{
		if(item.expn==p->data.expn)    //有指数相同的情况
		{
			p->data.coef += item.coef;
			flag=0;
			break;
		}
		if(item.expn>p->data.expn)
		{
			q = new Node<Polyitem>(item, p);    // 生成新结点q
			assert(q);                          // 申请结点失败，终止程序运行
		    pguard->next = q;				    // 将q插入到链表中
		    polyList.length++;					// 插入成功后，单链表长度加1 //polyList.InsertElem(count,item);
			flag=0;
			break;
		}
		p = p->next;
		pguard = pguard->next;
	}
	if(flag==1)                             //插入的指数比已有指数都小 插入到尾部
	{
		q = new Node<Polyitem>(item, p);    // 生成新结点q
		assert(q);                          // 申请结点失败，终止程序运行
		pguard->next = q;				    // 将q插入到链表中
		polyList.length++;					// 插入成功后，单链表长度加1
	}
	}
}
Polynomial::Polynomial(const LinkList<Polyitem> &copyLinkList)
{
	polyList=copyLinkList;
}
Polynomial& Polynomial::operator=(const Polynomial &copy)
{
	polyList=copy.polyList;
	return *this;
}
double Polynomial::calc(double x)
{
	double result=0;
	Node<Polyitem> *p = polyList.head->next;
	while(p!=polyList.head)
	{
		double temp=1;
		for(int i=0;i<p->data.expn;i++)
			temp*=x;
		result+=p->data.coef*temp;
		p=p->next;
	}
	return result;
}
void Polynomial::Derivative()
{
	Node<Polyitem> *p = polyList.head->next;
	while(p!=polyList.head)
	{
		if(p->data.expn==0) p->data.coef=0;
		else
		{
			p->data.coef*=p->data.expn;
		    --(p->data.expn);
		}
		    p=p->next;
	}
}
#endif // _POLYNOMIAL_H
