/*
���������������ද��A,B,C�������ද���ʳ������������Ȥ�Ļ��Ρ�A��B�� B��C��C��A��
����N�������1��N��š�ÿ�����ﶼ��A,B,C�е�һ�֣��������ǲ���֪������������һ�֡�
����������˵������N�����������ɵ�ʳ������ϵ����������
��һ��˵���ǡ�1 X Y������ʾX��Y��ͬ�ࡣ
�ڶ���˵���ǡ�2 X Y������ʾX��Y��
���˶�N���������������˵����һ���һ���˵��K�仰����K�仰�е�����ģ��е��Ǽٵġ�
��һ�仰������������֮һʱ����仰���Ǽٻ�����������滰��
1�� ��ǰ�Ļ���ǰ���ĳЩ��Ļ���ͻ�����Ǽٻ���
2�� ��ǰ�Ļ���X��Y��N�󣬾��Ǽٻ���
3�� ��ǰ�Ļ���ʾX��X�����Ǽٻ���
��������Ǹ��ݸ�����N��1 <= N <= 50,000����K�仰��0 <= K <= 100,000��������ٻ���������

Input��һ������������N��K����һ���ո�ָ��� 
����K��ÿ�������������� D��X��Y������֮����һ���ո����������D��ʾ˵�������ࡣ
��D=1�����ʾX��Y��ͬ�ࡣ
��D=2�����ʾX��Y��

Outputֻ��һ����������ʾ�ٻ�����Ŀ��

Sample Input
100 7
1 101 1
2 1 2
2 2 3
2 3 3
1 1 3
2 3 1
1 5 5
Sample Output
3 
*/

#include <iostream>
#include<algorithm>
using namespace std;

int n, k;
int father[50005];
int d[50005];  //d[x]��ʾx���丸�ڵ�Ĺ�ϵ

int mod(int x, int y)
{
	return (x % y + y) % y;
}

int find(int x)
{
	if (x == father[x]) return x;

	int root = find(father[x]);
	d[x] = mod(d[x] + d[father[x]], 3);
	father[x] = root;
	return father[x];
}

void merge(int x, int y, int t)
{
	int fx = find(x);
	int fy = find(y);
	d[fx] = mod(t + d[y] - d[x], 3);
	father[fx] = fy;
}

int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) father[i] = i;

	int ans = 0;
	for (int i = 1; i <= k; ++i)
	{
		int D, x, y;
		cin >> D >> x >> y;
		if (x > n || y > n)
		{
			ans++;
			continue;
		}
		if (D == 1) //x��y��ͬ��
		{
			int fx = find(x);
			int fy = find(y);
			if (fx == fy)
			{
				if (mod(d[x], 3) != mod(d[y], 3)) ans++;
			}
			else
				merge(x, y, 0);
		}
		else //D==2��x��y
		{
			if (x == y)
			{
				ans++;
				continue;
			}
			int fx = find(x);
			int fy = find(y);
			if (fx == fy)
			{
				if (mod(d[x] - d[y], 3) != 1) ans++;
			}
			else
				merge(x, y, 1);
		}
	}
	cout << ans << endl;

	return 0;
}