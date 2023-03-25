///*
//给定一个由不同的小写字母组成的字符串，输出这个字符串的所有全排列，
//给定的字符串中的字母已经按照从小到大排列。
//
//输入：
//输入一个由不同的小写字母组成的字符串，已知字符串的长度在1到6之间。
//
//输出：
//输出这个字符串的所有排列方式，每行一个排列，要求字母序比较小的排列在前面
//
//输入样例：
//abc
//
//输出样例:
//abc
//acb
//bac
//bca
//cab
//cba
//*/
//
//#include<iostream>
//using namespace std;
//
//string s;
//long n;
//bool visit[7];
//char ans[7];
//
//void dfs(long dep)
//{
//	if (dep == n + 1)
//	{
//		for (long i = 1; i <= n; ++i)
//			printf("%c", ans[i]);
//		cout << endl;
//		return;
//	}
//
//	for (long i = 0; i < n; ++i)
//	{
//		if (!visit[i])
//		{
//			visit[i] = 1;
//			ans[dep] = s[i];
//			dfs(dep + 1);
//			visit[i] = 0;
//		}
//	}
//}
//
//int main()
//{
//	cin >> s;
//	n = s.size();
//	dfs(1);
//
//	return 0;
//}