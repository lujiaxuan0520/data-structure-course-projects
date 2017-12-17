#include<iostream>
#include"LinkList.h"
using namespace std;

class Polynomial
{
protected:
	LinkList<Polyitem> polyList;
public:
	Polynomial():polyList(){};      //无参构造函数
	~Polynomial(){};                //析构函数
	Polynomial(const Polynomial &copy);     //拷贝构造函数
	int Length()const;
	bool IsZero() const;           //判0
	void SetZero();                  //置0
	void Display();                //显示多项式
	void InsItem(const Polyitem &item);   //插入一项
	Polynomial(const LinkList<Polyitem> &copyLinkList);     //用多项式链表构造
	Polynomial &operator=(const Polynomial &copy);     //赋值运算符重载
	Polynomial operator+(const Polynomial &p) const;
	Polynomial operator-(const Polynomial &p) const;
	Polynomial operator*(const Polynomial &p) const;
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
	while (p != NULL) 
	{
		if(p->data.expn)
			cout<<p->data.coef<<"x^"<<p->data.expn;
		else
			cout<<p->data.coef;
		p = p->next;
		if(p&&p->data.coef>0) cout<<'+';
	}
	cout<<endl;
}
void Polynomial::InsItem(const Polyitem &item)
{
	Node<Polyitem> *p = polyList.head->next;
	int flag=1;
	Polyitem temp1,temp2;
	while (p != NULL) 
	{
		if(item.expn==p->data.expn)    //有指数相同的情况
		{
			p->data.coef += item.coef;
			flag=0;
		}
		p = p->next;
	}
	if(flag==1)
		for(int i=1;i<=polyList.length;i++)     //插入的指数的大小在已有的两个指数之间
		{
			polyList.GetElem(i,temp1);
			polyList.GetElem(i+1,temp2);
			if(item.expn<temp1.expn&&item.expn>temp2.expn)
			{
				polyList.InsertElem(i+1,item);
				flag=0;
				break;
			}
		}
	if(flag==1)                             //插入的指数比已有指数都小 插入到尾部
		polyList.InsertElem(item);
}
Polynomial::Polynomial(const LinkList<Polyitem> &copyLinkList)
{
	/*polyList.head = new Node<Polyitem>;		// 构造头指针
	assert(polyList.head);                   // 构造头指针失败，终止程序运行 
	polyList.length = 0;*/						// 初始化元素个数

	Polyitem e;
	for (int i = 1; i <= copyLinkList.length; i++)	{	// 复制数据元素
		copyLinkList.GetElem(i, e);	       // 取出第i个元素的值放在e中 
		InsItem(e);		       // 将e有序地插入到当前多项式中 
	}
}
Polynomial& Polynomial::operator=(const Polynomial &copy)
{
	polyList=copy.polyList;
	return *this;
}
Polynomial Polynomial::operator+(const Polynomial &p) const
{
	Polynomial temp(*this);
	Node<Polyitem> *pos = p.polyList.head->next;
	while(pos!=NULL)
	{
		temp.InsItem(pos->data);
		pos=pos->next;
	}
	return temp;
}
Polynomial Polynomial::operator-(const Polynomial &p) const
{
	Polynomial temp(*this);
	Node<Polyitem> *pos = p.polyList.head->next;
	while(pos!=NULL)
	{
		temp.InsItem(-pos->data);
		pos=pos->next;
	}
	return temp;
}
Polynomial Polynomial::operator*(const Polynomial &p) const
{
	Polynomial temp,t;
	Node<Polyitem> *pos = p.polyList.head->next;
	while(pos!=NULL)
	{
		t=*this;
		Node<Polyitem> *q = t.polyList.head->next;
		while(q!=NULL)
	    {
		    q->data.coef *= pos->data.coef;
			q->data.expn += pos->data.expn;
			q = q->next;
		}
		temp = temp+t;
		pos = pos->next;
	}
	return temp;
}

int main()
{
	Polyitem a0(5,10),a1(2,6),a2(2,0),a3(2,0);
	Polyitem b0(3,10),b1(7,4),b2(6,1);
	Polyitem a[3]={a0,a1,a2};
	Polyitem b[3]={b0,b1,b2};
	LinkList<Polyitem> al(a,3);
	LinkList<Polyitem> bl(b,3);
	Polynomial la(al);
	Polynomial lb(bl);
	Polynomial lc,ld,le;
	la.InsItem(a3);
	cout<<"la:"<<endl;
	la.Display();
	cout<<"lb:"<<endl;
	lb.Display();
	lc=la+lb;ld=la-lb;le=la*lb;
	cout<<"==============="<<endl;
	cout<<"lc=la+lb:"<<endl;
	lc.Display();
	cout<<"ld=la+lb:"<<endl;
	ld.Display();
	cout<<"le=la+lb:"<<endl;
	le.Display();
	return 0;
}
