///*
// һ����������һ�������װm����ı�����������n����Ʒ�����ǵ������ֱ�Ϊw1��w2,..., wn��
// ���ǵļ�ֵ�ֱ�Ϊc1��c2,..., cn���е���Ʒֻ����ȡһ�Σ��е���Ʒ����ȡ���޴Σ�
// �е���Ʒ����ȡ�Ĵ�����һ�����ޣ�����Щ��Ʒװ�뱳����
// ��ʹ��Щ��Ʒ�ķ����ܺͲ����������������Ҽ�ֵ�ܺ����
//
//���룺
//��һ����������m��n��
//�ڶ��е�n+1��,ÿ����������W,C,P��ǰ���������ֱ��ʾÿ����Ʒ��������ֵ��
//������������Ϊ0����˵������Ʒ���Թ�������������Ϊ�������֣���Ϊ����Ʒ�ɹ����������.
//
//���:
//��һ��һ��������ʾ����ֵ�ܺ�.
//
//����ʾ����
//10 3
//2  1  0
//3  3  1
//4  5  4
//
//���ʾ����
//11
//*/
//
//#include<iostream>
//using namespace std;
//
//long n, m;
//long w[31], c[31], p[31];
//long price[201], value[201]; 
//bool type[201]; //�ж����������͵ı���
//long dp[201];
//
//int main()
//{
//	long index = 0;
//	cin >> m >> n;
//	for (long i = 1; i <= n; ++i)
//	{
//		cin >> w[i] >> c[i] >> p[i];
//		if (p[i] == 0) //��ȫ����
//		{
//			type[++index] = 1;
//			price[index] = w[i];
//			value[index] = c[i];
//		}
//		else if (p[i] == 1) //01����
//		{
//			//type[++index] = 0;
//			price[++index] = w[i];
//			value[index] = c[i];
//		}
//		else  //���ر���-�����Ʋ��
//		{
//			for (long j = 1; j <= p[i]; j <<= 1)
//			{
//				//type[++index] = 0;
//				price[++index] = j * w[i];
//				value[index] = j * c[i];
//				p[i] -= j;
//			}
//			if (p[i])
//			{
//				//type[++index] = 0;
//				price[++index] = p[i] * w[i];
//				value[i] = p[i] * c[i];
//			}
//		}//else
//	}//for
//
//	for (long i = 1; i <= index; ++i)
//	{
//		if (type[i] == 1) //��ȫ����
//		{
//			for (long j = price[i]; j <= m; ++j)
//				dp[j] = max(dp[j], dp[j - price[i]] + value[i]);
//		}
//		else  //01����
//		{
//			for (long j = m; j >= price[i]; --j)
//				dp[j] = max(dp[j], dp[j - price[i]] + value[i]);
//		}
//	}
//
//	cout << dp[m] << endl;
//
//	return 0;
//}