#include <iostream>
#include "SeqList.h"
using namespace std;

void Test1(SeqList<int> &L)
{
    cout<<"请输入要插入的值:";
    int a;
    cin>>a;
    L.Insert(a);
    cout<<"插入后:"<<endl;
    L.Show();
}
void Test2(SeqList<int> &L)
{
    cout<<"请输入需要删除的元素的值:";
    int a;
    cin>>a;
    L.Delete(a);
    cout<<"删除后:"<<endl;
    L.Show();
}
void Test3(SeqList<int> &L)
{
    int vec[5]={3,6,9,11,22};
    SeqList<int> b(vec,5,5);
    cout<<"顺序表A: ";
    L.Show();
    cout<<"顺序表B: ";
    b.Show();
    cout<<"合并两个顺序表:"<<endl;
    SeqList<int> c=L.Merge(b);
    c.Show();
}
void Test4(SeqList<int> &L)
{
    int s,t;
    cout<<"输入s:";
    cin>>s;
    cout<<"输入t:";
    cin>>t;
    L.DeleteBetween(s,t);
    cout<<"删除s-t中间的所有元素:"<<endl;
    L.Show();
}
int main()
{
    int v[7]={4,4,8,8,8,10,20};
    SeqList<int> L(v,7,10);
    cout<<"顺序表A: ";
    L.Show();
    cout<<"请输入操作数:";
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
