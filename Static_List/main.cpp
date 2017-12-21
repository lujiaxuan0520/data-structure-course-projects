#include <iostream>
#include "Node.h"
#include "StaList.h"
using namespace std;

int main()
{
    StaList<int> a(5);
    cout<<"使用普通构造函数构造一个最大空间为5的空链表"<<endl;
    cout<<"输出链表a: ";
    a.Show();
    cout<<endl<<"链表a的实际大小:"<<a.GetLength()<<" 链表a的最大空间:"<<a.GetMaxLength()<<endl;
    int Array[6]={1,2,3,4,5,6};
    StaList<int> b(Array,6,8);
    cout<<"使用已有数组构造一个长度为6，最大空间为8的链表b"<<endl;
    cout<<"输出链表b:";
    b.Show();
    cout<<endl<<"链表b的实际大小:"<<b.GetLength()<<" 链表b的最大空间:"<<b.GetMaxLength()
        <<" 链表b的剩余空闲空间:"<<b.GetRemainedLength()<<endl;
    b.InsertElemBefore(5);
    cout<<"在链首插入元素5后的链表b:";
    b.Show();
    b.DeleteElem2(3);
    cout<<endl<<"删除逻辑上的第3个结点后链表b:";
    b.Show();
    return 0;
}
