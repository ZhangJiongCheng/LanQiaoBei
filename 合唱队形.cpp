///*
//n位同学站成一排，音乐老师要请其中的n-k位同学出列，使得剩下的k位同学排成合唱队形。
//合唱队形是指这样的一种队形:设k位同学从左到右依次编号为1，2，......, k，
//他们的身高分别为T1,T2,....,Tk,则他们的身高满足T1<T2<,...,<Ti,Ti>Ti+1>,...,>TK，
//你的任务是，已知所有n位同学的身高，计算最少需要几位同学出列，可以使得剩下的同学排成合唱队形。
//
//输入:
//输入的第一行是一个整数n,表示同学的总数。
//第二行有n个整数，用空格分隔，第i个整数Ti是第i位同学的身高。
//
//输出:
//一个整数，就是最少需要几位同学出列。
//
//输入示例：
//8
//186 186 150 200 160 130 197 220
//
//输出示例：
//4
//*/
//
//#include<iostream>
//using namespace std;
//
//long n;
//long a[101];
//long dp_up[101], dp_down[101];
//
//int main()
//{
//	cin >> n;
//	for (long i = 1; i <= n; ++i)
//	{
//		cin >> a[i];
//		dp_up[i] = dp_down[i] = 1;
//	}
//
//	
//	for (long i = 2; i <= n; ++i)
//		for (long j = 1; j < i; ++j)
//			if (a[i] > a[j]) dp_up[i] = max(dp_up[i], dp_up[j] + 1);
//		
//	for (long i = n - 1; i >= 1; --i)
//		for (long j = n; j > i; --j)
//			if (a[i] > a[j]) dp_down[i] = max(dp_down[i], dp_down[j] + 1);
//
//	long maxx = 0;
//	for (long i = 1; i <= n; ++i)
//		maxx = max(maxx, dp_up[i] + dp_down[i] - 1);
//
//	cout << n - maxx << endl;
//
//	return 0;
//}