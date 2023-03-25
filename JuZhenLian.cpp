///*
//矩阵链相乘
//*/
//#include <iostream>
//using namespace std;
//
//const int N = 55;
//
//int n;   //矩阵的个数
//int p[N];  //矩阵A1...n的输入向量为<p0,p1,p2...pn>
//int m[N][N];  //m[i][j]表示Ai...j相乘的结果
//
//int main()
//{
//    cin >> n;
//    for (int i = 0; i <= n; ++i)
//        cin >> p[i];
//
//    for (int len = 2; len <= n; ++len)  //枚举长度
//    {
//        for (int l = 1; l + len - 1 <= n; ++l)  //枚举左端点
//        {
//            int r = l + len - 1;
//            m[l][r] = m[l + 1][r] + p[l - 1] * p[l] * p[r];
//            for (int k = l + 1; k < r; ++k)  //枚举分界点
//            {
//                m[l][r] = min(m[l][r], m[l][k] + m[k + 1][r] + p[l - 1] * p[k] * p[r]);
//            }
//        }
//    }
//
//    cout << m[1][n] << endl;
//
//    return 0;
//}