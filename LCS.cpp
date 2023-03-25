///*
//【问题描述】
//
//给定一个序列，如果其中有些元素(也可能没有)被省略，则我们可以得到该序列的一个子序列。
//给定一个序列X = <x1,x2...,xn> ，另一个序列Z满足条件，存在严格递增索引序列I=<i1,i2,...ik>,
//使得对于所有j = 1,2,…,k,Xij=Zj ，则称Z= <Z1,Z2,...,Zk>是X的子序列。
//例如，Z = <a, b, f, c>是X = <a, b, c, f, b, c>的子序列。
//
//给定两个序列X和Y，问题是求出X和Y的最大长度公共子序列的长度。
//
//【输入形式】
//两个给定字符串
//
//【输出形式】
//两个序列最大长度公共子序列的长度。
//
//【样例输入】
//abcfbc abfcab
//
//【样例输出】
//4
//*/
//
//#include <iostream>
//#include<string>
//using namespace std;
//
//const int N = 1e4 + 10;
//
//string s1, s2;
//int f[N][N];   //f[i][j]表示s1的前i个字符和s2的前j个字符的LCS的长度
//
//int main()
//{
//    cin >> s1 >> s2;
//    s1 = " " + s1;
//    s2 = " " + s2;
//
//    int n = s1.size();
//    int m = s2.size();
//    for (int i = 1; i < n; ++i)
//    {
//        for (int j = 1; j < m; ++j)
//        {
//            if (s1[i] == s2[j])
//                f[i][j] = f[i - 1][j - 1] + 1;
//            else
//                f[i][j] = max(f[i - 1][j], f[i][j - 1]);
//        }
//    }
//    cout << f[n - 1][m - 1] << endl;
//
//    return 0;
//}