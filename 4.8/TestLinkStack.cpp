#include "LinkStack.h"	// ��ջ��ģ��

void test1(int &sum)//ԭ�ݹ����
{
    int x;
    scanf("%d",&x);
    if(x==0) sum=0;
    else
    {
        test1(sum);
        sum+=x;
    }
    printf("%d ",sum);
}

void test2(int &sum)//�ı��ķǵݹ����
{
    LinkStack<int> link;
    int x;
    sum=0;
    scanf("%d",&x);
    while(x)
    {
        link.Push(x);
        scanf("%d",&x);
    }
    printf("%d ",sum);
    while(!link.IsEmpty())
    {
        link.Pop(x);
        sum+=x;
        printf("%d ",sum);
    }
}

int main(void)
{
	int sum=3;
	cout<<"ԭ���򣨵ݹ飩:";
	test1(sum);
	cout<<endl<<"�ı��ǵݹ����:";
	test2(sum);
	return 0;
}


