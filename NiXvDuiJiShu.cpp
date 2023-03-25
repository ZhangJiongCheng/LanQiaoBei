///*
//【问题描述】
//
//对于给定的数组A，计算其逆序对的总数。即：
//
//image.png
//
//【输入形式】
//
//输入包含1组测试用例。
//
//一个测试用例占一行，第一个整数表示数组的长度，后面紧跟者数组中的各个整数元素，中间都用一个空格分开。
//
//数组的长度 l 范围 1<=l<=10^6
//
//每个数字A[i]的范围为  1<=A[i]<=2000
//
//【输出形式】
//
//输出一个整数，表示逆序对的个数。
//
//【样例输入】
//5 1 2 3 5 4
//
//【样例输出】
//1
//*/
//
//#include <iostream>
//using namespace std;
//
//
//typedef long long ll;
//
//const int N = 1e6 + 10;
//int a[N];
//int n;
//
//ll num_of_reverse_pair(int left, int right)
//{
//    if (left == right) return 0;
//
//    int mid = left + right >> 1;
//    ll num1 = num_of_reverse_pair(left, mid);
//    ll num2 = num_of_reverse_pair(mid + 1, right);
//
//    //两个子问题计算完成后，需要计算跨越边界的逆序对有多少
//    //这需要将两个子问题的数据进行归并排序并在排序过程中计算逆序对数
//    int* tem = new int[n + 1];
//    int i = 0;
//    int lp = left;
//    int rp = mid + 1;
//    ll num = 0;
//    while (lp <= mid && rp <= right)
//    {
//        if (a[lp] > a[rp])   //若a[lp]>a[rp]，则左边子序列自lp开始的每个数都跟a[rp]形成了逆序对
//        {
//            num += mid - lp + 1;
//            tem[i++] = a[rp++];
//        }
//        else
//        {
//            tem[i++] = a[lp++];
//        }
//    }
//    while (lp <= mid)
//        tem[i++] = a[lp++];
//    while (rp <= right)
//        tem[i++] = a[rp++];
//
//    for (int i = left; i <= right; ++i)
//        a[i] = tem[i - left];
//
//    delete[] tem;
//
//    return num + num1 + num2;
//}
//
//int main()
//{
//    cin >> n;
//    for (int i = 1; i <= n; ++i)
//        cin >> a[i];
//
//    ll ans = num_of_reverse_pair(1, n);
//    cout << ans << endl;
//
//    return 0;
//}

//下面是动态规划算法
#include <iostream>
using namespace std;

typedef long long ll;

const int N = 1e6 + 10;
int n;
int a[N];
int f[N];   //f[i]表示第i个数与前面i-1个数形成的逆序对数

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    ll ans = 0;
    for (int i = 2; i <= n; ++i)
    {
        for (int j = 1; j < i; ++j)
        {
            if (a[i] < a[j])
                f[i]++;
        }
        ans += f[i];
    }

    cout << ans << endl;

    return 0;
}