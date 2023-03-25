///*
//设有n种物品，每种物品有一个重量及一个价值，但每种物品的数量是无限的，
//同时有一个背包最大载重量为m，从n种物品中选取若干件，使其重量的和小于等于m，而价值的和为最大。
//
//输入:
//第一行两个整数m和n，第二到n+1行，每行两个整数，wi,ci表示每个物品的重量和价值.
//
//输出:
//仅一行，一个数，表示最大总价值。
//
//输入示例：
//10 4
//2  1
//3  3
//4  5
//7  9
//
//输出示例：
//max=12
//*/
//
//#include<iostream>
//using namespace std;
//
//long m;  //背包容量
//long n;  //物品数量
//long w[101], c[101];
//long dp[201];   //dp[i]表示用了i公斤的容量所能获得的最大价值
//
//int main()
//{
//	cin >> m >> n;
//	for (long i = 1; i <= n; ++i) 
//		cin >> w[i] >> c[i];
//
//	for (long i = 1; i <= n; ++i)
//		for (long j = m; j >= 1; --j)
//			for (long k = 0; k <= j / w[i]; ++k)
//				if (j >= k * w[i])dp[j] = max(dp[j], dp[j - k * w[i]] + k * c[i]);
//
//	cout << "max=" << dp[m] << endl;
//
//	return 0;
//}