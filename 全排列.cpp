///*
//����һ���ɲ�ͬ��Сд��ĸ��ɵ��ַ������������ַ���������ȫ���У�
//�������ַ����е���ĸ�Ѿ����մ�С�������С�
//
//���룺
//����һ���ɲ�ͬ��Сд��ĸ��ɵ��ַ�������֪�ַ����ĳ�����1��6֮�䡣
//
//�����
//�������ַ������������з�ʽ��ÿ��һ�����У�Ҫ����ĸ��Ƚ�С��������ǰ��
//
//����������
//abc
//
//�������:
//abc
//acb
//bac
//bca
//cab
//cba
//*/
//
//#include<iostream>
//using namespace std;
//
//string s;
//long n;
//bool visit[7];
//char ans[7];
//
//void dfs(long dep)
//{
//	if (dep == n + 1)
//	{
//		for (long i = 1; i <= n; ++i)
//			printf("%c", ans[i]);
//		cout << endl;
//		return;
//	}
//
//	for (long i = 0; i < n; ++i)
//	{
//		if (!visit[i])
//		{
//			visit[i] = 1;
//			ans[dep] = s[i];
//			dfs(dep + 1);
//			visit[i] = 0;
//		}
//	}
//}
//
//int main()
//{
//	cin >> s;
//	n = s.size();
//	dfs(1);
//
//	return 0;
//}