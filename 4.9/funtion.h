#ifndef FUNCTION
#define FUNCTION
#include "LinkStack.h"
#include <iostream>
#include <cstdlib>
#include "assistance.h"
#include <cstring>
#include <cstdio>
using namespace std;
int Prior(char op1,char op2)//栈顶操作符和当前操作符的比较
{
    int prior;
    switch(op1)
    {
    case'+':
    case'-':if(op2=='+'||op2=='-'||op2==')'||op2=='#')
                prior=2;//栈顶弹出，当前操作符入栈（栈顶操作符优先级大于等于当前操作符）
            else
                prior=1;//不弹出，当前操作符入栈（栈顶操作符优先级小于当前操作符）
            break;
    case'*':
    case'/':
    case'^':if(op2=='^'||op2=='(')
                prior=1;
            else
                prior=2;
            break;
    case'(':if(op2==')')
                prior=0;//输出括号里的运算
            else if(op2=='#')
                prior=-1;//操作出错
            else
                prior=1;
            break;
    case')':if(op2=='(')
                prior=-1;
            else
                prior=2;
            break;
    case'#':if(op2==')')
                prior=-1;
            else if(op2=='#')
                prior=3;//已经完成转换
            else
                prior=1;
            break;
    }
    return prior;
}

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
double Operate(double left,char op,double right)
{
    double result;
    switch(op)
    {
    case'+':
        result=left + right;
        break;
    case'-':
        result=left-right;
        break;
    case'*':
        result=left * right;
        break;
    case'/':
        result=left/right;
        break;
    case'^':
        result=pow(left,right);
        break;
    }
    return result;
}

void Calculation()
{
    LinkStack<double> opnd;//操作数栈
    LinkStack<char> optr;//操作符栈
    char ch,op,optrtop='#',priorchar;
    double operand,left,right;
    optr.push('#');
    priorchar='#';
    cout<<"输入中缀表达式,以#结束:"<<endl;;
    ch=GetChar();
    while(optrtop!='#'||ch!='#')
    {
        if(isdigit(ch))
        {
            if(priorchar=='0'||priorchar==')')
            {
                throw Error("两个操作数之间缺少运算符！");
            }
            cin.putback(ch);//将ch重新放回输入流
            cin>>operand;//可读取一个多位操作数
            opnd.push(operand);
            priorchar='0';
            ch=GetChar();
        }
        else if(!IsOperator(ch))//不是操作数并且不是操作符
        {
            throw Error("表达式中有非法符号！");
        }
        else//ch为操作符
        {
            if(ch=='('&&(priorchar=='0'||priorchar==')'))//左括号和前面字符不符合读入语法
            {
                throw Error("'('前缺少操作符");
            }
            while(Prior(optrtop,ch)==2)//栈顶操作符优先级大于等于当前操作符，栈顶弹出，当前操作符入栈，直到栈顶操作符优先级小于当前操作符
            {
                optr.pop(op);//弹出当前栈顶操作符
                if(opnd.pop(right)==UNDER_FLOW)//弹出右操作数
                {
                    throw Error("缺少操作数！");
                }
                if(opnd.pop(left)==UNDER_FLOW)//弹出左操作数
                {
                    throw Error("缺少操作数！");
                }
                opnd.push(Operate(left,op,right));//左结合计算结果
                if(optr.top(optrtop)==UNDER_FLOW)//取出栈顶的操作符进行下一次循环比较
                {
                    throw Error("缺少操作符！");
                }
            }
            switch(Prior(optrtop,ch))
            {
                case -1:throw Error("括号不匹配！");
                case 0: optr.pop(optrtop);//左括号和右括号匹配成功，弹出左括号，同时右括号也不入栈
                        if(optr.top(optrtop)==UNDER_FLOW)
                            throw Error("缺少操作符！");
                        priorchar=ch;
                        ch=GetChar();
                        break;
                case 1:optr.push(ch);//普通入栈
                        optrtop=ch;
                        priorchar=ch;
                        ch=GetChar();
                        break;
            }
        }
    }
    if(opnd.pop(operand)==UNDER_FLOW)//取出最后的操作数即结果
    {
        throw Error("缺少操作數！");
    }
    cout<<operand;
}
#endif // FUNCTION
