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
//long price[5001], value[5001];
//long w, c, nums;
//long dp[6001];
//
//int main()
//{
//	cin >> n >> m;
//	long index = 1;
//	for (long i = 1; i <= n; ++i)
//	{
//		cin >> w >> c >> nums;
//		for (long j = 1; j <= nums; j <<= 1)
//		{
//			price[index] = j * w;
//			value[index] = j * c;
//			index++;
//			nums -= j;
//		}
//		if (nums)
//		{
//			price[index] = nums * w;
//			value[index] = nums * c;
//			index++;
//		}
//	}
//
//	for (long i = 1; i < index; ++i)
//		for (long j = m; j >= price[i]; --j)
//			dp[j] = max(dp[j], dp[j - price[i]] + value[i]);
//
//	cout << dp[m] << endl;
//
//	return 0;
//}