///*
//一个旅行者有一个最多能装m公斤的背包，现在有n件物品，他们重量分别为w1，w2,..., wn，
//他们的价值分别为c1，c2,..., cn，这些物品被划分为若干组，每组中的物品互相冲突，最多选一件，
//求解将哪些物品装入背包，可使这些物品的费用总额不超过背包容量，且价值总和最大。
//
//输入：
//第一行 ，三个整数m,n,t(t是组数)
//第二到n+1行，每行三个整数w,c,p,表示每个物品的重量,价值,所属组号。
//
//输出：
//仅一行，一个数，表示最大总价值。
//
//输入示例：
//10 6  3
//2  1  1
//3  3  1
//4  8  2
//6  9  2
//2  8  3
//3  9  3
//
//输出示例：
//20
//*/
//
//#include<iostream>
//#include<vector>
//using namespace std;
//
//long m, n, t;
//long w[31], c[31];
//long dp[201];
//
//int main()
//{
//	cin >> m >> n >> t;
//
//	vector<vector<long>> group(t + 1);
//	long p;
//	for (long i = 1; i <= n; ++i)
//	{
//		cin >> w[i] >> c[i] >> p;
//		group[p].push_back(i);
//	}
//
//	long index;
//	for(long i=1;i<=t;++i)
//		for(long j=m;j>=1;--j)
//			for (long k = 0; k < group[i].size(); ++k)
//			{
//				index = group[i][k];
//				if (j >= w[index]) dp[j] = max(dp[j], dp[j - w[index]] + c[index]);
//			}
//
//	cout << dp[m] << endl;
//
//	return 0;
//}