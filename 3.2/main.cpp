#include <iostream>
#include "SeqList.h"
using namespace std;

int main()
{
    int v[7]={4,8,20,8,8,10,4};
    SeqList<int> L(v,7,10);
    L.Insert(8);
    L.Show();
    //L.Delete(8);
    //L.Sort();
    SeqList<int> c(5);
    c.Insert(1);
    c.Insert(2);
    c.Insert(3);
    c.Insert(4);
    c.Show();
    SeqList<int> b=L.Merge(c);
    b.Show();
    b.DeleteBetween(4,4);
    b.Show();


    return 0;
}
