#include "CrossList.h"		// 稀疏矩阵的三元组顺序表

int main(void)
{
    try								// 用try封装可能出现异常的代码
	{
		CrossList<int> a(3, 2),b(2,4);	// 定义一个rs行cs列稀疏矩阵
		int m[3][2] = {
			 1,	 5,
			 2,	 0,
			 4,  3
		};
		int i,j,v;
		for (i = 0; i < 3; i++)
			for (j = 0; j < 2; j++)
				a.SetElem(i, j, m[i][j]);	// 设置元素值


		int n[2][4] = {
			 0,	 5,	 2,	 0,
			 4,  3,  2,  5
		};
		for (i = 0; i < 2; i++)
			for (j = 0; j < 4; j++)
				b.SetElem(i, j, n[i][j]);	// 设置元素值


		// 显示稀疏矩阵a
		cout << "显示矩阵a:" << endl;
		for (i = 0; i < a.GetRows(); i++)  {
			for (j = 0; j < a.GetCols(); j++)	{	// 列
				a.GetElem(i, j, v);		// 取元素值
				cout << v << "\t";		// 显示元素值
			}
			cout << endl;
		}
		cout << endl;

		cout << "显示矩阵b:" << endl;
		for (i = 0; i < b.GetRows(); i++)  {
			for (j = 0; j < b.GetCols(); j++)	{	// 列
				b.GetElem(i, j, v);		// 取元素值
				cout << v << "\t";		// 显示元素值
			}
			cout << endl;
		}
		cout << endl;

        CrossList<int> c(3, 4);
        c=a*b;
        cout << "显示矩阵a*b:" << endl;
		for (i = 0; i < c.GetRows(); i++)  {
			for (j = 0; j < c.GetCols(); j++)	{	// 列
				c.GetElem(i, j, v);		// 取元素值
				cout << v << "\t";		// 显示元素值
			}
			cout << endl;
		}
		cout << endl;
	}
	catch (Error err)		// 捕捉并处理异常
	{
		err.Show();			// 显示异常信息
	}

  	system("PAUSE");        // 调用库函数system()
	return 0;               // 返回值0, 返回操作系统
}

