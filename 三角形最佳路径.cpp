/*

*/
#include<iostream>
using namespace std;

long n;
long a[101][101];
long dp[010][101];

int main()
{
	cin >> n;
	for (long i = 1; i <= n; ++i)
		for (long j = 1; j <= i; ++j)
			cin >> a[i][j];

	long maxx = dp[1][1] = a[1][1];
	for (long i = 2; i <= n; ++i)
		for (long j = 1; j <= i; ++j)
		{
			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + a[i][j];
			maxx = max(maxx, dp[i][j]);
		}

	cout << maxx << endl;

	return 0;
}