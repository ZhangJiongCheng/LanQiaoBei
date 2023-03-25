///*
//* 输入
//10
//0 2 5 1 0 0 0 0 0 0
//0 0 0 0 12 14 0 0 0 0
//0 0 0 0 6 10 4 0 0 0
//0 0 0 0 13 12 11 0 0 0
//0 0 0 0 0 0 0 3 9 0
//0 0 0 0 0 0 0 6 5 0
//0 0 0 0 0 0 0 0 10 0
//0 0 0 0 0 0 0 0 0 5
//0 0 0 0 0 0 0 0 0 2
//0 0 0 0 0 0 0 0 0 0
//
//输出
//minLong=19
//1 3 5 8 10
//*/
//
//#define INF 0x3f3f3f3f
//
//#include<iostream>
//using namespace std;
//
//long n;
//long a[1001][1001];
//long dp[1001];     //dp[i]表示第i个顶点到指定顶点的最短距离为dp[i]
//long nex[1001];   //nex[i]表示第i个顶点的后继为nex[i]
//
//int main()
//{
//	cin >> n;
//	for (long i = 1; i <= n; ++i)
//		for (long j = 1; j <= n; ++j)
//			cin >> a[i][j];
//
//	for (long i = 1; i < n; ++i) dp[i] = INF;
//
//	dp[n] = 0;
//	nex[n] = 0;
//	for (long i = n - 1; i >= 1; --i)
//	{
//		for (long j = i + 1; j <= n; ++j)
//		{
//			if (a[i][j] && dp[j] + a[i][j] < dp[i])
//			{
//				dp[i] = dp[j] + a[i][j];
//				nex[i] = j;
//			}
//		}//for
//	}
//	cout << "minLong=" << dp[1] << endl;
//	long minIndex = 1;
//	while (minIndex)
//	{
//		cout << minIndex << " ";
//		minIndex = nex[minIndex];
//	}
//
//	return 0;
//}