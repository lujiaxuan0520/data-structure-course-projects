// Class_StringMain.cpp
#include <iostream>
#include <iomanip>
#include<stdio.h>
#include<cstring>
#include "Class_String.h"
#define M 1024
using namespace std;


void frequency(String &s,char * character,int *num)
{
    memset(character,0,sizeof(character));
    memset(num,0,sizeof(num));
    int presentnum=0;//当前character和num的实际长度
    int j;
    for(int i=0;i<s.length();++i)//遍历s中的每个元素
    {

        for(j=0;j<presentnum;++j)//寻找该字符是否已经存在，若存在，数值+1
        {
            if(s[i]==character[j])
            {
                num[j]++;
                break;
            }
        }
        if(j==presentnum)//前面不存在
        {
            presentnum++;
            character[j]=s[i];
            num[j]=1;
        }
    }
}


int main()
{
    String s;
    cin>>s;
    char character[M]={0};
    int num[M]={0};
    frequency(s,character,num);
    for(int i=0;character[i]!='\0';++i)
    {
        cout<<character[i]<<"出现的次数为："<<num[i]<<endl;
    }

    return 0;
}
