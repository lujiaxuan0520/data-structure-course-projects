#include "String.h"			// ����
int CountNewFailure(const String&pat,int *f,int j);
void GetFailure(const String&pat,int *f)//��ͨʧЧ����
{
    int j=0,k=-1;
    f[0]=-1;
    while(j<pat.GetLength()-1)
    {
        if(k==-1||pat[k]==pat[j])
            f[++j]=++k;
        else
            k=f[k];
    }
}

void GetNewFailure(const String&pat,int *f,int *newf)//�Ľ�ʧЧ����
{
    for(int j=0;j<pat.GetLength();j++)
    {
        newf[j]=CountNewFailure(pat,f,j);
    }


}

int CountNewFailure(const String&pat,int *f,int j)
{
    if(j==0||pat[j]!=pat[f[j]])
    {
        return f[j];
    }
    else
    {
        return CountNewFailure(pat,f,f[j]);
    }
}

int main(void)
{
    String s="abcaabbabcabaacbacba";
    int f[s.GetLength()+1]={0};
    int newf[s.GetLength()+1]={0};
    GetFailure(s,f);
    cout<<"��ͨʧЧ������";
    for(int i=0;i<s.GetLength();++i)
    {
        cout<<f[i]<<" ";
    }
    cout<<endl<<"�Ľ�ʧЧ������";
    GetNewFailure(s,f,newf);
    for(int k=0;k<s.GetLength();++k)
    {
        cout<<newf[k]<<" ";
    }
	return 0;               // ����ֵ0, ���ز���ϵͳ
}
