#include <iostream>
#include "Node.h"
#include "StaList.h"
using namespace std;

int main()
{
    StaList<int> a(5);
    cout<<"ʹ����ͨ���캯������һ�����ռ�Ϊ5�Ŀ�����"<<endl;
    cout<<"�������a: ";
    a.Show();
    cout<<endl<<"����a��ʵ�ʴ�С:"<<a.GetLength()<<" ����a�����ռ�:"<<a.GetMaxLength()<<endl;
    int Array[6]={1,2,3,4,5,6};
    StaList<int> b(Array,6,8);
    cout<<"ʹ���������鹹��һ������Ϊ6�����ռ�Ϊ8������b"<<endl;
    cout<<"�������b:";
    b.Show();
    cout<<endl<<"����b��ʵ�ʴ�С:"<<b.GetLength()<<" ����b�����ռ�:"<<b.GetMaxLength()
        <<" ����b��ʣ����пռ�:"<<b.GetRemainedLength()<<endl;
    b.InsertElemBefore(5);
    cout<<"�����ײ���Ԫ��5�������b:";
    b.Show();
    b.DeleteElem2(3);
    cout<<endl<<"ɾ���߼��ϵĵ�3����������b:";
    b.Show();
    return 0;
}
