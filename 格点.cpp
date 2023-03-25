/*
问题描述
如果一个点 (x, y)的两维坐标都是整数, 即 x∈Z 且 y∈Z, 则称这个点为 一个格点。

如果一个点 (x, y)的两维坐标都是正数, 即 x>0 且 y>0, 则称这个点在 第一象限。

请问在第一象限的格点中, 有多少个点 (x, y) 的两维坐标乘积不超过 2021 , 即 x⋅y≤2021 。

掟示: 建议使用计算机编程解决问题。
*/

#include<iostream>
using namespace std;

long res = 0;

int main()
{
	for(long x = 1; x <= 2021; ++x)
		for (long y = 1; y <= 2021; ++y)
		{
			if (x * y <= 2021) ++res;
			else break;
		}
	cout << res << endl;
	return 0;
}