﻿///*
//题目描述
//蓝桥学院由 21​​​ 栋教学楼组成，教学楼编号 1​​ 到 21​​。对于两栋教学楼 a​ 和 b​，
//当 a​ 和b​ 互质时，a 和 b 之间有一条走廊直接相连，
//两个方向皆可通行，否则没有直接连接的走廊。
//
//小蓝现在在第一栋教学楼，他想要访问每栋教学楼正好一次，最终回到第一栋教学楼（即走一条哈密尔顿回路），
//请问他有多少种不同的访问方案？
// 
//两个访问方案不同是指存在某个 i，小蓝在两个访问方法中访问完教学楼 i 后访问了不同的教学楼。
//
//提示：建议使用计算机编程解决问题。
//
//答案提交
//这是一道结果填空的题，你只需要算出结果后提交即可。本题的结果为一个整数，在提交答案时只填写这个整数，
//填写多余的内容将无法得分。
//*/
//
//#include<iostream>
//using namespace std;
//
//typedef long long ll;
//
//const ll n = 1 << 21;
//ll f[n][21];   //f[i][j]表示当前状态为i,最后走到节点j时的方案数
//bool g[21][21];      //图
//
//int gcd(int a, int b)      //求a和b的最大公约数
//{
//	return b == 0 ? a : gcd(b, a % b);
//}
//
//int main()
//{
//	//构图
//	for (int i = 1; i <= 21; ++i)
//		for (int j = i + 1; j <= 21; ++j)
//			if (gcd(i, j) == 1)     //最大公约数为1， 即互质
//				g[i - 1][j - 1] = g[j - 1][i - 1] = 1;
//
//	//枚举状态，每个状态用一个21位的二进制数表示
//	f[1][0] = 1;   //f[1][0]表示在初始状态（即前面20位为0，最后一位为1）走到1号教学楼的方案数
//	for (ll i = 1; i < n; ++i)
//		for (int j = 0; j < 21; ++j)
//			if (i >> j & 1)  //在第i个状态下能够走到j顶点
//				for (int k = 0; k < 21; ++k)
//					if (g[j][k] && !(i >>  k & 1))   //j和k连通且在当前状态（i）下k未被走过
//						f[i | (1 << k)][k] += f[i][j];   //状态转移方程，关键
//
//	ll res = 0;
//  	for (int j = 0; j < 21; ++j)
//		res += f[n - 1][j];
//	cout << res << endl;           //881012367360
//
//	return 0;
//}