///*
//某国有一条横贯东西的大河，河有笔直的南北两岸，岸上各有位置各不相同的n个城市。
//北岸的每个城市有且仅有一个友好城市在南岸，而且不同城市的友好城市不同。
//每对友好城市都向政府申请在河上开辟一条直线航道连接两个城市，
//但是由于河上雾太大，政府决定避免任意两条航道交叉，以避免事故。
//编程帮助政府做出一些批准和拒绝申请的决定，
//使得在保证任意两条航线不相交的情况下，被批准的申请尽量多。
//
//输入:
//第一行，一个整数n，表示城市数量。
//第二行到第n+1行，每行两个整数，中间用一个空格隔开，
//分别表示南岸和北岸的一对友好城市的坐标。
//
//输出:
//仅一行，输出一个整数，表示政府所能批准的最多申请数。
//
//输入样例：
//7
//22 4
//2  6
//10 3
//15 12
//9  8
//17 17
//4  2
//
//输出样例：
//4
//*/
//
//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//struct friendCity
//{
//	long x, y;
//}a[5001];
//long n;
//long dp[5001];
//
//bool comp(const friendCity& a, const friendCity& b)
//{
//	return a.x < b.x;
//}
//
//int main()
//{
//	cin >> n;
//	for (long i = 1; i <= n; ++i)
//	{
//		cin >> a[i].x >> a[i].y;
//		dp[i] = 1;
//	}
//
//	sort(a + 1, a + n + 1, comp);
//
//	long maxx = 1;
//	for (long i = 2; i <= n; ++i)
//	{
//		for (long j = 1; j < i; ++j)
//		{
//			if (a[i].y > a[j].y)
//				dp[i] = max(dp[i], dp[j] + 1);
//		}
//		maxx = max(maxx, dp[i]);
//	}
//	cout << maxx << endl;
//
//	return 0;
//}