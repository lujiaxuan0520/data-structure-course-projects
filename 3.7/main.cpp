#include<iostream>
#include"LinkList.h"
#include "Polynomial.h"
using namespace std;

int main()
{
	Polyitem a0(6,8),a1(2,4),a2(4,0);
	Polyitem a[3]={a0,a1,a2};
	LinkList<Polyitem> al(a,3);
	Polynomial la(al);
	cout<<"设多项式链表:"<<endl;
	la.Display();
	cout<<endl;
	Polyitem t(3,1);
	la.InsItem(t);
	cout<<"插入3x^1后的多项式链表:"<<endl;
	la.Display();
	cout<<endl<<"请输入x的值:";
	double i;
	cin>>i;
	cout<<"当x="<<i<<"时，多项式链表的值是"<<la.calc(i)<<endl;
	cout<<"对其求导后的结果："<<endl;
	la.Derivative();
	la.Display();
	return 0;
}
