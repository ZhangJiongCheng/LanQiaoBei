///*
//����һ�����֣�����������ӷֽ���ʽ��
//
//���룺
//����һ������n��
//
//�����
//��������������ӷֽ���ʽ��
//���ʽ�и���������С�������С�
//������������Էֽ������a��b�η�����b����1ʱд��a^b;��b=1ʱ,��ֱ��д��a
//
//����������
//60
//
//���������
//2^2*3*5
//*/
//#include<iostream>
//using namespace std;
//
//long n;
//bool flag = false;
//
////��div��ʼ�ֽ�n,��ǰ�ֽ����Ϊdep,���Ѿ��ֽ��dep��div
//void f(long n, long div/*����*/, long dep)
//{
//	if (n == 1)
//	{
//		if (flag) cout << "*";
//		if (dep >= 2) cout << div << "^" << dep;
//		else cout << div;
//		return;
//	}
//	if (n % div == 0)
//		f(n / div, div, dep + 1);
//	else
//	{
//		if (dep > 0)
//		{
//			if (flag) cout << "*";
//			flag = true;
//			if (dep >= 2) cout << div << "^" << dep;
//			else cout << div;
//		}
//
//		f(n, div + 1, 0);
//	}
//}
//
//int main()
//{
//	cin >> n;
//	f(n, 2, 0);
//	return 0;
//}