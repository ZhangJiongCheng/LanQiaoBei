/*
数学老师给小明出了一道等差数列求和的题目。但是粗心的小明忘记了一 部分的数列，只记得其中 N 个整数。

现在给出这 N 个整数，小明想知道包含这 N 个整数的最短的等差数列有几项？*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<long> shulie;
	long data;
	int i;
	for (i = 0; i < n; ++i)    //输入n个数据
	{
		cin >> data;
		shulie.push_back(data);
	}

	sort(shulie.begin(), shulie.end());

	//找最小差距
	data = shulie[1] - shulie[0];
	for (i = 2; i < n; ++i)
	{
		if (shulie[i] - shulie[i - 1] < data)
			data = shulie[i + 1] - shulie[i];
	}
	
	if (data)
	{
		n = (shulie[n - 1] - shulie[0]) / data + 1;
		cout << n << endl;
	}
	else     //公差为0，第一次栽在这里，导致没完全通过
		cout << n << endl;
	

	return 0;
}