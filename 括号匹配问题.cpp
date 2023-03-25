///*
//在某个字符串中有左括号、右括号和大小写字母，规定（与常见的算术式子一样）任何
//一个左括号都从内到外与在他右边且距离最近的右括号匹配。
//写一个程序，找到无法匹配的左括号和右括号，输出原来的字符，并
//在下一行标出不能匹配的括号，不能匹配的左括号用$标识，不能匹配的右括号用?标注.
//
//输入:
//输入包括多组数据，每组数据一行,包含一个字符串，只包含左右括号和大小写字母，
//长度不超过100。
//
//输出：
//对每组输出数据，输出两行，第一行包括原始输入字符，第二行由$,?和空格组成，
//$,?表示与之对应的左括号和右括号不能匹配
//
//输入示例:
//((ABCD(x)
//)(RTTYY())sss)(
//
//输出示例：
//((ABCD(x)
//$$
//)(RTTYY())sss)(
//?            ?$
//*/
//
//#include<iostream>
//#include<stack>
//#include<cstring>
//using namespace std;
//
//stack<long> sk;
//string s;
//char mark[101];
//
//void check(const string& s)
//{
//	for (long i = 0; i < s.size(); ++i)
//	{
//		if (s[i] == '(') sk.push(i);
//		else if (s[i] == ')')
//		{
//			if (!sk.empty())
//				sk.pop();
//			else
//				mark[i] = '?';
//		}
//	}
//
//	while (!sk.empty())
//	{
//		mark[sk.top()] = '$';
//		sk.pop();
//	}
//}
//
//int main()
//{
//	while (cin >> s)
//	{
//		memset(mark, 32, sizeof(mark));
//		check(s);
//		cout << s << endl;
//		for (long i = 0; i < s.size(); ++i)
//			cout << mark[i];
//		cout << endl;
//	}
//	return 0;
//}