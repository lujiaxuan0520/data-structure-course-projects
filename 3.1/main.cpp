#include <iostream>
#include "SeqList.h"
using namespace std;

int main()
{
    int v[7]={-3,8,1,14,8,8,0};
    SeqList<int> L(v,7,10);
    //L.DeleteMin();
    //L.Delete(4);
    L.DeleteRepetition();
    L.Show();


    return 0;
}
