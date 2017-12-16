#include <iostream>
#include "SeqList.h"
using namespace std;

int main()
{
    int v[7]={4,8,20,8,8,10,4};
    SeqList<int> L(v,7,10);
    L.Insert(8);
    L.Show();
    L.Delete(8);
    //L.Sort();
    L.Show();


    return 0;
}
