#include <iostream>
#include "Node.h"
#include "StaList.h"
using namespace std;

int main()
{

    int b[4]={1,2,3,4};
    StaList<int> a(b,4,4);
    //a.InsertElemBefore(4);
    a.Show();
    a.Clear();
    a.Show();
//    cout<<a.GetLength();
//    cout<<a.GetMaxLength();
//    cout<<a.GetRemainedLength();
    return 0;
}
