/*
问题描述
如果一个质数 P 的每位数字都是质数, 而且每两个相邻的数字组成的两位数是质数,
而且每三位相邻的数字组成的三位数是质数, 依次类推, 如果每相 邻的k 位数字组成的k 位数都是质数,
则P 称为超级质数。

如果把超级质数P 看成一个字符串, 则这个超级质数的每个子串都是质数。

例如, 53 是一个超级质数。

请问, 最大的超级质数是多少?

答案提交
这是一道结果填空的题, 你只需要算出结果后提交即可。本题的结果为一 个整数, 在提交答案时只填写这个整数, 填写多余的内容将无法得分。
*/

#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>
using namespace std;

vector<long> zichuan;  //存放所有子串
long ans = 0;

bool is_prime(const long& x)  //判读一个数是不是质数
{
	if (x <= 3)
		return x > 1;
	else if (x % 2 == 0) //3以上的偶数
		return false;
	else  //3以上的奇数
	{
		for (long i = 3; i <= sqrt(x); i += 2)
			if (x % i == 0) return false;
	}
	return true;
}

void get_zichuan(long x)   //获取x的所有子串
{
	zichuan.clear();
	//先将x的每一位进行分割
	vector<long> buf;
	while (x)
	{
		buf.push_back(x % 10);
		x /= 10;
	}
	reverse(buf.begin(), buf.end()); 

	//求所有子串
	for (long i = 0; i < buf.size(); ++i)   //i+1表示子串的长度
	{
		for (long j = 0; j < buf.size() - i; ++j)  //j+1表示长度为i+1的子串的个数
		{
			string tem;
			long k = 0;
			while (k <= i)   
			{
				tem += to_string(buf[j + k]);
				k++;
			}
			zichuan.push_back(stol(tem));
		}//for
	}
}

int main()
{
	for (long i = 2; i < 1e4; ++i)
	{
		if (is_prime(i))   //超级质数的前提是质数
		{
			//获取每一个子串，然后检查每一个子串
			get_zichuan(i);
			long j;
			for (j = 0; j < zichuan.size(); ++j)
			{
				if (!is_prime(zichuan[j])) break; 
			}
			if (j == zichuan.size()) ans = i;   //如果j == zichuan.size()，说明i的每一个子串都是质数
		}
	}
	cout << ans << endl;
	return 0;
}