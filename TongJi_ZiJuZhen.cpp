///*
//给定一个N×M 的矩阵A, 请你统计有多少个子矩阵 (最小1×1, 最大N×M) 满足
//子矩阵中所有数的和不超过给定的整数K ?
//
//输入格式
//第一行包含三个整数N,M 和K.
//之后N 行每行包含M 个整数, 代表矩阵A.
//
//输出格式
//一个整数代表答案。
//
//样例输入
//3 4 10
//1 2 3 4
//5 6 7 8
//9 10 11 12
//
//样例输出
//19
//*/
//
//#include<iostream> 
//using namespace std;
//
//const int N = 505;
//int n, m, k;
//int s[N][N];
//
//int main()
//{
//	cin >> n >> m >> k;
//	for(int i = 1; i <= n; ++i)
//		for (int j = 1; j <= m; ++j)
//		{
//			cin >> s[i][j];
//			s[i][j] += s[i - 1][j];
//		}
//
//	long long res = 0;
//	for (int i = 1; i <= n; ++i)
//	{
//		for (int j = i; j <= n; ++j)
//		{
//			for (int l = 1, r = 1, sum = 0; r <= m; ++r)
//			{
//				sum += s[j][r] - s[i - 1][r];
//				while (sum > k)
//				{
//					sum -= s[j][l] - s[i - 1][l];
//					++l;
//				}
//				res += r - l + 1;
//			}
//		}
//	}
//	cout << res << endl;
//
//	return 0;
//}