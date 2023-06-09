///*
//总公司拥有高效设备m台，准备分给下属的n个分公司，
//各分公司若获得这些设备，可以为国家提供一定的盈利。
//如何分配这m台设备，才能使国家得到的盈利最大？求出最大盈利值。
//其中，m<=15,n<=10。分配原则:每个公司有权获得任意数目的设备，但总台数不超过设备数m。
//
//输入：
//第一行有两个数，第一个数是分公司数n，第二个数是设备台数m;
//接下来是一个n×m的矩阵，表示第i个分公司分配j台机器的盈利。
//
//输出：
//第一行输出最大盈利值。接下来n行，每行有2个数,即分公司编号和该分公司获得设备台数。
//
//输入示例：
//3 3
//30 40 50
//20 30 50
//20 25 30
//
//输出示例：
//70
//1 1
//2 1
//3 1
//*/
//
//#include<iostream>
//using namespace std;
//
//long n, m;
//long a[1001][1001];
//long dp[1001][1001]; //dp[i][j]表示前i个公司分j台设备所能取得的最大盈利
//long getk[1001][1001]; //get[i][j]表示第i个公司在分配j台设备是分得的台数
//
//void print(long n, long m)
//{
//	if (n == 0) return;
//	print(n - 1, m - getk[n][m]);
//	cout << n << " " << getk[n][m] << endl;
//}
//
//int main()
//{
//	cin >> n >> m;
//	for (long i = 1; i <= n; ++i)
//		for (long j = 1; j <= m; ++j)
//			cin >> a[i][j];
//
//	for (long i = 1; i <= n; ++i)
//	{
//		for (long j = 1; j <= m; ++j)
//		{
//			for (long k = 0; k <= j; ++k)
//			{
//				if (dp[i - 1][j - k] + a[i][k] > dp[i][j])
//				{
//					dp[i][j] = dp[i - 1][j - k] + a[i][k];
//					getk[i][j] = k;
//				}
//			}
//		}//for
//	}
//
//	cout << dp[n][m] << endl;
//	print(n, m);
//	return 0;
//}
