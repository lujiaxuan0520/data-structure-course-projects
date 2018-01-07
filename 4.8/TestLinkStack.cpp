#include "LinkStack.h"	// 链栈类模板

void test1(int &sum)//原递归程序
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

void test2(int &sum)//改编后的非递归程序
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
	cout<<"原程序（递归）:";
	test1(sum);
	cout<<endl<<"改编后非递归程序:";
	test2(sum);
	return 0;
}


