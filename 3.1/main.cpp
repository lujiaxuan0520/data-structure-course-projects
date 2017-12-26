#include <iostream>
#include "SeqList.h"
using namespace std;

void Test1(SeqList<int> &L)
{
    cout<<"删除最小的元素并用最后一个元素填补:"<<endl;
    L.DeleteMin();
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
    cout<<"删除重复的元素并保留第一个";
    L.DeleteRepetition();
    cout<<endl<<"删除后:"<<endl;
    L.Show();
}

int main()
{
    int v[8]={-3,8,1,14,8,8,0,0};
    SeqList<int> L(v,8,8);
    cout<<"初始顺序表："<<endl;
    L.Show();
    cout<<endl<<"请输入操作数:";
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
