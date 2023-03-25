///*
//题目描述
//给定一个括号序列，要求尽可能少地添加若干括号使得括号序列变得合法，当添加完成后，
//会产生不同的添加结果，请问有多少种本质不同的添加结果。
//
//两个结果是本质不同的是指存在某个位置一个结果是左括号，而另一个是右括号。
//
//例如，对于括号序列 ((()，只需要添加两个括号就能让其合法，有以下几种不同的添加结果：
//()()()、()(())、(())()、(()()) 和 ((()))​。
//
//输入描述
//输入一行包含一个字符串 s，表示给定的括号序列，序列中只有左括号和右括号。
//
//输出描述
//输出一个整数表示答案，答案可能很大，请输出答案除以 1000000007(即 10^9 + 7)的余数。
//
//输入输出样例
//示例 1
//输入
//((()
//
//输出
//5
// */
//
///*
//可能出现三种情况：1.需要添加左括号    （）））
//                  2.需要添加右括号    （（（）
//                  3.需要添加左括号和右括号   ））（（
//            其中，情况1和情况2 是对称的，所以要求情况2，可以将字符串进行镜像对称，
//            然后用情况1的代码来解决，而情况3是情况1和情况2相乘的结果。
//
//            接下来，讨论情况1如何处理：
//            f[i][j]表示在第i个右括号前添加j个左括号的方案数，
//            前提条件为 j>=i-sum[i](sum[i]为原序列第i个右括号前的左括号数)
//            转移方程： f[i][j] = f[i-1][0]+f[i-1][1]+...+f[i-1][j]
//*/
//
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//
//const long M = 1e9 + 7;
//string s;         //读入括号序列
//long sum[5001];  //sum[i]为原序列第i个右括号前的左括号数
//long cnt1 = 0;    //需要添加cnt1个左括号
//long cnt2 = 0;    //需要添加cnt2个右括号
//long n = 0;     //右括号的个数
//long f[5001][5001];  //f[i][j]表示在第i个右括号前添加j个左括号的方案数
//long ne[5001];    //ne[j]表示f[i-1][0]+f[i-1][1]+....+f[i-1][j]的和
//
//long dp()
//{
//    long i, j, k;
//    memset(f, 0, sizeof(f));
//    //初始化
//    for (i = 1; i <= cnt1; ++i)
//        f[1][i] = 1;    //在第1个右括号前无论添加多少个左括号的方案数均为1
//    if (sum[1] > 0)
//        f[1][0] = 1;
//    for (i = 2; i <= n; ++i)  //将下面注释掉的三层for循环改成两层for循环，提高效率
//    {
//        ne[0] = f[i - 1][0];
//        for (k = 1; k <= cnt1; ++k)
//            ne[k] = (ne[k - 1] + f[i - 1][k]) % M;
//        for (j = max((long)0, i - sum[i]); j <= cnt1; ++j)
//            f[i][j] += ne[j];
//    }
//  /*  for (i = 2; i <= n; ++i)
//    {
//        for (j = max((long)0, i - sum[i]); j <= cnt1; ++j)
//        {
//            for (k = 0; k <= j; ++k)
//                f[i][j] = (f[i][j] + f[i - 1][k]) % M;
//        }
//    }*/
//
//    return f[n][cnt1];
//}
//
//int main()
//{
//    cin >> s;
//    long i;
//    long j = 1;
//    long l = 0, r = 0;
//    memset(sum, 0, sizeof(sum));
//    for (i = 0; i < s.length(); ++i)
//    {
//        if (s[i] == '(')   //进栈
//        {
//            cnt2++;
//            sum[j]++;
//        }
//        else
//        {
//            n++;
//            j++;
//            if (cnt2 == 0)
//                cnt1++;
//            else
//                cnt2--;
//        }
//    }
//    for (i = 1; i < j; ++i)
//        sum[i] += sum[i - 1];
//    if (cnt1 > 0)
//        l = dp();
//
//    //若需要添加右括号，则进行镜像对称，将求添加右括号的方案数改为求添加左括号的方案数
//    if (cnt2 > 0)  //若需要添加右括号
//    {
//        reverse(s.begin(), s.end());
//        for (i = 0; i < s.length(); ++i)
//        {
//            if (s[i] == '(')
//                s[i] = ')';
//            else
//                s[i] = '(';
//        }
//        n = s.length() - n;
//        cnt1 = cnt1 ^ cnt2;
//        cnt2 = cnt1 ^ cnt2;
//        cnt1 = cnt1 ^ cnt2;
//        memset(sum, 0, sizeof(sum));
//       
//        j = 1;
//        for (i = 0; i < s.length(); ++i)
//        {
//            if (s[i] == '(')   //进栈
//                sum[j]++;
//            else
//                j++;
//        }
//        for (i = 1; i < j; ++i)
//            sum[i] += sum[i - 1];
//        r = dp();
//    }
//
//    if (l && r)
//        cout << (l * r) % M << endl;
//    else if (l)
//        cout << l % M << endl;
//    else
//        cout << r % M << endl;
//     
//    return 0;
//}
//
////#include <iostream>
////#include<vector>
////using namespace std;
////#define N 1000000007
////long long func(string s) {
////    vector<long long> dd;
////    vector<vector<long long> > dp;
////    int i, j;
////    for (i = 0; i <= 1 + s.size(); i++) {
////        dd.push_back(0);
////    }
////    for (i = 0; i <= 1 + s.size(); i++) {
////        dp.push_back(dd);
////    }
////    dp[0][0] = 1;
////    for (i = 1; i <= s.size(); i++) {//对每个括号进行判断
////        if (s[i - 1] == '(') {
////            for (j = 1; j <= s.size(); j++) {
////                dp[i][j] = dp[i - 1][j - 1];
////            }
////        }
////        else {
////            dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % N;
////            for (j = 1; j <= s.size(); j++) {
////                dp[i][j] = (dp[i - 1][j + 1] + dp[i][j - 1]) % N;
////            }
////        }
////    }
////    for (i = s.size(); i >= 1; i--) {//等同于下面的代码，求添加左括号的方案数
////        if (s[i - 1] == ')' && dp[i][0] != 0)
////            return dp[i][0];
////    }
////    /*
////    for(int i=0;i<=len;i++)//len是括号序列的长度，求添加左括号的方案数
////        if(dp[len][i]!=0)
////            return dp[len][i];
////        return -1;
////    */
////    return 1;
////}
////int main(int argc, char** argv) {
////    string s;
////    cin >> s;
////    long long l = 0;
////    l = func(s);//求添加左括号的方案数
////    int i;
////    for (i = 0; i < s.size(); i++) {//将左括号变为右括号，右括号变为左括号
////        if (s[i] == '(')
////            s[i] = ')';
////        else
////            s[i] = '(';
////    }
////    reverse(s.begin(), s.end());//对括号序列翻转
////    long long r = func(s);//求添加右括号的方案数
////    cout << (l * r) % N;
////    return 0;
////}
//
////#include <iostream>
////#include <cstring>
////#include <algorithm>
////#include <string.h>
////
////using namespace std;
////
////typedef long long LL;
////
////const int N = 5010, MOD = 1e9 + 7;
////
////int n;
////char str[N];
////LL f[N][N];
////
////LL work()
////{
////    memset(f, 0, sizeof f);
////    f[0][0] = 1;
////    for (int i = 1; i <= n; i++)
////        if (str[i] == '(')
////        {
////            for (int j = 1; j <= n; j++)
////                f[i][j] = f[i - 1][j - 1];
////        }
////        else
////        {
////            f[i][0] = (f[i - 1][0] + f[i - 1][1]) % MOD;
////            for (int j = 1; j <= n; j++)
////                f[i][j] = (f[i - 1][j + 1] + f[i][j - 1]) % MOD;
////        }
////
////    for (int i = 0; i <= n; i++)
////        if (f[n][i])
////            return f[n][i];
////
////    return -1;
////}
////
////int main()
////{
////    cin >> str + 1;
////
////    n = strlen(str + 1);
////    LL l = work();
////    reverse(str + 1, str + n + 1);
////
////    for (auto& c : str)
////        if (c == '(')
////            c = ')';
////        else
////            c = '(';
////
////    LL r = work();
////
////    cout << l * r % MOD << endl;
////
////    return 0;
////}