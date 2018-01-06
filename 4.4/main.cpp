#include <iostream>
#include "TwoSeqStack.h"
using namespace std;

int main()
{
    TwoSeqStack<int> tss;
    //给栈1入栈1-5
    for(int i=1;i<=5;i++)
    {
        tss.Push(i,1);
    }
    cout<<"栈1入栈1-5后："<<endl;
    tss.Traverse(Write<int>,1);
    cout<<endl;
    //给栈1出栈元素5
    int temp;
    tss.Pop(temp,1);
    cout<<"栈1出栈元素5后："<<endl;
    tss.Traverse(Write<int>,1);
    cout<<endl;

    //给栈2入栈6-10
    for(int j=6;j<=10;j++)
    {
        tss.Push(j,2);
    }
    cout<<"栈2入栈6-10后："<<endl;
    tss.Traverse(Write<int>,2);
    cout<<endl;
    //给栈2出栈元素10
    tss.Pop(temp,2);
    cout<<"栈2出栈元素10后："<<endl;
    tss.Traverse(Write<int>,2);
    return 0;
}
