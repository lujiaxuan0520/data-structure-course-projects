#include "Assistance.h"
#include "ChildSiblingTree.h"
using namespace std;

int main()
{
    char items[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    int parents[] = {-1, 0, 0, 0, 1, 1, 3, 3};
    int n = 8;
    ChildSiblingTree<char> t(items, parents, n);
    cout << "��:" << endl;
    DisplayTWithConcaveShape(t);
    cout << endl;

    cout<<"�������Ϊ��";
    cout<<t.Height(t.GetRoot())<<endl;

    cout<<"���Ķ�Ϊ��";
    cout<<t.TreeDegree(t.GetRoot());

    return 0;
}
