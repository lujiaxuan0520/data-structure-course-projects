#include "LinkQueue.h"	// ��������

int main(void)
{
	int num;
	cout<<"����������:";
	cin>>num;num++;
	LinkQueue<int> link;
	int m=0,n;
	link.EnQueue(0);link.EnQueue(1);link.EnQueue(1);
	link.EnQueue(0);
	for(int i=1;i<num;++i)
    {
        for(int k=0;k<num-i;++k)
        {
            cout<<" ";
        }
        for(int j=0;j<i+3;++j)
        {
            link.DelQueue(n);
            link.EnQueue(m+n);
            m=n;
            if(m!=0) cout<<m<<" ";
        }
        link.EnQueue(0);
        cout<<endl;
    }
	return 0;
}


