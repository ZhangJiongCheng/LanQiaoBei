///*
//潜水员为了潜水要使用特殊的设备。他有一个带2种气体的气缸：
//一个为氧气，一个为氮气。让潜水员下潜的深度需要各种数量的氧和氮。
//潜水员有一定数量的气缸，每个气缸都有重量和气体容量。
//潜水员为了完成它的功工作，需要特定数量的氧和氮。
//他完成工作所需气缸的总重的最低限度是多少？
//
//例如，潜水员有5个气缸，每行三个数字为 氧，氮的量和气缸的重量：
//3  36 120
//10 25 129
//5  50 250
//1  45 130
//4  20 119
//
//如果潜水员需要5升的氧和60升的氮，则总重量最小为249（1,2或者4,5号气缸）。
//
//你的任务就是计算潜水员为了完成他的工作，需要的气缸的重量的最低值。
//
//
//输入：
//第一行有两个整数m，n，他们表示氧氮各自需要的量。
//第二行为整数t表示气缸的个数。
//此后的t行，每行包括a,b,c三个整数，这些是第i个气缸里的氧和氮的容量及气缸重量
//
//
//输出:
//仅一行一个整数,为潜水员完成工作所需的气缸的重量总和的最低值.
//
//输入示例：
//5  60
//5
//3  36 120
//10 25 129
//5  50 250 
//1  45 130
//4  20 119
//
//输出示例：
//249
//*/
//
//#include<iostream>
//#include<cstring>
//using namespace std;
//
//long m, n, t;
//long O[1001], N[1001], weight[1001];
//long dp[1001][1001];
//
//int main()
//{
//	cin >> m >> n;
//	cin >> t;
//	for(long i = 1; i <= t; ++i)
//		cin >> O[i] >> N[i] >> weight[i];
//	
//	memset(dp, 0x3f, sizeof(dp));
//
//	long x, y;
//	for (long i = 1; i <= t; ++i)
//		for (long j = m; j >= 0; --j)
//			for (long k = n; k >= 0; --k)
//				if (O[i] >= j && N[i] >= k) dp[j][k] = min(dp[j][k], weight[i]);
//				else
//				{
//					x = j < O[i] ? 0:j - O[i];
//					y = k < N[i] ? 0 : k - N[i];
//					dp[j][k] = min(dp[j][k], dp[x][y] + weight[i]);
//				}
//
//	cout << dp[m][n] << endl;
//
//	return 0;
//} 