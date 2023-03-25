/*
* 问题描述
你有一架天平和 N 个砝码，这 N 个砝码重量依次是 W_1, W_2, · · · , W_N​ 。

请你计算一共可以称出多少种不同的重量？ 注意砝码可以放在天平两边。

输入格式
输入的第一行包含一个整数 N。

第二行包含 N 个整数：W_1, W_2, W_3, · · · , W_N。

输出格式
输出一个整数代表答案。

样例输入
3
1 4 6

样例输出
10

样例说明
能称出的 10 种重量是：1、2、3、4、5、6、7、9、10、11。

1 = 1；
2 = 6 − 4 (天平一边放 6，另一边放 4)；​

3 = 4 − 1
4 = 4；
5 = 6 − 1；​

6 = 6;
7 = 1 + 6；
9 = 4 + 6 − 1；
10 = 4 + 6；
11 = 1 + 4 + 6。
*/

#include<iostream>
using namespace std;

const long N = 1e5 + 1;
long n;
bool f[101][N];      //f[i][j]表示前i个砝码能不能称出j这个重量 
//状态转移方程为f[i][j]=(f[i-1][j]||f[i-1][j-w[i]]||f[i-1][j+w[i]])
long res = 0; 

//int main()
//{
//	int i;
//	long a, sum = 0;
//	cin >> n;
//	f[0][0] = 1;
//	for (i = 1; i <= n; ++i)
//	{
//		cin >> a;
//		for (int j = 0; j <= sum; ++j)
//		{
//			if (f[i - 1][j])    //没加第i个砝码就能称得j走过重量
//			{
//				f[i][j] = 1;
//				f[i][abs(j - a)] = 1;
//				f[i][j + a] = 1;
//			}
//		}
//		sum += a;
//	}
//
//	for (i = 1; i <= sum; ++i)
//		res += f[n][i];
//	cout << res << endl;
//
//	return 0;
//}

int main()
{
	int i;
	long a, sum = 0;
	cin >> n;
	f[0][0] = 1;
	for (i = 1; i <= n; ++i)
	{
		cin >> a;
		sum += a;
		for (int j = 0; j <= sum; ++j)
			if (f[i - 1][j] || f[i - 1][abs(j - a)] || f[i - 1][j + a])
				f[i][j] = 1;
	}

	for (i = 1; i <= sum; ++i)
		res += f[n][i];
	cout << res << endl;

	return 0;
}