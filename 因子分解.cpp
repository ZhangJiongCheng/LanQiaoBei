///*
//输入一个数字，输出其素因子分解表达式。
//
//输入：
//输入一个整数n。
//
//输出：
//输出该整数的因子分解表达式。
//表达式中各个素数从小到大排列。
//如果该整数可以分解出因子a的b次方，当b大于1时写作a^b;当b=1时,则直接写成a
//
//输入样例：
//60
//
//输出样例：
//2^2*3*5
//*/
//#include<iostream>
//using namespace std;
//
//long n;
//bool flag = false;
//
////从div开始分解n,当前分解深度为dep,即已经分解出dep个div
//void f(long n, long div/*因子*/, long dep)
//{
//	if (n == 1)
//	{
//		if (flag) cout << "*";
//		if (dep >= 2) cout << div << "^" << dep;
//		else cout << div;
//		return;
//	}
//	if (n % div == 0)
//		f(n / div, div, dep + 1);
//	else
//	{
//		if (dep > 0)
//		{
//			if (flag) cout << "*";
//			flag = true;
//			if (dep >= 2) cout << div << "^" << dep;
//			else cout << div;
//		}
//
//		f(n, div + 1, 0);
//	}
//}
//
//int main()
//{
//	cin >> n;
//	f(n, 2, 0);
//	return 0;
//}