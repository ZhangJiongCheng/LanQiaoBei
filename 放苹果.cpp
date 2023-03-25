///*
//有m个同样的苹果，放在n个同样的盘子里，允许有的盘子空着不放，
//问共有多少种不同的分法？
//
//输入：
//第一行是测试数据的数目t。以下每行均包含两个整数m，n，以空格分开。
//
//输出：
//对输入的每组数据m和n，用一行输出相应的分法.
//
//输入样例：
//1
//7 3
//
//输出样例：
//8
//*/
//
///*
//f[i][j]表示i个苹果放在j个盘子里的方法数
//边界：f[0][0]=f[0][1]=f[1][0]=f[1][1]=1;
//情况1（i<j）：f[i][j]=f[i][i]
//情况2 (i>j)：
// 分类1(至少有一个空盘)：f[i][j]=f[i][j-1]
// 分类2（每个盘子都不空）： f[i][j]=f[i-j][j]
//*/
//
//#include<iostream>
//#include<cstring>
//using namespace std;
//
//long n, m, t;
//long long f[101][101]; //f[i][j]表示i个苹果放在j个盘子里的方法数 
//long long ans = 0;
//
//int main()
//{
//	cin >> t;
//	while (t--)
//	{
//		memset(f, 0, sizeof(f));
//		cin >> m >> n;
//		for (long i = 0; i <= m; ++i)
//		{
//			for (long j = 0; j <= n; ++j)
//			{
//				if (i <= 1 || j <= 1) f[i][j] = 1;
//				else if (i < j) f[i][j] = f[i][i];
//				else f[i][j] = f[i][j - 1] + f[i - j][j];
//			}
//		}
//
//		cout << f[m][n] << endl;
//	}
//	return 0;
//}