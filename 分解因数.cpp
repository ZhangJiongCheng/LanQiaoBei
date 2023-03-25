///*
//给出一个正整数a，要求分解成若干个正整数的乘积,即a=a1×a2×a3×,...,×an，
//并且1<a1<=a2<=a2<= ... <=an,问这样的分解的种数有多少
//注意: a=a也是一种分解。
//
//输入：
//第一行是测试数据的组数n，后面跟着n行输入。每组测试数据占一行，包括一个正整数a。
//
//输出：
// n行，每行输出对应一个输入，输出是一个正整数，指明满足要求的分解的种数
//
// 输入示例：
// 2
// 2 
// 20
//
// 输出示例：
// 1
// 4
//*/ 
//
//#include<iostream>
//using namespace std;
//
//long long ans;
//long n, a;
//
//void f(long a, long start) //从start开始分解a
//{
//	if (a <= start) return;
//	for (long i = start; i * i <= a; ++i)
//	{
//		if (a % i == 0)
//		{
//			ans++;
//			f(a / i, i);
//		}
//	}
//}
//
//int main()
//{
//	cin >> n;
//	while (n--)
//	{
//		cin >> a;
//		ans = 1;
//		f(a, 2);
//		cout << ans << endl;
//	}//while
//	return 0;
//}