///*
// 为了庆贺班级在校运动会上取得全校第一名的成绩，班主任决定开一场庆功会，
// 为此，拨款购买奖品犒劳运动员。希望拨款全额能购买最大价值的奖品，可以补充他们的体力和精力。
//
// 输入：
// 第一行两个数n,m，其中，n代表希望购买的奖品的总数,m表示拨款金额.
// 接下来n行每行三个数v,w,s，分别表示第I种奖品的价格、价值和能购买的最大数量。
//
//输出：
//一个数表示，此次能购买的最大的价值。
//
//输入示例：
//5 1000
//80 20 4
//40 50 9
//30 50 7
//40 30 6
//20 20 1
//
//输出示例：
//1040
//*/
//
//#include<iostream>
//using namespace std;
//
//long n, m;
//long price[501], value[501], nums[501];
//long dp[6001];
//
//int main()
//{
//	cin >> n >> m;
//	for (long i = 1; i <= n; ++i)
//		cin >> price[i] >> value[i] >> nums[i];
//
//	for (long i = 1; i <= n; ++i)
//		for (long j = m; j >= 1; --j)
//			for (long k = 0; k <= nums[i]; ++k)
//				if (j >= k * price[i])
//					dp[j] = max(dp[j], dp[j - k * price[i]] + k * value[i]);
//
//	cout << dp[m] << endl;
//
//	return 0;
//}