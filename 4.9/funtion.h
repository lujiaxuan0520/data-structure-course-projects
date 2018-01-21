#ifndef FUNCTION
#define FUNCTION
#include "LinkStack.h"
#include <iostream>
#include <cstdlib>
#include "assistance.h"
#include <cstring>
#include <cstdio>
using namespace std;
int Prior(char op1,char op2)//ջ���������͵�ǰ�������ıȽ�
{
    int prior;
    switch(op1)
    {
    case'+':
    case'-':if(op2=='+'||op2=='-'||op2==')'||op2=='#')
                prior=2;//ջ����������ǰ��������ջ��ջ�����������ȼ����ڵ��ڵ�ǰ��������
            else
                prior=1;//����������ǰ��������ջ��ջ�����������ȼ�С�ڵ�ǰ��������
            break;
    case'*':
    case'/':
    case'^':if(op2=='^'||op2=='(')
                prior=1;
            else
                prior=2;
            break;
    case'(':if(op2==')')
                prior=0;//��������������
            else if(op2=='#')
                prior=-1;//��������
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
                prior=3;//�Ѿ����ת��
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
    LinkStack<double> opnd;//������ջ
    LinkStack<char> optr;//������ջ
    char ch,op,optrtop='#',priorchar;
    double operand,left,right;
    optr.push('#');
    priorchar='#';
    cout<<"������׺���ʽ,��#����:"<<endl;;
    ch=GetChar();
    while(optrtop!='#'||ch!='#')
    {
        if(isdigit(ch))
        {
            if(priorchar=='0'||priorchar==')')
            {
                throw Error("����������֮��ȱ���������");
            }
            cin.putback(ch);//��ch���·Ż�������
            cin>>operand;//�ɶ�ȡһ����λ������
            opnd.push(operand);
            priorchar='0';
            ch=GetChar();
        }
        else if(!IsOperator(ch))//���ǲ��������Ҳ��ǲ�����
        {
            throw Error("���ʽ���зǷ����ţ�");
        }
        else//chΪ������
        {
            if(ch=='('&&(priorchar=='0'||priorchar==')'))//�����ź�ǰ���ַ������϶����﷨
            {
                throw Error("'('ǰȱ�ٲ�����");
            }
            while(Prior(optrtop,ch)==2)//ջ�����������ȼ����ڵ��ڵ�ǰ��������ջ����������ǰ��������ջ��ֱ��ջ�����������ȼ�С�ڵ�ǰ������
            {
                optr.pop(op);//������ǰջ��������
                if(opnd.pop(right)==UNDER_FLOW)//�����Ҳ�����
                {
                    throw Error("ȱ�ٲ�������");
                }
                if(opnd.pop(left)==UNDER_FLOW)//�����������
                {
                    throw Error("ȱ�ٲ�������");
                }
                opnd.push(Operate(left,op,right));//���ϼ�����
                if(optr.top(optrtop)==UNDER_FLOW)//ȡ��ջ���Ĳ�����������һ��ѭ���Ƚ�
                {
                    throw Error("ȱ�ٲ�������");
                }
            }
            switch(Prior(optrtop,ch))
            {
                case -1:throw Error("���Ų�ƥ�䣡");
                case 0: optr.pop(optrtop);//�����ź�������ƥ��ɹ������������ţ�ͬʱ������Ҳ����ջ
                        if(optr.top(optrtop)==UNDER_FLOW)
                            throw Error("ȱ�ٲ�������");
                        priorchar=ch;
                        ch=GetChar();
                        break;
                case 1:optr.push(ch);//��ͨ��ջ
                        optrtop=ch;
                        priorchar=ch;
                        ch=GetChar();
                        break;
            }
        }
    }
    if(opnd.pop(operand)==UNDER_FLOW)//ȡ�����Ĳ����������
    {
        throw Error("ȱ�ٲ�������");
    }
    cout<<operand;
}
#endif // FUNCTION
