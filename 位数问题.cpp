///*
//�����е�nλ���У��ж��ٸ�������ż��������3,���ڽ�����ܴܺ�
//��ֻ��Ҫ�������𰸶� 12345 ȡ���ֵ
//
//���룺
// ����һ����n��
// 
// �����
// ����ж��ٸ�������ż��������3.
// 
// ����������
// 2
// 
// ���������
// 73
//*/
//
///*
//  �߽磺even[1]=0,odd[1]=1;
//  ���ƹ�ϵʽ��even[i]=9*even[i-1]+1*odd[i-1];
//	          odd[i]=1*even[i-1]+9*odd[i-1];
//  ���������λ����Ϊ0�����
//*/
//
//#include<iostream>
//using namespace std;
//
//const long mod = 12345;
//const long N = 1001;
//long even[N], odd[N];
////even[i]��ʾ����iλ���У���even[i]��������ż��������3
////odd[i]��ʾ����iλ���У���odd[i]������������������3
//long n;
//
//int main()
//{
//	cin >> n;
//	even[1] = 9, odd[1] = 1;
//	long times = 9;
//	for (long i = 2; i <= n; ++i)
//	{
//		if (i == n) times = 8;
//		even[i] = (times * even[i - 1] + odd[i - 1]) % mod;
//		odd[i] = (times * odd[i - 1] + even[i - 1]) % mod;
//	}
//	cout << even[n] << endl;
//
//	return 0;
//}