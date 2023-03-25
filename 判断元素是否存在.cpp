/*
有一个集合n是这样生成的，（1）已知k是集合n的元素；
（2）如果y是n的元素，那么2y+1和3y+1都是n的元素;
(3) 除了上述二种情况外，没有别的数能够成为n的一个元素.
问题:任意给定k和x，请判断x是否是n的元素，
   这里的k是无符号整数,x不大于100000，如果是只输出YES，否则输出NO

输入:
输入整数k和x，逗号间隔。

输出：
如果是，则输出YES，否则输出NO.

输入示例：
0,22

输出示例：
YES
*/
#include<iostream>
using namespace std;

long k, x;

bool f(long k, long x)
{
	if (k > x) return false;
	if (k == x) return true;
	return f(2 * k + 1, x) || f(3 * k + 1, x);
}

int main()
{
	scanf_s("%d,%d", &k, &x);
	if (f(k, x)) cout << "YES" << endl;
	else cout << "NO" << endl;

	return 0;
}