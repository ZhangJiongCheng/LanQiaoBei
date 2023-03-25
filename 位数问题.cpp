///*
//在所有的n位数中，有多少个数中有偶数个数字3,由于结果可能很大，
//你只需要输出这个答案对 12345 取余的值
//
//输入：
// 输入一个数n。
// 
// 输出：
// 输出有多少个数中有偶数个数字3.
// 
// 输入样例：
// 2
// 
// 输出样例：
// 73
//*/
//
///*
//  边界：even[1]=0,odd[1]=1;
//  递推关系式：even[i]=9*even[i-1]+1*odd[i-1];
//	          odd[i]=1*even[i-1]+9*odd[i-1];
//  最后减掉最高位不能为0的情况
//*/
//
//#include<iostream>
//using namespace std;
//
//const long mod = 12345;
//const long N = 1001;
//long even[N], odd[N];
////even[i]表示所有i位数中，有even[i]个数中有偶数个数字3
////odd[i]表示所有i位数中，有odd[i]个数中有奇数个数字3
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