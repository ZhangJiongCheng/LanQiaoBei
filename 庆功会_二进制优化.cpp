///*
// Ϊ����ذ༶��У�˶�����ȡ��ȫУ��һ���ĳɼ��������ξ�����һ���칦�ᣬ
// Ϊ�ˣ������Ʒ�����˶�Ա��ϣ������ȫ���ܹ�������ֵ�Ľ�Ʒ�����Բ������ǵ������;�����
//
// ���룺
// ��һ��������n,m�����У�n����ϣ������Ľ�Ʒ������,m��ʾ������.
// ������n��ÿ��������v,w,s���ֱ��ʾ��I�ֽ�Ʒ�ļ۸񡢼�ֵ���ܹ�������������
//
//�����
//һ������ʾ���˴��ܹ�������ļ�ֵ��
//
//����ʾ����
//5 1000
//80 20 4
//40 50 9
//30 50 7
//40 30 6
//20 20 1
//
//���ʾ����
//1040
//*/
//
//#include<iostream>
//using namespace std;
//
//long n, m;
//long price[5001], value[5001];
//long w, c, nums;
//long dp[6001];
//
//int main()
//{
//	cin >> n >> m;
//	long index = 1;
//	for (long i = 1; i <= n; ++i)
//	{
//		cin >> w >> c >> nums;
//		for (long j = 1; j <= nums; j <<= 1)
//		{
//			price[index] = j * w;
//			value[index] = j * c;
//			index++;
//			nums -= j;
//		}
//		if (nums)
//		{
//			price[index] = nums * w;
//			value[index] = nums * c;
//			index++;
//		}
//	}
//
//	for (long i = 1; i < index; ++i)
//		for (long j = m; j >= price[i]; --j)
//			dp[j] = max(dp[j], dp[j - price[i]] + value[i]);
//
//	cout << dp[m] << endl;
//
//	return 0;
//}