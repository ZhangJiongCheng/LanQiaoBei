///*
//���������
//*/
//#include <iostream>
//using namespace std;
//
//const int N = 55;
//
//int n;   //����ĸ���
//int p[N];  //����A1...n����������Ϊ<p0,p1,p2...pn>
//int m[N][N];  //m[i][j]��ʾAi...j��˵Ľ��
//
//int main()
//{
//    cin >> n;
//    for (int i = 0; i <= n; ++i)
//        cin >> p[i];
//
//    for (int len = 2; len <= n; ++len)  //ö�ٳ���
//    {
//        for (int l = 1; l + len - 1 <= n; ++l)  //ö����˵�
//        {
//            int r = l + len - 1;
//            m[l][r] = m[l + 1][r] + p[l - 1] * p[l] * p[r];
//            for (int k = l + 1; k < r; ++k)  //ö�ٷֽ��
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