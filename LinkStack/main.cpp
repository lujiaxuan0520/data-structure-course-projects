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
    cout<<"�����׺���ʽ����'#'����:"<<endl;
    ch=getchar();
    while(ch!='#')
    {
        if(isdigit(ch)|| ch=='.')//����ǲ���������С���㣬����ջ
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
        else if(!IsOperator(ch)||ch=='('||ch==')')//������ǲ�����Ҳ���ǲ�����
        {
            throw Error("���ʽ���зǷ����ţ�");
        }
        else//�ǲ�������������
        {
            if(opnd.Pop(second)==UNDER_FLOW)
            {
                throw Error("ȱ�ٲ�������");
            }
            if(opnd.Pop(first)==UNDER_FLOW)
            {
               throw Error("ȱ�ٲ�������");
            }
            try
            {
                opnd.Push(Operate(first,ch,second));
            }
            catch(int)
            {
                throw Error("�������");
            }
            ch=getchar();
        }

    }
    if(opnd.Pop(operand)==UNDER_FLOW)
    {
        throw Error("ȱ�ٲ�������");
    }
    if(!opnd.IsEmpty())
    {
        throw Error("ȱ�ٲ�������");
    }
    cout<<"���ʽ�Ľ��Ϊ:"<<operand<<endl;
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
