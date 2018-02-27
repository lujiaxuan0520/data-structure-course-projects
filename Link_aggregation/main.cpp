#include <iostream>
#include <cstring>
#include "LinkList.h"
using namespace std;
//链式结构

bool IsElement(const LinkList<int> &q,const int m)//判断m是否为集合q中的元素
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
    LinkList<int> a;//集合a
    LinkList<int> b;//集合b
    LinkList<int> c;//进行集合运算的目标集合
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
            for(Node<int>*p=a.GetHead()->next;p!=NULL;p=p->next)//如果temp的数值已经存在于集合中，就不执行操作
            {
                if(p->data==temp)
                {
                    cout<<"The current set A is:";
                    a.Show();
                    goto here;
                }
            }
            a.InsertElem(temp);//把temp加入链表
            cout<<"The current set A is:";
            a.Show();
            goto here;
        }
        else if(str=="IB")
        {
            cout<<"Please enter the element you want to add:";
            cin>>temp;
            for(Node<int>*p=b.GetHead()->next;p!=NULL;p=p->next)//如果temp的数值已经存在于集合中，就不执行操作
            {
                if(p->data==temp)
                {
                    cout<<"The current set B is:";
                    b.Show();
                    goto here;
                }
            }
            b.InsertElem(temp);//把temp加入链表
            cout<<"The current set B is:";
            b.Show();
            goto here;
        }
        else if(str=="DA")
        {
            cout<<"Please enter the element you want to delete:";
            cin>>temp;
            i=0;
            i=a.LocateElem(temp);//定位temp在链表中的位置
            if(i==0)//temp不在链表中
            {
                cout<<"The current set A is:";
                a.Show();
                goto here;
            }
            a.DeleteElem(i,temp);//删除第i个元素
            cout<<"The current set A is:";
            a.Show();
            goto here;
        }
        else if(str=="DB")
        {
            cout<<"Please enter the element you want to delete:";
            cin>>temp;
            i=0;
            i=b.LocateElem(temp);//定位temp在链表中的位置
            if(i==0)//temp不在链表中
            {
                cout<<"The current set B is:";
                b.Show();
                goto here;
            }
            b.DeleteElem(i,temp);//删除第i个元素
            cout<<"The current set B is:";
            b.Show();
            goto here;
        }
        else if(str=="OU")
        {
            c.Clear();//清空c链表
            for(Node<int>*p=a.GetHead()->next;p!=NULL;p=p->next)//先把a中元素全部复制过来
            {
                c.InsertElem(p->data);
            }
            for(Node<int>*s=b.GetHead()->next;s!=NULL;s=s->next)//遍历b中元素，如果a中没有，就把这个元素加入c
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
                if(IsElement(b,p->data))//a[i]是a中也是b中元素
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
                if(!IsElement(b,p->data))//a[i]是a中但不是b中元素
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
