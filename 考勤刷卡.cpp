﻿/*
问题描述
小蓝负责一个公司的考勤系统, 他每天都需要根据员工刷卡的情况来确定每个员工是否到岗。

当员工刷卡时, 会在后台留下一条记录, 包括刷卡的时间和员工编号, 只要在一天中员工刷过一次卡, 就认为他到岗了。

现在小蓝导出了一天中所有员工的刷卡记录, 请将所有到岗员工的员工编号列出。

输入格式
输入的第一行包含一个正整数n, 表示一天中所有员工的刷卡记录的条数。 
接下来n 行, 每行包含一条刷卡记录, 每条刷卡记录的格式为: HH:MM:SS ID

其中 HH:MM: SS 表示刷卡时间, HH 为一个 0 到 23 之间的两位十进制整数 (可能含前导 0 ) 表示时, 
MM 为一个 0 到 59 之间的两位十进制整数 (可能含前 导 0) 表示分, 
SS 为一个 0 到 59 之间的两位十进制整数 (可能含前导 0 ) 表 示秒, 
ID 为一个不含前导 0 的整数表示员工的编号。

所有记录按照刷卡时间升序排列, 可能同一时刻有多人刷卡。

输出格式
输出若干行, 每行包含一个整数, 按照从小到大的顺序输出, 表示到岗员 工的编号。

样例输入
4
13:05:42 103

14:07:12 4567

15:03:00 103

17:00:21 1

样例输出
1
103
4567
*/

#include<iostream>
#include<set>
using namespace std;

long n;
set<long> ID;

int main()
{
	cin >> n;
	string s;
	long id;
	for (long i = 1; i <= n; ++i)
	{
		cin >> s >> id;
		ID.emplace(id);
	}
	for (const auto& elem : ID)
		cout << elem << endl;
	return 0;
}