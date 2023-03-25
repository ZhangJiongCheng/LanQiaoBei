/*
�� N ����Ʒ��һ�������� V �ı�����

�� i ����Ʒ����� si ����ÿ������� vi����ֵ�� wi��

��⽫��Щ��Ʒװ�뱳������ʹ��Ʒ����ܺͲ����������������Ҽ�ֵ�ܺ����
�������ֵ��

�����ʽ
��һ������������N��V (0<N��1000, 0<V��20000)���ÿո�������ֱ��ʾ��Ʒ�����ͱ����ݻ���

�������� N �У�ÿ���������� vi,wi,si���ÿո�������ֱ��ʾ�� i ����Ʒ���������ֵ��������

�����ʽ
���һ����������ʾ����ֵ��

���ݷ�Χ
0<N��1000
0<V��20000
0<vi,wi,si��20000
��ʾ
���⿼����ر����ĵ��������Ż�������

��������
4 5
1 2 3
2 4 1
3 4 3
4 5 2
���������
10
*/

#include<iostream>
#include<cstring>
using namespace std;

const int N = 1005;
const int M = 20005;
int f[N], g[N];
int n, m;
int q[M];

int main()
{
	cin >> n >> m;

	for (int i = 1; i <= n; ++i)  //ö��n����Ʒ
	{
		int v, w, s;
		cin >> v >> w >> s;
		memcpy(g, f, sizeof(f));

		for (int j = 0; j < v; ++j)   //ö��v��ͬ����
		{
			int head = 0; 
			int tail = -1; 
			for (int k = j; k <= m; k += v)
			{
				//�����������ֵ��ͷԪ�س���
				if (head <= tail && k - q[head] > s * v) head++;
				//βԪ�س��ӣ�ά�ֵ�����  
				while (head <= tail && g[q[tail]] - (q[tail] - j) / v * w 
					<= g[k] - (k - j) / v * w)  
					tail--;
				//���
				q[++tail] = k;
				//��������ֵ
				if (head <= tail)
					f[k] = max(f[k], g[q[head]] + (k - q[head]) / v * w);
			}
		}
	}
	cout << f[m] << endl;

	return 0;
}