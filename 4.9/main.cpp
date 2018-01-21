#include <iostream>
#include "LinkStack.h"
#include "funtion.h"
using namespace std;
int main()
{
    try
    {
        Calculation();
    }
    catch(Error e)
    {
        e.Show();
    }
    return 0;
}
