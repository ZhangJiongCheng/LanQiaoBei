///*
//����һ��n����ֵ�Ļ���ϵͳ���������ֵΪm�Ļ����ж����ַ�����
//
//����:
//��һ��Ϊn��m.
//������n�У�ÿ��һ��������ʾ��ֵ��
//
//���:
//һ��,������.
//
//����ʾ����
//3  10
//1
//2
//5
//
//���ʾ����
//10
//*/
//
//#include<iostream>
//#include<vector>
//using namespace std;
//
//long m, n;
//long long a[10001];
//long long dp[10001];
//
//int main()
//{
//	cin >> n >> m;
//	for (long i = 1; i <= n; ++i) cin >> a[i];
//
//	dp[0] = 1;
//	for (long i = 1; i <= n; ++i)
//		for (long j = 1; j <= m; ++j)
//			if (j >= a[i]) dp[j] = dp[j] + dp[j - a[i]];
//
//	cout << dp[m] << endl;
//
//	return 0;
//}