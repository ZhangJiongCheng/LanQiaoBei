/*
问题描述
在梦境中, 你䠖上了一只木筏, 在江上漂流。

根据对当㘿的了解，你知道在你下游 D 米处有一个㷋谷, 如果你向下游前进大干等于 D 米则必死无疑。

现在你打响了急救电话, T 秒后救抜䀒会到达并生你救上岸。水流速度是 1, 
你现在有 M 点体力。 每消耕一点体力, 你可以划一秒桨使船向上游前 进 1, 否则会向下游前进 1(水流)。
M 点体力需在救援队赴来前花光。因为 江面太宽了, 䣸借你自己的力量不可能上岸。

请问, 有多少种划奖的方案可以让你得救。

两个划桨方案不同是指; 存在某一秒铗, 一个方案划桨, 另一个方案不划。

输入格式
输入一行包含三个整数 D, T, M 。

输出格式
输出一个整数, 表示可以让你得救的总方案数, 答案可能很大, 请输出方案数除以 1,000,000,007 的余数。

样例输入
1 6 3

样例输出
5
*/

//#include<iostream>
//#include<cstring>
//using namespace std;
//
//const long M = 1e9 + 7;
//long f[3010][1510];     //f[T][M]表示第T秒时还有M点体力的方案数
//
//long dfs(long t, long m, long d)  //计算还有t秒，m点体力，离峡谷还有d米的方案数
//{
//	if (f[t][m] != -1) return f[t][m];
//	if (!t) 
//		if (m) return 0;    //体力没在t秒内花光
//		else return f[0][0];    
//
//	f[t][m] = 0;
//	if (m > 0)  f[t][m] = (f[t][m] + dfs(t - 1, m - 1, d + 1)) % M; 
//	if (d > 1) f[t][m] = (f[t][m] + dfs(t - 1, m, d - 1)) % M;
//
//	return f[t][m];
//}
//
//int main()
//{
//	long d, t, m;
//	cin >> d >> t >> m;
//
//	memset(f, -1, sizeof(f));
//	f[0][0] = 1;
//	cout << dfs(t, m, d) << endl;
//	return 0;
//}

#include<iostream>
using namespace std;

const long M = 1e9 + 7;
long f[3001][1501];   //f[i][j]表示i秒内用了j点体力还活着从方案数

int main()
{
	long d, t, m;
	cin >> d >> t >> m;
	f[0][0] = 1;
	for (long i = 1; i <= t; ++i)
	{
		if (i < d) f[i][0] = 1;
		for (long j = 1; j <= min(m, i); ++j)
		{
			long k = (i - j) - j;    //i秒内用了j点体力，会向下游前进(i-j)，会向上游前进j,所以k表示向下游前进的距离
			if (k >= d) continue;
			f[i][j] = (f[i - 1][j] + f[i - 1][j - 1]) % M;
		}
	}
	cout << f[t][m] << endl;
	return 0;
}