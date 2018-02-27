// Class_StringMain.cpp
#include <iostream>
#include <iomanip>
#include "Class_String.h"
using namespace std;

int main()
{
    String s("aabbabcbaabaaacbab");
    String t("bab");
    String v("abdc");
    cout<<s.Replace(t,v);
    return 0;
}
