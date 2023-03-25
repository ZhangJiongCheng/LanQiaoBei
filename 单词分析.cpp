/*
题目描述
小蓝正在学习一门神奇的语言，这门语言中的单词都是由小写英文字母组 成，
有些单词很长，远远超过正常英文单词的长度。小蓝学了很长时间也记不住一些单词，
他准备不再完全记忆这些单词，而是根据单词中哪个字母出现得最多来分辨单词。

现在，请你帮助小蓝，给了一个单词后，帮助他找到出现最多的字母和这 个字母出现的次数。

输入描述
输入一行包含一个单词，单词只由小写英文字母组成。

对于所有的评测用例，输入的单词长度不超过 1000。

输出描述
输出两行，第一行包含一个英文字母，表示单词中出现得最多的字母是哪 个。如果有多个字母出现的次数相等，输出字典序最小的那个。

第二行包含一个整数，表示出现得最多的那个字母在单词中出现的次数。

输入输出样例
示例 1
输入

lanqiao
输出
a
2

示例 2
输入
longlonglongistoolong

输出
o
6
*/

#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

long w[26];

void statistic_chars(string& allChars, string& differentChars)  //统计电文有多少个不同的字符
{
	int i;
	int j;
	int n1 = allChars.length();
	int n2;
	for (i = 0; i < n1; ++i)   //对allChars的每个字符进行遍历
	{
		n2 = differentChars.length();
		for (j = 0; j < n2; ++j)       //查看allChars[i]是否在differentChars中
		{
			if (allChars[i] == differentChars[j]) break;
		}

		if (j == n2)   //differentChars中不存在allChars[i],将allChars[i]加入differentChars
			differentChars.append(1, allChars[i]);
	}
}

void count(string& allChars, string& differentChars)  //统计每个字符的权重
{
	int i;
	int j;
	int n1 = allChars.length();
	int n2 = differentChars.length();
	memset(w, 0, sizeof(w));

	for (i = 0; i < n1; ++i)   //统计每个字符出现的次数
	{
		for (j = 0; j < n2; ++j)
		{
			if (allChars[i] == differentChars[j])
			{
				++w[j];
				break;
			}
		}
	}     
}

int main()
{
	string s;
	string differentChars;
	cin >> s;
	statistic_chars(s, differentChars);
	sort(differentChars.begin(),differentChars.end());
	count(s, differentChars);

	long max_index = 0;
	for (int i = 0; i < differentChars.length(); ++i)
		if (w[i] > w[max_index]) max_index = i;

	cout << differentChars[max_index] << endl;
	cout << w[max_index] << endl; 
	return 0;
}

