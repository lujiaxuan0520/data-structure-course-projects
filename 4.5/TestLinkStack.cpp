#include "LinkStack.h"	// 链栈类模板
#include "TwoStack.h"
int main(void)
{
    TwoStack<int> a;
    int t;
    cout<<"依次入队5、4、3、2、1后:"<<endl;
    for(int i=5;i>=1;i--)
    {
        a.In(i);
    }
    a.Show();
    cout<<"出队一个元素:"<<endl;
    a.Out(t);
    a.Show();
	return 0;
}


