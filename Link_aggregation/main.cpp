#include <iostream>
#include <cstring>
#include "LinkList.h"
using namespace std;
//��ʽ�ṹ

bool IsElement(const LinkList<int> &q,const int m)//�ж�m�Ƿ�Ϊ����q�е�Ԫ��
{
    int i=0;
    i=q.LocateElem(m);
    if(i==0)
        return false;
    else
        return true;
}

int main()
{
    LinkList<int> a;//����a
    LinkList<int> b;//����b
    LinkList<int> c;//���м��������Ŀ�꼯��
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
            for(Node<int>*p=a.GetHead()->next;p!=NULL;p=p->next)//���temp����ֵ�Ѿ������ڼ����У��Ͳ�ִ�в���
            {
                if(p->data==temp)
                {
                    cout<<"The current set A is:";
                    a.Show();
                    goto here;
                }
            }
            a.InsertElem(temp);//��temp��������
            cout<<"The current set A is:";
            a.Show();
            goto here;
        }
        else if(str=="IB")
        {
            cout<<"Please enter the element you want to add:";
            cin>>temp;
            for(Node<int>*p=b.GetHead()->next;p!=NULL;p=p->next)//���temp����ֵ�Ѿ������ڼ����У��Ͳ�ִ�в���
            {
                if(p->data==temp)
                {
                    cout<<"The current set B is:";
                    b.Show();
                    goto here;
                }
            }
            b.InsertElem(temp);//��temp��������
            cout<<"The current set B is:";
            b.Show();
            goto here;
        }
        else if(str=="DA")
        {
            cout<<"Please enter the element you want to delete:";
            cin>>temp;
            i=0;
            i=a.LocateElem(temp);//��λtemp�������е�λ��
            if(i==0)//temp����������
            {
                cout<<"The current set A is:";
                a.Show();
                goto here;
            }
            a.DeleteElem(i,temp);//ɾ����i��Ԫ��
            cout<<"The current set A is:";
            a.Show();
            goto here;
        }
        else if(str=="DB")
        {
            cout<<"Please enter the element you want to delete:";
            cin>>temp;
            i=0;
            i=b.LocateElem(temp);//��λtemp�������е�λ��
            if(i==0)//temp����������
            {
                cout<<"The current set B is:";
                b.Show();
                goto here;
            }
            b.DeleteElem(i,temp);//ɾ����i��Ԫ��
            cout<<"The current set B is:";
            b.Show();
            goto here;
        }
        else if(str=="OU")
        {
            c.Clear();//���c����
            for(Node<int>*p=a.GetHead()->next;p!=NULL;p=p->next)//�Ȱ�a��Ԫ��ȫ�����ƹ���
            {
                c.InsertElem(p->data);
            }
            for(Node<int>*s=b.GetHead()->next;s!=NULL;s=s->next)//����b��Ԫ�أ����a��û�У��Ͱ����Ԫ�ؼ���c
            {
                if(!IsElement(a,s->data))
                c.InsertElem(s->data);
            }
            cout<<"The result of union is:";
            c.Show();
            goto here;
        }
        else if(str=="OI")
        {
            c.Clear();
            for(Node<int>*p=a.GetHead()->next;p!=NULL;p=p->next)
            {
                if(IsElement(b,p->data))//a[i]��a��Ҳ��b��Ԫ��
                {
                    c.InsertElem(p->data);
                }
            }
            cout<<"The result of intersection is:";
            c.Show();
            goto here;
        }
        else if(str=="OD")
        {
            c.Clear();
            for(Node<int>*p=a.GetHead()->next;p!=NULL;p=p->next)
            {
                if(!IsElement(b,p->data))//a[i]��a�е�����b��Ԫ��
                {
                    c.InsertElem(p->data);
                }
            }
            cout<<"The result of difference is:";
            c.Show();
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
