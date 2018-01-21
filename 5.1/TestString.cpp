#include "String.h"			// 串类

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
    String temp;//新开的一个临时字符串
    int j=0,k=0,p=KMP_find(s,t);;//j为主串中当前操作位置，k为模式串中当前操作位置
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
	return 0;               // 返回值0, 返回操作系统
}
