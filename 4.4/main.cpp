#include <iostream>
#include "TwoSeqStack.h"
using namespace std;

int main()
{
    TwoSeqStack<int> tss;
    //��ջ1��ջ1-5
    for(int i=1;i<=5;i++)
    {
        tss.Push(i,1);
    }
    cout<<"ջ1��ջ1-5��"<<endl;
    tss.Traverse(Write<int>,1);
    cout<<endl;
    //��ջ1��ջԪ��5
    int temp;
    tss.Pop(temp,1);
    cout<<"ջ1��ջԪ��5��"<<endl;
    tss.Traverse(Write<int>,1);
    cout<<endl;

    //��ջ2��ջ6-10
    for(int j=6;j<=10;j++)
    {
        tss.Push(j,2);
    }
    cout<<"ջ2��ջ6-10��"<<endl;
    tss.Traverse(Write<int>,2);
    cout<<endl;
    //��ջ2��ջԪ��10
    tss.Pop(temp,2);
    cout<<"ջ2��ջԪ��10��"<<endl;
    tss.Traverse(Write<int>,2);
    return 0;
}
