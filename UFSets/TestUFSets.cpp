#include "Assistance.h"				// 辅助软件包
#include "UFSets.h"		            // 并查类

int main(void)
{
    int n = 5;//元素个数
    char c[] = {'a', 'b', 'c', 'd', 'e'};

    UFSets<char> ufsets(c,n);
    ufsets.Union('a','b');
    ufsets.Union('b','c');
    ufsets.Union('d','e');

    bool sign[n];				// 标志数组，已输出的结点值为true，否则值为false
    for (int i = 0; i < n; i++)
        sign[i] = false;
    int p = 0;				// 当前结点
    while (p < n)		{	// 对没有输出的当前结点，输出其等价类
        cout << "{" << ufsets.GetElem(p);
        sign[p] = true;
        for (int i = p + 1; i < n; i++)	{	// 输出等价类
            if (!ufsets.Differ(ufsets.GetElem(p), ufsets.GetElem(i)))	{	// p与i在同一个等价类中
                cout << "," << ufsets.GetElem(i);
                sign[i] = true;
            }
        }
        cout << "}" << endl;
        while (p < n && sign[p]) p++;
    }
	return 0;
}


