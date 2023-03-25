/*
动物王国中有三类动物A,B,C，这三类动物的食物链构成了有趣的环形。A吃B， B吃C，C吃A。
现有N个动物，以1－N编号。每个动物都是A,B,C中的一种，但是我们并不知道它到底是哪一种。
有人用两种说法对这N个动物所构成的食物链关系进行描述：
第一种说法是”1 X Y”，表示X和Y是同类。
第二种说法是”2 X Y”，表示X吃Y。
此人对N个动物，用上述两种说法，一句接一句地说出K句话，这K句话有的是真的，有的是假的。
当一句话满足下列三条之一时，这句话就是假话，否则就是真话。
1） 当前的话与前面的某些真的话冲突，就是假话；
2） 当前的话中X或Y比N大，就是假话；
3） 当前的话表示X吃X，就是假话。
你的任务是根据给定的N（1 <= N <= 50,000）和K句话（0 <= K <= 100,000），输出假话的总数。

Input第一行是两个整数N和K，以一个空格分隔。 
以下K行每行是三个正整数 D，X，Y，两数之间用一个空格隔开，其中D表示说法的种类。
若D=1，则表示X和Y是同类。
若D=2，则表示X吃Y。

Output只有一个整数，表示假话的数目。

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
int d[50005];  //d[x]表示x跟其父节点的关系

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
		if (D == 1) //x和y是同类
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
		else //D==2，x吃y
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