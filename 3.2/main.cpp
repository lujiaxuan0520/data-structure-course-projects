#include <iostream>
#include "SeqList.h"
using namespace std;

void Test1(SeqList<int> &L)
{
    cout<<"������Ҫ�����ֵ:";
    int a;
    cin>>a;
    L.Insert(a);
    cout<<"�����:"<<endl;
    L.Show();
}
void Test2(SeqList<int> &L)
{
    cout<<"��������Ҫɾ����Ԫ�ص�ֵ:";
    int a;
    cin>>a;
    L.Delete(a);
    cout<<"ɾ����:"<<endl;
    L.Show();
}
void Test3(SeqList<int> &L)
{
    int vec[5]={3,6,9,11,22};
    SeqList<int> b(vec,5,5);
    cout<<"˳���A: ";
    L.Show();
    cout<<"˳���B: ";
    b.Show();
    cout<<"�ϲ�����˳���:"<<endl;
    SeqList<int> c=L.Merge(b);
    c.Show();
}
void Test4(SeqList<int> &L)
{
    int s,t;
    cout<<"����s:";
    cin>>s;
    cout<<"����t:";
    cin>>t;
    L.DeleteBetween(s,t);
    cout<<"ɾ��s-t�м������Ԫ��:"<<endl;
    L.Show();
}
int main()
{
    int v[7]={4,4,8,8,8,10,20};
    SeqList<int> L(v,7,10);
    cout<<"˳���A: ";
    L.Show();
    cout<<"�����������:";
    int i;
    cin>>i;
    switch(i)
    {
        case 1:Test1(L);break;
        case 2:Test2(L);break;
        case 3:Test3(L);break;
        case 4:Test4(L);break;
    }
    return 0;
}
