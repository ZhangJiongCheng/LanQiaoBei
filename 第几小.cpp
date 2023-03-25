/*
问题描述
给定一个数组A=(a1,a2,⋯,an ), 请对该数组执行 m 次修改或查询操作:
若操作为1xy, 表示将ax的值修改为 y;

若操作为2lrp 表示求ap在 al,al+1,⋯,ar 中是第几小的（比ap小的元素个数加 1)。

输入格式
输入的第一行包含一个整数
n 。

第二行包含 n 个整数 a1,a2 ,⋯,an, 表示数组中每个数的初始值, 相邻的整数之间用一个空格分隔。

第三行包含一个整数 m 。

接下来 m 行每行包含一个操作, 可能是1xiyi​或
2liripi​, 相邻的整数之 间用一个空格分隔。

输出格式
输出一行, 包含多个整数, 相邻的整数之间用一个空格分隔, 依次表示第二种操作的答案。

样例输入
3
1 2 3

3
2 1 3 2
1 2 4
2 1 3 2

样例输出
2 3

评测用例规模与约定
对于 20% 的评测用例,n≤500 ；

对于 40% 的评测用例，n≤5000;

对于所有评测用例，1≤n≤100000,1≤m≤2n,1≤ai,yi​≤10^6, 1<=xi<=n, 1<=li<=pi<=ri<=n。
*/

#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>
using namespace std;
using namespace std::placeholders;

long n;
long a[100001];
long m;
vector<long> result;
long choice;
long x, y;
long l, r, p;

int main()
{
	cin >> n;
	for (long i = 1; i <= n; ++i)
		cin >> a[i];

	cin >> m;
	long temp;
	for (long i = 1; i <= m; ++i)
	{
		cin >> choice;
		if (choice == 1)  //修改
		{
			cin >> x >> y;
			a[x] = y;
		}
		else  //查询
		{
			cin >> l >> r >> p;
			temp = count_if(a + l, a + r + 1, bind(less<long>(), _1, a[p])) + 1;
			result.push_back(temp);
		}
	}
	for (const auto& elem : result)
		cout << elem << " ";
	cout << endl;
	return 0;
}