///*
//һ����������һ�������װm����ı�����������n����Ʒ�����������ֱ�Ϊw1��w2,..., wn��
//���ǵļ�ֵ�ֱ�Ϊc1��c2,..., cn����Щ��Ʒ������Ϊ�����飬ÿ���е���Ʒ�����ͻ�����ѡһ����
//��⽫��Щ��Ʒװ�뱳������ʹ��Щ��Ʒ�ķ����ܶ���������������Ҽ�ֵ�ܺ����
//
//���룺
//��һ�� ����������m,n,t(t������)
//�ڶ���n+1�У�ÿ����������w,c,p,��ʾÿ����Ʒ������,��ֵ,������š�
//
//�����
//��һ�У�һ��������ʾ����ܼ�ֵ��
//
//����ʾ����
//10 6  3
//2  1  1
//3  3  1
//4  8  2
//6  9  2
//2  8  3
//3  9  3
//
//���ʾ����
//20
//*/
//
//#include<iostream>
//#include<vector>
//using namespace std;
//
//long m, n, t;
//long w[31], c[31];
//long dp[201];
//
//int main()
//{
//	cin >> m >> n >> t;
//
//	vector<vector<long>> group(t + 1);
//	long p;
//	for (long i = 1; i <= n; ++i)
//	{
//		cin >> w[i] >> c[i] >> p;
//		group[p].push_back(i);
//	}
//
//	long index;
//	for(long i=1;i<=t;++i)
//		for(long j=m;j>=1;--j)
//			for (long k = 0; k < group[i].size(); ++k)
//			{
//				index = group[i][k];
//				if (j >= w[index]) dp[j] = max(dp[j], dp[j - w[index]] + c[index]);
//			}
//
//	cout << dp[m] << endl;
//
//	return 0;
//}