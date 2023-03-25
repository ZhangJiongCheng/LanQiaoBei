/*
问题描述
A 市的车牌由六位组成, 其中前三位可能为数字 0 至 9 , 
或者字母 A 至 F, 每位有 16 种可能。后三位只能是数字 0 至 9。
为了减少攀比, 车牌中不能有连续三位是相同的字符。

例如, 202020 是合法的车牌, AAA202 不是合法的车牌, 因为前三个字母相同。

请问, A 市有多少个合法的车牌?
*/

#include<iostream>
using namespace std;

int main()
{
	long res = 0;
	for (int i1 = 0; i1 <= 15; ++i1)
		for (int i2 = 0; i2 <= 15; ++i2)
			for (int i3 = 0; i3 <= 15; ++i3)
			{
				if (i1 == i2 && i2 == i3) continue;
				for (int j1 = 0; j1 <= 9; ++j1)
				{
					if (i2 == i3 && i3 == j1) continue;
					for (int j2 = 0; j2 <= 9; ++j2)
					{
						if (i3 == j1 && j1 == j2) continue;
						for (int j3 = 0; j3 <= 9; ++j3)
						{
							if (j1 == j2 && j2 == j3) continue;
							res++;
						}
					}
				}
			}
	cout << res << endl;

	return 0; 
}