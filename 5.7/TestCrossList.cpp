#include "CrossList.h"		// ϡ��������Ԫ��˳���

int main(void)
{
    try								// ��try��װ���ܳ����쳣�Ĵ���
	{
		CrossList<int> a(3, 2),b(2,4);	// ����һ��rs��cs��ϡ�����
		int m[3][2] = {
			 1,	 5,
			 2,	 0,
			 4,  3
		};
		int i,j,v;
		for (i = 0; i < 3; i++)
			for (j = 0; j < 2; j++)
				a.SetElem(i, j, m[i][j]);	// ����Ԫ��ֵ


		int n[2][4] = {
			 0,	 5,	 2,	 0,
			 4,  3,  2,  5
		};
		for (i = 0; i < 2; i++)
			for (j = 0; j < 4; j++)
				b.SetElem(i, j, n[i][j]);	// ����Ԫ��ֵ


		// ��ʾϡ�����a
		cout << "��ʾ����a:" << endl;
		for (i = 0; i < a.GetRows(); i++)  {
			for (j = 0; j < a.GetCols(); j++)	{	// ��
				a.GetElem(i, j, v);		// ȡԪ��ֵ
				cout << v << "\t";		// ��ʾԪ��ֵ
			}
			cout << endl;
		}
		cout << endl;

		cout << "��ʾ����b:" << endl;
		for (i = 0; i < b.GetRows(); i++)  {
			for (j = 0; j < b.GetCols(); j++)	{	// ��
				b.GetElem(i, j, v);		// ȡԪ��ֵ
				cout << v << "\t";		// ��ʾԪ��ֵ
			}
			cout << endl;
		}
		cout << endl;

        CrossList<int> c(3, 4);
        c=a*b;
        cout << "��ʾ����a*b:" << endl;
		for (i = 0; i < c.GetRows(); i++)  {
			for (j = 0; j < c.GetCols(); j++)	{	// ��
				c.GetElem(i, j, v);		// ȡԪ��ֵ
				cout << v << "\t";		// ��ʾԪ��ֵ
			}
			cout << endl;
		}
		cout << endl;
	}
	catch (Error err)		// ��׽�������쳣
	{
		err.Show();			// ��ʾ�쳣��Ϣ
	}

  	system("PAUSE");        // ���ÿ⺯��system()
	return 0;               // ����ֵ0, ���ز���ϵͳ
}

