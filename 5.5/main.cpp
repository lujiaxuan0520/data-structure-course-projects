#include <iostream>

using namespace std;

void Andian(int (*a)[3],int m,int n)//m,n�ֱ�Ϊ��ά���������������
{
    int Max_j=0;//�����������Ǹ�Ԫ�ص�����
    for(int i=0;i<m;++i)//������
    {
        Max_j=-1;
        for(int j=0;j<n;j++)//��������Max_j�õ���������Ԫ�ص�����
        {
            if(a[i][j]>a[i][Max_j])
            {
                Max_j=j;
            }
        }
        int k;
        for(k=0;k<m;++k)//������Ԫ�������У���֤�Ƿ�Ϊ��С
        {
            if(a[i][Max_j]>a[k][Max_j])
                break;
        }
        if(k==m)//�ǰ���
        {
            cout<<"���ڰ��㣺���±�Ϊ"<<i<<" ���±�Ϊ"<<Max_j<<" ֵΪ"<<a[i][Max_j]<<endl;
        }
    }
}


int main()
{
    int a[3][3]={{2,2,2},{2,2,2},{2,2,2}};
    //int m=3,n=3;
    Andian(a,3,3);

    return 0;
}
