/*
* 问题描述
小蓝国是一个水上王国, 有 2021 个城邦, 依次编号 1 到 2021。在任意两 个城邦之间,
都有一座桥直接连接。

为了庆祝小蓝国的传统节日, 小蓝国政府准备将一部分桥装饰起来。

对于编号为 a 和 b 的两个城邦, 它们之间的桥如果要装饰起来, 需要的费 用如下计算: 
找到 a 和 b 在十进制下所有不同的数位, 将数位上的数字求和。

例如, 编号为 2021 和 922 两个城邦之间, 千位、百位和个位都不同, 
将这 些数位上的数字加起来是 (2+0+1)+(0+9+2)=14。注意 922 没有千位, 千 位看成 0 。

为了节约开支, 小蓝国政府准备只装饰 2020 座桥, 并且要保证从任意一个 
城邦到任意另一个城邦之间可以完全只通过装饰的桥到达。

请问, 小蓝国政府至少要花多少费用才能完成装饰。

提示: 建议使用计算机编程解决问题。
*/

#include<iostream>
using namespace std;

/*
本题是要求最小生成树,图是完全图
*/
typedef struct
{
	long x, y, cost;   //分别表示边的两个顶点编号和边的费用
}edge;
typedef long long ll;
const ll M = 2021 * 2020 / 2;   //2021个顶点的完全图有2021*2020/2条边
edge e[M];
long father[2022];    //求最小生成树时，用于辅助避环，如果father[i]==father[j],说明i和j是同一个最小生成树的顶点
long ans = 0;    //装修的总费用

long fee(long x, long y)   //计算两城邦之间修桥的费用，x,y表示两城邦的编号
{
	long p = 0;   //费用
	long f1[5];
	long f2[5];
	for (long i = 4; i > 0; --i)
	{
		if (x) f1[i] = x % 10, x /= 10;
		else f1[i] = 0;
		if (y) f2[i] = y % 10, y /= 10;
		else f2[i] = 0;
	}
	for (long i = 1; i <= 4; ++i)
		if (f1[i] != f2[i]) p += (f1[i] + f2[i]);
	return p;
}

bool is_circle(long a, long b)   //判断a,b是否是同一个最小生成树的顶点
{
	return father[a] == father[b];
}

void mark(long a, long b)    //标记a，b为同一个最小生成树
{
	long tem = father[b];
	for (long i = 1; i <= 2021; ++i)
		if (father[i] == tem) father[i] = father[a];
}

int cmp(const void* p1, const void* p2)
{
	return (*(edge*)p1).cost - (*(edge*)p2).cost;
}

int main()
{
	long i;
	ll m = 0;
	for (i = 1; i <= 2020; ++i)     //记录下所有边
	{
		for (long j = i + 1; j <= 2021; ++j)
		{
			e[m].x = i;
			e[m].y = j;
			e[m].cost = fee(i, j);
			m++;
		}
	}

	qsort(e, m, sizeof(edge), cmp);

	for (i = 1; i <= 2021; ++i) father[i] = i;    //一开始，每个顶点都是独立的
	long n = 0;
	for (i = 0; i < m; ++i)
	{
		if (!is_circle(e[i].x, e[i].y))    //边的两个顶点不是同一个最小生成树
		{
			ans += e[i].cost;
			mark(e[i].x, e[i].y);
			n++;
			if (n == 2020) break;
		}
	}
	cout << ans << endl;

	return 0;
}