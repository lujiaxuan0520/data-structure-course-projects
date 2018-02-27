#include <iostream>
#include <cstring>
#define M 1024
using namespace std;
//˳��ṹ

bool IsElement(int *p,const int p_num,const int m)//�ж�m�Ƿ�Ϊ����a�е�Ԫ��
{
    for(int i=0;i<p_num;i++)
    {
        if(m==p[i]) return true;
    }
    return false;
}

int main()
{
    int a[M]={0};//����a
    int a_num=0;//����a��Ԫ�ظ���
    int b[M]={0};//����b
    int b_num=0;//����b��Ԫ�ظ���
    int c[M]={0};//���м��������Ŀ�꼯��
    int c_num=0;
    int temp,i,j,k;//��ʱ����
    string str;

    //��ʼ��
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
            for(i=0;i<a_num;i++)//���temp����ֵ�Ѿ������ڼ����У��Ͳ�ִ�в���
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
            for(i=0;i<b_num;i++)//���temp����ֵ�Ѿ������ڼ����У��Ͳ�ִ�в���
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
                    for(j=i;j<a_num-1;j++)//ɾ����Ԫ�ء����ƶ�����ÿһλԪ�ص�λ��
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
                    for(j=i;j<b_num-1;j++)//ɾ����Ԫ�ء����ƶ�����ÿһλԪ�ص�λ��
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
            memset(c,0,sizeof(c));//�������c
            c_num=0;
            for(i=0;i<a_num;i++)//�Ȱ�a��Ԫ��ȫ�����ƹ���
            {
                c[i]=a[i];
                c_num++;
            }
            for(j=0;j<b_num;j++)//����b��Ԫ�أ����c��û�У��Ͱ����Ԫ�ؼ���c
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
            memset(c,0,sizeof(c));//�������c
            c_num=0;
            for(i=0;i<a_num;i++)
            {
                if(IsElement(b,b_num,a[i]))//a[i]��a��Ҳ��b��Ԫ��
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
            memset(c,0,sizeof(c));//�������c
            c_num=0;
            for(i=0;i<a_num;i++)
            {
                if(!IsElement(b,b_num,a[i]))//a[i]��a�е�����b��Ԫ��
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
