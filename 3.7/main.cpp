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
	cout<<"�����ʽ����:"<<endl;
	la.Display();
	cout<<endl;
	Polyitem t(3,1);
	la.InsItem(t);
	cout<<"����3x^1��Ķ���ʽ����:"<<endl;
	la.Display();
	cout<<endl<<"������x��ֵ:";
	double i;
	cin>>i;
	cout<<"��x="<<i<<"ʱ������ʽ�����ֵ��"<<la.calc(i)<<endl;
	cout<<"�����󵼺�Ľ����"<<endl;
	la.Derivative();
	la.Display();
	return 0;
}
