/*
问题描述
给定 n,m, 求有多少个不同的序列 A 满足如下条件:
1. A 中有至少 1 个数、至多 n 个数, 且都是互不相同的正整数;
2. A 中所有元素的和恰好为 m;

3. 存在一个下标 k 使得对于 1<i≤k 有Ai−1 <Ai, 对于 k<i≤n 有Ai−1>Ai。

输入格式
输入一行包含两个整数 n,m, 中间用一个空格分隔。

输出格式
输出一行包含一个整数表示答案, 答案可能很大, 请输出答案除以 1000000007 的余数。

样例输入 1
2 3

样例输出 1
3

样例说明 1
A 可能为(3)、(1,2) 或 (2,1) 。

样例输入 2
10001 20223

样例输出 2
259920306

评测用例规模与约定
对于 25% 的评测用例，n,m≤10;

对于 50% 的评测用例, n,m≤300;

对于 75% 的评测用例, n,m≤5000;

对于所有评测用例, 1≤n,m≤100000 。
*/

#include<iostream>
#include<cstring>
using namespace std;

const long mod = 1e9 + 7;
long n, m;
long ans = 0;
bool visit[100001];

int main()
{
	cin >> n >> m;

	long sum;
	long count;
	ans = 1;   //长度为1只有一种情况
	for (long len = 2; len <= n; ++len)
	{
		for (long i = 1; i < m; ++i)
		{
			memset(visit, 0, sizeof(visit));
			visit[i] = true;
			sum = i;
			count = 1;

		}//for
		
		/*for (long i = 1; i <= len; ++i)
		{
			for (long j = 1;; ++j)
			{
				if (visit[j]) continue;

				visit[j] = true;
				sum += j;
				break;
			}
			if (sum > m) break;
			if (sum == m && i == len)
			{
				long temp = 1;
				for (long k = 2; k <= len; ++k)
					temp *= k;
				ans = (ans + temp) % mod;
			}
		}*/
	}

	cout << ans << endl;
	return 0;
}