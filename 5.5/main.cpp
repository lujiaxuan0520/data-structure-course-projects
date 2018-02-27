#include <iostream>

using namespace std;

void Andian(int (*a)[3],int m,int n)//m,n分别为二维数组的行数和列数
{
    int Max_j=0;//该行上最大的那个元素的列数
    for(int i=0;i<m;++i)//遍历行
    {
        Max_j=-1;
        for(int j=0;j<n;j++)//遍历列让Max_j得到该行最大的元素的列数
        {
            if(a[i][j]>a[i][Max_j])
            {
                Max_j=j;
            }
        }
        int k;
        for(k=0;k<m;++k)//遍历该元素所在列，验证是否为最小
        {
            if(a[i][Max_j]>a[k][Max_j])
                break;
        }
        if(k==m)//是鞍点
        {
            cout<<"存在鞍点：行下标为"<<i<<" 列下标为"<<Max_j<<" 值为"<<a[i][Max_j]<<endl;
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
