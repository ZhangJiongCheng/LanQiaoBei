///*
// 在一个地图上有n个地窖，每个地窖中埋有一定数量的地雷。
// 同时给出地窖之间的连接路径，并规定路径都是单向的，
// 且保证都是小序号地窖指向大序号地窖，也不存在可以从一个地窖出发，
// 经过若干地窖后，又回到原来地窖的路径。
// 某人可以从任意一处开始挖地雷，然后沿着指出的连接往下挖，仅能选择一条路径，
// 当无连接时挖地雷工作结束。设计一个挖地雷的方案，使他能挖到最多的地雷。
//
// 输入
//第一行:地窖的个数，
//第二行:为每个地窖地雷的个数
//下面若干行:xi,yi     //表示从xi可到yi, xi小于yi
//最后一行为0 0表示结束
//
//输出
//k1 -k 2 -...... -kv，//挖地雷的顺序
//挖到最多的雷
//*/
//
///*
//输入
//6
//5 10 20 5 4 5
//1 2
//1 4
//2 4
//3 4
//4 5
//4 6
//5 6
//0 0
//
//输出
//3-4-5-6
//34
//*/
//
//#include<iostream>
//using namespace std;
//
//long n;
//long a[201];  //每个地窖的地雷数
//long b[201][201];  //地窖的邻接矩阵
//long dp[201];  //dp[i]表示从第i个地窖开始挖能挖到的最多的地雷数
//long nex[201];    //nex[i]表示第i个地窖的后继为第nex[i]个地窖
//
//int main()
//{
//	cin >> n;
//	for (long i = 1; i <= n; ++i)
//		cin >> a[i], dp[i] = a[i];
//
//	long x, y;
//	while (cin >> x >> y && x && y)
//		b[x][y] = 1;
//
//	long maxx = dp[n];
//	long maxIndex = n;
//	for (long i = n - 1; i >= 1; --i)
//	{
//		for (long j = i + 1; j <= n; ++j)
//		{
//			if (b[i][j] && dp[j] + a[i] > dp[i])
//				dp[i] = dp[j] + a[i], nex[i] = j;
//		}
//		if (dp[i] > maxx)
//			maxx = dp[i], maxIndex = i;
//	}
//	while (nex[maxIndex])
//	{
//		cout << maxIndex << "-";
//		maxIndex = nex[maxIndex];
//	}
//	cout << maxIndex << endl << maxx << endl;
//
//	return 0;
//}