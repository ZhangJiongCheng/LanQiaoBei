///*
//输入示例：
//4 6
//1 4
//2 6
//3 12
//2 7
//
//输出示例：
//23
//*/
//
//#include<iostream>
//using namespace std;
//
//long n, m;
//long w[3501], c[3501];
//long dp[12881];
//
//int main()
//{
//	cin >> n >> m;
//	for (long i = 1; i <= n; ++i) cin >> w[i] >> c[i];
//
//	for (long i = 1; i <= n; ++i)
//		for (long j = m; j >= w[i]; --j)
//			dp[j] = max(dp[j], dp[j - w[i]] + c[i]);
//
//	cout << dp[m] << endl;
//
//	return 0;
//}