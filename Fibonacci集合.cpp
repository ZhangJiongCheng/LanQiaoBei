/*
问题描述
小蓝定义了一个 Fibonacci 集合 F, 集合的元素如下定义:

最小的 5 个 Fibonacci 数 1,2,3,5,8 属于集合 F 。

如果一个元素 x 属于 F, 则 3 x+2 、 5x+3 和 8 x+5 都属于集合 F 。

其他元素都不而于 F 。

请问，这个集合中的第 2020 小元素的值是多少?
*/

//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//vector<long> f{ 1,2,3,5,8 };
//
//int main()
//{
//	long i = 2, j = 1, k = 0;
//	long res;
//	for (long n = 6; n <= 2020; ++n)
//	{
//		long a3 = 3 * f[i] + 2;
//		long a5 = 5 * f[j] + 3;
//		long a8 = 8 * f[k] + 5;
//		res = min({ a3,a5,a8 });
//		f.push_back(res);
//		if (res == a3) ++i;
//		if (res == a5) ++j;
//		if (res == a8) ++k;
//	}
//	cout << res << endl;
//	
//	return 0;
//}


#include<iostream>
#include<set>
using namespace std;

set<long> f{ 1,2,3,5,8 };

int main()
{
	for (auto& elem : f)
	{
		f.insert({ 3 * elem + 2,5 * elem + 3,8 * elem + 5 });
		if (f.size() >= 2020 * 4) break;                          
		//为什么要2020*4，因为8x+5可能会大于5（x+1）+3 、 3（x+1）+2 、 5（x+2）+3 、 3（x+2）+2
		//所以如果只是2020，那么可能会出现第2020个数并不是集合里第2020小的
		//（因为5（x+1）+3 、 3（x+1）+2 、 5（x+2）+3 、 3（x+2）+2 可能会比第2020个小，但是还没被放到集合里）
	}
	long i = 1;
	set<long>::iterator iter;
	for (iter = f.begin(); i != 2020; ++i, ++iter);
	cout << *iter << endl;

	return 0;
}