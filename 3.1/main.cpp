#include <iostream>
#include "SeqList.h"
using namespace std;

void Test1(SeqList<int> &L)
{
    cout<<"ɾ����С��Ԫ�ز������һ��Ԫ���:"<<endl;
    L.DeleteMin();
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
    cout<<"ɾ���ظ���Ԫ�ز�������һ��";
    L.DeleteRepetition();
    cout<<endl<<"ɾ����:"<<endl;
    L.Show();
}

int main()
{
    int v[8]={-3,8,1,14,8,8,0,0};
    SeqList<int> L(v,8,8);
    cout<<"��ʼ˳���"<<endl;
    L.Show();
    cout<<endl<<"�����������:";
    int i;
    cin>>i;
    switch(i)
    {
        case 1:Test1(L);break;
        case 2:Test2(L);break;
        case 3:Test3(L);break;
    }
    return 0;
}
