///*
// 一个旅行者有一个最多能装m公斤的背包，现在有n件物品，它们的重量分别为w1，w2,..., wn，
// 他们的价值分别为c1，c2,..., cn，有的物品只可以取一次，有的物品可以取无限次，
// 有的物品可以取的次数有一个上限，求将哪些物品装入背包，
// 可使这些物品的费用总和不超过背包容量，且价值总和最大。
//
//输入：
//第一行两个整数m和n，
//第二行到n+1行,每行三个整数W,C,P，前两个整数分别表示每个物品的重量价值，
//第三个整数若为0，则说明此物品可以购买无数件，若为其他数字，则为此物品可购买的最多件数.
//
//输出:
//仅一行一个数，表示最大价值总和.
//
//输入示例：
//10 3
//2  1  0
//3  3  1
//4  5  4
//
//输出示例：
//11
//*/
//
//#include<iostream>
//using namespace std;
//
//long n, m;
//long w[31], c[31], p[31];
//long price[201], value[201]; 
//bool type[201]; //判断是哪种类型的背包
//long dp[201];
//
//int main()
//{
//	long index = 0;
//	cin >> m >> n;
//	for (long i = 1; i <= n; ++i)
//	{
//		cin >> w[i] >> c[i] >> p[i];
//		if (p[i] == 0) //完全背包
//		{
//			type[++index] = 1;
//			price[index] = w[i];
//			value[index] = c[i];
//		}
//		else if (p[i] == 1) //01背包
//		{
//			//type[++index] = 0;
//			price[++index] = w[i];
//			value[index] = c[i];
//		}
//		else  //多重背包-二进制拆分
//		{
//			for (long j = 1; j <= p[i]; j <<= 1)
//			{
//				//type[++index] = 0;
//				price[++index] = j * w[i];
//				value[index] = j * c[i];
//				p[i] -= j;
//			}
//			if (p[i])
//			{
//				//type[++index] = 0;
//				price[++index] = p[i] * w[i];
//				value[i] = p[i] * c[i];
//			}
//		}//else
//	}//for
//
//	for (long i = 1; i <= index; ++i)
//	{
//		if (type[i] == 1) //完全背包
//		{
//			for (long j = price[i]; j <= m; ++j)
//				dp[j] = max(dp[j], dp[j - price[i]] + value[i]);
//		}
//		else  //01背包
//		{
//			for (long j = m; j >= price[i]; --j)
//				dp[j] = max(dp[j], dp[j - price[i]] + value[i]);
//		}
//	}
//
//	cout << dp[m] << endl;
//
//	return 0;
//}