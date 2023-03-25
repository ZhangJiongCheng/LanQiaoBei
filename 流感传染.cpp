///*
//有一批易感人群住在网格状的宿舍区内，宿舍区为n*n的矩阵，
//每个格点为一个房间，房间里可能住人，也可能空着.
//在第一天,有些房间里的人得了流感，以后每天得流感的人会使其邻居传染上流感，
//已经得病的不变，空房间不会传染，请输出第m天得流感的人数.
//
//输入:
// 第一行一个数字n，表示有n*n的宿舍房间，
// 接下来的n行，每行n个字符，'.'表示第一天该房间住着健康的人，‘#’表示该房间空着，
//  ‘@’表示第一天该房间住着得流感的人。
// 接下来的一行是一个整数m.
//
//输出:
// 输出第m天得流感的人数
//
//输入样例:
//5
//....#
//.#.@.
//.#@..
//#....
//.....
//4
//
//输出样例:
//16
//*/
//
//#include<iostream>
//using namespace std;
//
//long n,m;
//long long ans = 0;
//char a[101][101], b[101][101];
//
//long dx[] = { 0,0,-1,1 };
//long dy[] = { 1,-1,0,0 };
//
//int main()
//{
//	cin >> n;
//	for (long i = 0; i < n; ++i)
//		for (long j = 0; j < n; ++j)
//			cin >> a[i][j], b[i][j] = a[i][j];
//	cin >> m;
//
//	for (long k = 2; k <= m; ++k)
//	{
//		for (long i = 0; i < n; ++i)
//		{
//			for (long j = 0; j < n; ++j)
//			{
//				if (a[i][j] == '@')
//				{
//					for (long index = 0; index < 4; ++index)
//					{
//						long bx = i + dx[index];
//						long by = j + dy[index];
//						if (bx >= 0 && bx < n && by >= 0 && by < n && b[bx][by] == '.')
//							b[bx][by] = '@';
//					}
//				}
//			}//for j
//		}//for i
//		for (long i = 0; i < n; ++i)
//			for (long j = 0; j < n; ++j)
//				a[i][j] = b[i][j];
//	}//for k
//
//	for (long i = 0; i < n; ++i)
//		for (long j = 0; j < n; ++j)
//			if (a[i][j] == '@') ans++;
//
//	cout << ans << endl;
//
//	return 0;
//}