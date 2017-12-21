#include <iostream>
#include "LinkList.h"
#include "Assistance.h"
#include "Node.h"
using namespace std;

int main()
{
    int a[5]={1,2,3,4,5};
    LinkList<int> L(a,5);
    L.Show();
    return 0;
}
