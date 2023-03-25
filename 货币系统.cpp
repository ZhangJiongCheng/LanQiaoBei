///*
//给你一个n种面值的货币系统，求组成面值为m的货币有多少种方案？
//
//输入:
//第一行为n和m.
//接下来n行，每行一个数，表示面值。
//
//输出:
//一行,方案数.
//
//输入示例：
//3  10
//1
//2
//5
//
//输出示例：
//10
//*/
//
//#include<iostream>
//#include<vector>
//using namespace std;
//
//long m, n;
//long long a[10001];
//long long dp[10001];
//
//int main()
//{
//	cin >> n >> m;
//	for (long i = 1; i <= n; ++i) cin >> a[i];
//
//	dp[0] = 1;
//	for (long i = 1; i <= n; ++i)
//		for (long j = 1; j <= m; ++j)
//			if (j >= a[i]) dp[j] = dp[j] + dp[j - a[i]];
//
//	cout << dp[m] << endl;
//
//	return 0;
//}