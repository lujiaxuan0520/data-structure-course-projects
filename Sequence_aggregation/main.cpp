#include <iostream>
#include <cstring>
#define M 1024
using namespace std;
//顺序结构

bool IsElement(int *p,const int p_num,const int m)//判断m是否为集合a中的元素
{
    for(int i=0;i<p_num;i++)
    {
        if(m==p[i]) return true;
    }
    return false;
}

int main()
{
    int a[M]={0};//集合a
    int a_num=0;//集合a中元素个数
    int b[M]={0};//集合b
    int b_num=0;//集合b中元素个数
    int c[M]={0};//进行集合运算的目标集合
    int c_num=0;
    int temp,i,j,k;//临时变量
    string str;

    //初始化
    cout<<"--------------------------------------------"<<endl;
    cout<<"\t\t\tMenu"<<endl;
    cout<<"  IA:Insert into Set A\tDA:Delete from Set A"<<endl;
    cout<<"  IB:Insert into Set B\tDB:Delete from Set B"<<endl;
    cout<<"  OU:Union\t\tOI:Intersection"<<endl;
    cout<<"  OD:Difference\t\tQ:Quit"<<endl;
    here:
    cout<<"--------------------------------------------"<<endl;
    cout<<"Enter Command===>";

    cin>>str;
    while(!str.empty())
    {
        if(str=="IA")
        {
            cout<<"Please enter the element you want to add:";
            cin>>temp;
            for(i=0;i<a_num;i++)//如果temp的数值已经存在于集合中，就不执行操作
            {
                if(a[i]==temp)
                {
                    cout<<"The current set A is:";
                    for(i=0;i<a_num;i++)
                    {
                        cout<<a[i]<<" ";
                    }
                    cout<<endl;
                    goto here;
                }
            }
            a[a_num]=temp;
            a_num++;
            cout<<"The current set A is:";
            for(i=0;i<a_num;i++)
            {
                cout<<a[i]<<" ";
            }
            cout<<endl;
            goto here;
        }
        else if(str=="IB")
        {
            cout<<"Please enter the element you want to add:";
            cin>>temp;
            for(i=0;i<b_num;i++)//如果temp的数值已经存在于集合中，就不执行操作
            {
                if(b[i]==temp)
                {
                    cout<<"The current set B is:";
                    for(i=0;i<b_num;i++)
                    {
                        cout<<b[i]<<" ";
                    }
                    cout<<endl;
                    goto here;
                }
            }
            b[b_num]=temp;
            b_num++;
            cout<<"The current set B is:";
            for(i=0;i<b_num;i++)
            {
                cout<<b[i]<<" ";
            }
            cout<<endl;
            goto here;
        }
        else if(str=="DA")
        {
            cout<<"Please enter the element you want to delete:";
            cin>>temp;
            for(i=0;i<a_num;i++)
            {
                if(a[i]==temp)
                {
                    for(j=i;j<a_num-1;j++)//删除该元素——移动后面每一位元素的位置
                    {
                        a[j]=a[j+1];
                    }
                    a_num--;
                }
            }
            cout<<"The current set A is:";
            for(i=0;i<a_num;i++)
            {
                cout<<a[i]<<" ";
            }
            cout<<endl;
            goto here;
        }
        else if(str=="DB")
        {
            cout<<"Please enter the element you want to delete:";
            cin>>temp;
            for(i=0;i<b_num;i++)
            {
                if(b[i]==temp)
                {
                    for(j=i;j<b_num-1;j++)//删除该元素——移动后面每一位元素的位置
                    {
                        b[j]=b[j+1];
                    }
                    b_num--;
                }
            }
            cout<<"The current set B is:";
            for(i=0;i<b_num;i++)
            {
                cout<<b[i]<<" ";
            }
            cout<<endl;
            goto here;
        }
        else if(str=="OU")
        {
            memset(c,0,sizeof(c));//清空数组c
            c_num=0;
            for(i=0;i<a_num;i++)//先把a中元素全部复制过来
            {
                c[i]=a[i];
                c_num++;
            }
            for(j=0;j<b_num;j++)//遍历b中元素，如果c中没有，就把这个元素加入c
            {
                for(k=0;k<c_num;k++)
                {
                    if(b[j]!=c[k])
                        continue;
                    break;
                }
                if(k==c_num)
                {
                    c[c_num]=b[j];
                    c_num++;
                }
            }
            cout<<"The result of union is:";
            for(i=0;i<c_num;i++)
            {
                cout<<c[i]<<" ";
            }
            cout<<endl;
            goto here;
        }
        else if(str=="OI")
        {
            memset(c,0,sizeof(c));//清空数组c
            c_num=0;
            for(i=0;i<a_num;i++)
            {
                if(IsElement(b,b_num,a[i]))//a[i]是a中也是b中元素
                {
                    c[c_num]=a[i];
                    c_num++;
                }
            }
            cout<<"The result of intersection is:";
            for(i=0;i<c_num;i++)
            {
                cout<<c[i]<<" ";
            }
            cout<<endl;
            goto here;
        }
        else if(str=="OD")
        {
            memset(c,0,sizeof(c));//清空数组c
            c_num=0;
            for(i=0;i<a_num;i++)
            {
                if(!IsElement(b,b_num,a[i]))//a[i]是a中但不是b中元素
                {
                    c[c_num]=a[i];
                    c_num++;
                }
            }
            cout<<"The result of difference is:";
            for(i=0;i<c_num;i++)
            {
                cout<<c[i]<<" ";
            }
            cout<<endl;
            goto here;
        }
        else if(str=="Q")
        {
            return 0;
        }
        else
        {
            goto here;
        }

    }
    return 0;
}
