/*
信息学院的同学小明毕业之后打算创业开餐馆，现在共有n个地点可选择，
小明打算从中选择合适的位置开设一些餐馆，这n个地点排列在同一条直线上，
我们用一个整数序列a1,a2 ,...,an,来表示它们的相对位置，
由于地段关系，开仓馆的利润会有所不同，我们用pi表示在ai处开餐馆的利润，
为了避免自己的餐馆的内部竞争，餐馆之间的距离必须大于m，
请你帮助小明选择一个总利润最大的方案

输入:
输入第一行是整数t,表示有t组测试数据，紧接着有t组连续的测试，每组测试数据有三行，
第一行地点总数n,距离限制k,
第二行n个地点的位置a1,a2,...,an,
第三行n个地点的仓管利润p1,p2,...,pn

输出:
对于每组测试数据输出可能的最大利润

输入示例;
2
3  11
1  2  15
10 2  30
3  16
1  2  15
10 2  30

输出示例：
40
30
*/

#include<iostream>
using namespace std;

long n, m, t;
long a[101], p[101];
long dp[101];

int main()
{
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		for (long i = 1; i <= n; ++i) cin >> a[i];
		for (long i = 1; i <= n; ++i) cin >> p[i], dp[i] = p[i];

		long maxx = dp[1];
		for (long i = 2; i <= n; ++i)
		{
			for (long j = 1; j < i; ++j)
				if (a[i] - a[j] > m) dp[i] = max(dp[i], dp[j] + p[i]);
			maxx = max(maxx, dp[i]);
		}

		cout << maxx << endl;
	}//while
	return 0;
}