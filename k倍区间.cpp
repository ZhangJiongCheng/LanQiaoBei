/*


　　给定一个长度为N的数列，A1, A2, ... AN，如果其中一段连续的子序列
  Ai, Ai+1, ... Aj(i <= j)之和是K的倍数，我们就称这个区间[i, j]是K倍区间。

　　你能求出数列中总共有多少个K倍区间吗？

输入格式
　　第一行包含两个整数N和K。(1 <= N, K <= 100000)
　　以下N行每行包含一个整数Ai。(1 <= Ai <= 100000)

输出格式
　　输出一个整数，代表K倍区间的数目。


　　例如，

输入格式

　　5 2
　　1
　　2
　　3
　　4
　　5

　　程序应该输出：
　　6
*/
/*
//本题用的是同余类的思想，倍数的题一般都可以用同余类来解决
#include<iostream> 
using namespace std;

const int N = 1e5 + 10;
long long cnt[N];   //cnt[i]=y表示有y个前缀和取余k等于i
int n, k;
long long ans = 0;

int main()
{
	cin >> n >> k;

	long long sum = 0;
	int num;
	cnt[0] = 1;    //取余k余数为0说明本身就是一个k被区间
	for (int i = 1; i <= n; ++i)
	{
		cin >> num;
		sum += num;

		ans += cnt[sum % k];
		cnt[sum % k]++;
	}
	cout << ans << endl;

	return 0;
}*/