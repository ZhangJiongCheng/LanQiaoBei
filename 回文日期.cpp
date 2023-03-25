/*
题目描述
2020 年春节期间，有一个特殊的日期引起了大家的注意：2020 年 2 月 2 日。
因为如果将这个日期按 “yyyymmdd” 的格式写成一个 8 位数是 20200202，恰好是一个回文数。我们称这样的日期是回文日期。

有人表示 20200202 是 “千年一遇” 的特殊日子。对此小明很不认同，
因为不到 2 年之后就是下一个回文日期：20211202 即 2021 年 12 月 2 日。

也有人表示 20200202 并不仅仅是一个回文日期，还是一个 ABABBABA 型的回文日期。
对此小明也不认同，因为大约 100 年后就能遇到下一个 ABABBABA 型的回文日期：
21211212 即 2121 年 12 月 12 日。算不上 “千年一遇”，顶多算 “千年两遇”。

给定一个 8 位数的日期，请你计算该日期之后下一个回文日期和下一个 ABABBABA 型的回文日期各是哪一天。

输入描述
输入包含一个八位整数 N，表示日期。

对于所有评测用例，10000101 <= N <= 89991231，保证 N 是一个合法日期的 8 位数表示。

输出描述
输出两行，每行 1 个八位数。第一行表示下一个回文日期，第二行表示下一个 ABABBABA 型的回文日期。
*/

#include<iostream>
using namespace std;

bool is_leap(int n)
{
	return ((n % 4 == 0 && n % 100 != 0) || n % 400 == 0) ? true : false;
}

long get_next_day(long n)
{
	long y, m, d;
	d = n % 100;
	m = n % 10000 / 100;
	y = n / 10000;
	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
	{
		if (d < 31) d++;
		else
		{
			d = 1, m++;
			if (m == 13) m = 1, y++; 
		}
	}
	else if (m == 4 || m == 6 || m == 9 || m == 11)
	{
		if (d < 30) d++;
		else d = 1, m++; 
	}
	else //m==2
	{
		if (is_leap(y))
		{
			if (d < 29) d++;
			else m++, d = 1;
		}
		else
		{
			if (d < 28)  d++;
			else m++, d = 1;
		}
	}
	return y * 10000 + m * 100 + d;
}

int main()
{
	long n, h1, h2;
	long f[9];
	cin >> n;
	h1 = h2 = get_next_day(n);
	//先找出下一个回文日期 h1
	for (long i = h1; i <= 99991231; i = get_next_day(i))
	{
		f[1] = i / 10000000; f[2] = i / 1000000 % 10;
		f[3] = i / 100000 % 10; f[4] = i / 10000 % 10;
		f[5] = i / 1000 % 10; f[6] = i / 100 % 10;
		f[7] = i / 10 % 10; f[8] = i % 10;
		if (f[1] == f[8] && f[2] == f[7] && f[3] == f[6] && f[4] == f[5])
		{
			h1 = i;
			break;
		}
	}
	//再找出下一个ABABBABA 型的回文日期 h2
	for (long i = h2; i <= 99991231; i = get_next_day(i))
	{
		f[1] = i / 10000000; f[2] = i / 1000000 % 10;
		f[3] = i / 100000 % 10; f[4] = i / 10000 % 10;
		f[5] = i / 1000 % 10; f[6] = i / 100 % 10;
		f[7] = i / 10 % 10; f[8] = i % 10;
		if ((f[1] == f[8] && f[2] == f[7] && f[3] == f[6] && f[4] == f[5])
			&& (f[1] == f[3] && f[3] == f[6] && f[6] == f[8]) && (f[2] == f[4] && f[4] == f[5] && f[5] == f[7]))
		{
			h2 = i;
			break;
		}
	}
	cout << h1 << endl;
	cout << h2 << endl;
	return 0;
}

/*
//分析：是否合法（年月日）-->不合法，跳过
//                          -->合法--是否是闰年-->分解日期（装入数组）-->判断是否满足回文-->设置变量只打印下一个


#include<stdio.h>
int mon[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int arr[8]={0};
int year,month,day,j,flag=0,temp;
int legal()//判断是否合法
{
	if(year%400==0)
	  mon[1]=29;
	else
	  mon[1]=28;
	if(year<1000||year>9999||month<=0||month>12||day>mon[month])
	  return 0;
	return 1;
}
int main()
{
  int time;
  scanf("%d",&time);
  for(int i=time+1;i<=99991231;i++)
  {
	year=i/10000;
	month=i/100%100;
	day=i%100;
	if(!legal())
	  continue;
	j=0;temp=i;
	while(temp)
	{
		arr[j++]=temp%10;
		temp/=10;
	}
	if(arr[0]==arr[7]&&arr[1]==arr[6]&&arr[2]==arr[5]&&arr[3]==arr[4])
	{
		if(flag==0)
		{
			for(int t=0;t<8;t++)
			  printf("%d",arr[t]);
			printf("\n");
			flag=1;
		}
	  if(arr[0]==arr[2]&&arr[1]==arr[3])
		{
		  for(int t=0;t<8;t++)
			  printf("%d",arr[t]);
		  break;
	  }
	 }
  }
  return 0;
}
*/