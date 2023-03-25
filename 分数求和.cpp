///*
//输入n个分数，并对他们求和，并用最简形式表示。所谓最简形式是指：
//分子分母的最大公约数为1，若最终结果的分母为1则直接用整数表示。
//如：5/6 、 10/3 均是最简形式， 而 3/6 需要化简为 1/2 ， 3/1 需要化简为 3。
//分子和分母均不为零，也不为负数。
//
//输入：
//第一行是一个整数n表示分数个数，
//接下来n行每行一个分数用 p/q 的形式表示,不含空格,p、q均不超过10.
//
//输出：
//输出只有一行，即最终结果的最简形式，若为分数用 p/q 的形式表示
//
//输入样例:
//2
//1/2
//1/3
//
//输出样例:
//5/6
//*/
//#include<iostream>
//using namespace std;
//
//long n, c, d;
//
//long gcd(long a, long b)
//{
//	if (b == 0) return a;
//	return gcd(b, a % b);
//}
//
//int main()
//{
//	cin >> n;
//	scanf_s("%d/%d", &c, &d);
//	n--;
//	long a, b;
//	while (n--)
//	{
//		scanf_s("%d/%d", &a, &b);
//		c = a * d + b * c;
//		d = b * d;
//
//		long temp = gcd(c, d);
//		c /= temp;
//		d /= temp;
//	}
//	if (d == 1) cout << c << endl;
//	else cout << c << "/" << d << endl;
//
//	return 0;
//}