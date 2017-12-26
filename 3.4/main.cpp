#include <iostream>
#include "LinkList.h"
#include "Assistance.h"
#include "Node.h"
using namespace std;

int main()
{
    int a[6]={0,1,2,3,4,5};
    LinkList<int> L(a,6);
    //Node<int> *temp=L.LocateNode(3);
    //cout<<temp<<endl;
    //temp->Show();
    cout<<L.CountNode(2);
    return 0;
}
