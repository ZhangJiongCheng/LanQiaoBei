///*
//逆波兰表达式是一种把运算符前置的算术表达式，例如普通的表达式
//2 + 3 的逆波兰表达式为 + 2 3 。逆波兰表达式的优点是运算轴之间不必有优先关系，
//也不必用括号改变运算测序，例如（2+3）* 4的逆波表达式为
//* + 2 3 4 。本题求解逆波兰表达式的值，其中运算符包括 + - / * 四个
//
//输入：
//输入为一行，其中运算符和运算符之间都用空格分隔，运算符是浮点数。
//
//输出：
//输出为一行，表达式的值。
//可直接用printf("%f\n", v)输出表达式的值v
//
//输入样例：
//* + 11.0 12.0 + 24.0 35.0
//
//输出样例：
//1357.000000
//*/
//
//#include<iostream>
//#include<string>
//using namespace std;
//
//double f()
//{
//	string s;
//	cin >> s;
//	switch (s[0])
//	{
//	case '+':
//		return f() + f();
//		break;
//	case '-':
//		return f() - f();
//		break;
//	case '*':
//		return f() * f();
//		break;
//	case '/':
//		return f() / f();
//		break;
//	default:
//		return stod(s);
//	}
//}
//
//int main()
//{
//	printf("%lf\n", f());
//	return 0;
//}