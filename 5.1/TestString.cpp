#include "String.h"			// ����

void GetFailure(const String&pat,int f[])
{
    int j=0,k=-1;
    f[0]=-1;
    while(j<pat.GetLength()-1)
    {
        if(k==-1||pat[k]==pat[j])
        {
            f[++j]=++k;
        }
        else
            k=f[k];
    }
}

int KMP_find(const String &ob,const String&pat,int p=0)
{
    int *f=new int[pat.GetLength()];
    GetFailure(pat,f);
    int i=p,j=0;
    while(i<ob.GetLength()&&j<pat.GetLength()&&pat.GetLength()-j<=ob.GetLength()-i)
    {
        if(j==-1||pat[j]==ob[i])
        {
            i++;j++;
        }
        else
        {
            j=f[j];
        }
    }
    delete []f;
    if(j<pat.GetLength())
    {
        return -1;
    }
    else return i-j;

}

String Replace(String &s,String &t,String &v)
{
    String temp;//�¿���һ����ʱ�ַ���
    int j=0,k=0,p=KMP_find(s,t);;//jΪ�����е�ǰ����λ�ã�kΪģʽ���е�ǰ����λ��
    while(p!=-1)
    {
        for(int i=0;i<p-j;i++)
        {
            temp[k]=s[j];
            k++;j++;
        }
        Insert(temp,v,k);
        k=k+v.GetLength();
        j=j+t.GetLength();

        p=KMP_find(s,t,p+1);
    }
    s=temp;
    return s;
}

int main(void)
{
	String s("aababcbab");
	String t("bab");
	String v("ab");
	Replace(s,t,v);
	Write(s);
	return 0;               // ����ֵ0, ���ز���ϵͳ
}
