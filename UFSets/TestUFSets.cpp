#include "Assistance.h"				// ���������
#include "UFSets.h"		            // ������

int main(void)
{
    int n = 5;//Ԫ�ظ���
    char c[] = {'a', 'b', 'c', 'd', 'e'};

    UFSets<char> ufsets(c,n);
    ufsets.Union('a','b');
    ufsets.Union('b','c');
    ufsets.Union('d','e');

    bool sign[n];				// ��־���飬������Ľ��ֵΪtrue������ֵΪfalse
    for (int i = 0; i < n; i++)
        sign[i] = false;
    int p = 0;				// ��ǰ���
    while (p < n)		{	// ��û������ĵ�ǰ��㣬�����ȼ���
        cout << "{" << ufsets.GetElem(p);
        sign[p] = true;
        for (int i = p + 1; i < n; i++)	{	// ����ȼ���
            if (!ufsets.Differ(ufsets.GetElem(p), ufsets.GetElem(i)))	{	// p��i��ͬһ���ȼ�����
                cout << "," << ufsets.GetElem(i);
                sign[i] = true;
            }
        }
        cout << "}" << endl;
        while (p < n && sign[p]) p++;
    }
	return 0;
}


