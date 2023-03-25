///*
//【问题描述】
//基本知识：二叉搜索树的定义及其查找。本题中二叉搜索树的结点都保存着字符串，
//大小关系由字典序定义。
//
//查找的过程中，查找效率取决于比较次数，比较的次数则取决于树的形状。
//要想减少查找的开销，就需要构造一棵树，使得较高频率被查找的字符串位于树的较高层次上以减小比较次数，
//对于较低频率被查找的字符串则放在较低的位置上。
//
//令n是字符串的数量，他们会被组织成一棵二叉搜索树。令K1…Kn是按照字典序排好顺序的n个字符串，
//p1...pn, q0...qn是2n+1个和为1的非负实数。其中表示pi待查找字符串s是Ki的概率。
//qi是待查找字符串s的字典序严格落在Ki和Ki+1之间的概率。其中q0表示s的字典序比K1小的概率。
//qn表示s字典序比Kn大的概率。
//
//我们想构造一棵二叉搜索树，包含n个结点，分别存储K1~Kn字符串，最小化期望的搜索代价。
//搜索代价定义如下：
//cost = pi*(1 +中间结点Ki的深度) + qi*(在Ki和Ki+1之间的叶结点深度)  （根结点深度为0）
//
//下面是一个例子
//
//image.png
//
//【输入形式】
//输入包含1个测试用例。每个测试用例首先是一个整数n (1<=n<=200)。
//接下来有2n+1个非负整数表示频数。令s是所有频数之和(1<=s<=1e6)。
//概率p1...pn和q0...qn是用频数/s表示的。注意数字之间可能是空格，也可能是换行。
//
//【输出形式】
//对每个测试用例构造一棵二叉搜索树使得期望搜索代价最小。输出一个整数，值为搜索代价*s。
//
//【样例输入】
//2
//20 15 15 25 25
//
//【样例输出】
//160
//*/
//
//
//#include <iostream>
//using namespace std;
//
//const int N = 210;
//int n;
//int P[2 * N];    //<a0,b1,a1,b2,...,bn,an>
//int w[N][N];  //w[i][j]表示a[i-1]+b[i]+a[i]+,...+b[j]+a[j]
//int m[N][N];  //m[i][j]表示<bi,...,bj>构成的子二分检索树的平均比较次数的最小值
//
//int main()
//{
//	cin >> n;
//	for (int i = 1, index = 1; i <= n; ++i, index += 2)
//	{
//		cin >> P[index];
//	}
//	for (int i = 0, index = 0; i <= n; ++i, index += 2)
//	{
//		cin >> P[index];
//	}
//	for (int i = 1; i <= 2 * n; ++i)
//	{
//		P[i] += P[i - 1];
//	}
//	
//	//统计w[i][j]
//	for (int i = 1; i <= n; ++i)
//	{
//		for (int j = i; j <= n; ++j)
//		{
//			if (i == 1)
//				w[i][j] = P[2 * j];
//			else
//				w[i][j] = P[2 * j] - P[2 * (i - 1) - 1];
//		}
//	}
//
//	//初始化m[i][j]
//	for (int i = 1; i <= n; ++i)
//	{
//		for (int j = i; j <= n; ++j)
//			m[i][j] = 0x3f3f3f3f;
//	}
//
//	for (int len = 1; len <= n; ++len)
//	{
//		for (int i = 1; i + len - 1 <= n; ++i)
//		{
//			int j = i + len - 1;
//			for (int k = i; k <= j; ++k)
//			{
//				m[i][j] = min(m[i][j], m[i][k - 1] + m[k + 1][j] + w[i][j]);
//			}
//
//		}
//	}
//	cout << m[1][n] << endl;
//
//	return 0;
//}