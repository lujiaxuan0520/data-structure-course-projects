#include "LinkStack.h"	// ��ջ��ģ��
#include "TwoStack.h"
int main(void)
{
    TwoStack<int> a;
    int t;
    cout<<"�������5��4��3��2��1��:"<<endl;
    for(int i=5;i>=1;i--)
    {
        a.In(i);
    }
    a.Show();
    cout<<"����һ��Ԫ��:"<<endl;
    a.Out(t);
    a.Show();
	return 0;
}


