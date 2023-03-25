///*
//pell数列a1,a2,a3的定义是这样的，a1=1,a2=2, ..., an=2a[n- 1]+a[n- 2]，
//给出一个正整数k，要求pell数列的第k项模上32767是多少？
//
//输入：
// 第一行是测试数据的组数n，后面跟着n行输入。
// 每组测试数据占一行，包括一个正整数k。
// 
//输出：
// n行，每行输出对应一个输入。输出应是一个非负整数。
// 
//输入样例：
//2
//1
//8
//
//输出样例：
//1
//408
//*/
//#include<iostream>
//using namespace std;
//
//const long mod = 32767;
//const long N = 1000001;
//long n, k;
//long long f[N];
//
//int main()
//{
//	f[1] = 1, f[2] = 2;
//	for (long i = 3; i < N; ++i)
//		f[i] = (2 * f[i - 1] + f[i - 2]) % mod;
//	cin >> n;
//	while (n--)
//	{
//		cin >> k;
//		cout << f[k] << endl;
//	}
//	return 0;
//}