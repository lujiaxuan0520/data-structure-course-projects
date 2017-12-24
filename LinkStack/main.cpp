#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include "Node.h"
#include "LinkStack.h"
#include "Assistance.h"
using namespace std;

bool IsOperator(char ch)
{
    if(ch=='#'||ch=='('||ch==')'||ch=='^'||ch=='*'||ch=='/'||ch=='+'||ch=='-')
    {
        return true;
    }
    else
    {
        return false;
    }
}

double Operate(double f,char c,double s) throw(int)
{
    if(c=='+')
    {
        return f+s;
    }
    else if(c=='-')
    {
        return f-s;
    }
    else if(c=='*')
    {
        return f*s;
    }
    else if(c=='/')
    {
        if(s==0) throw (int)0;
        else return f/s;
    }
    else if(c=='^')
    {
        return pow(f,s);
    }
}

void Calculation() throw(Error)
{
    LinkStack<double> opnd;
    char ch;
    double operand,first,second;
    cout<<"输入后缀表达式，以'#'结束:"<<endl;
    ch=getchar();
    while(ch!='#')
    {
        if(isdigit(ch)|| ch=='.')//如果是操作数或者小数点，就入栈
        {
            cin.putback(ch);
            cin>>operand;
            opnd.Push(operand);
            ch=getchar();
        }
        else if(ch==' ')
        {
            ch=getchar();
        }
        else if(!IsOperator(ch)||ch=='('||ch==')')//如果不是操作符也不是操作数
        {
            throw Error("表达式中有非法符号！");
        }
        else//是操作符，则运算
        {
            if(opnd.Pop(second)==UNDER_FLOW)
            {
                throw Error("缺少操作数！");
            }
            if(opnd.Pop(first)==UNDER_FLOW)
            {
               throw Error("缺少操作数！");
            }
            try
            {
                opnd.Push(Operate(first,ch,second));
            }
            catch(int)
            {
                throw Error("运算出错！");
            }
            ch=getchar();
        }

    }
    if(opnd.Pop(operand)==UNDER_FLOW)
    {
        throw Error("缺少操作数！");
    }
    if(!opnd.IsEmpty())
    {
        throw Error("缺少操作符！");
    }
    cout<<"表达式的结果为:"<<operand<<endl;
}

int main()
{
    try
    {
        Calculation();
    }
    catch(Error e)
    {
        e.Show();
    }
    return 0;
}
