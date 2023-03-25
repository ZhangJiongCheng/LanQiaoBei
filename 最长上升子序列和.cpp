///*
//输入示例：
//7
//1 7 3 5 9 4 8
//
//输出示例：
//18
//*/
//
//#include<iostream>
//using namespace std;
//
//long n;
//long a[1001];
//long dp[1001];  //dp[i]表示以i结尾的最长上升子序列和
//
//int main()
//{
//	cin >> n;
//	for (long i = 1; i <= n; ++i)
//	{
//		cin >> a[i];
//		dp[i] = a[i];
//	}
//
//	long maxx = a[1];
//	for (long i = 2; i <= n; ++i)
//	{
//		for (long j = 1; j < i; ++j)
//			if (a[i] > a[j]) dp[i] = max(dp[i], dp[j] + a[i]);
//		maxx = max(maxx, dp[i]);
//	}
//
//	cout << maxx << endl;
//
//	return 0;
//}