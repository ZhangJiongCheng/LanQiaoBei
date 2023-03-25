///*
//问题描述
//今年是 2021 年, 2021 这个数字非常特殊, 它的千位和十位相等, 个位比 百位大 1 ，我们称满足这样条件的年份为特殊年份。
//
//输入 5 个年份, 请计算这里面有多少个特殊年份。
//
//输入格式
//输入 5 行, 每行一个 4 位十进制数 (数值范围为 1000 至 9999), 表示一个 年份。
//
//输出格式
//输出一个整数, 表示输入的 5 个年份中有多少个特殊年份。
//
//样例输入
//2019
//2021
//1920
//2120
//9899
//
//样例输出
//2
//*/
//
//#include <iostream>
//using namespace std;
//
//int main()
//{
//    string year;
//    int ans = 0;
//    for (int i = 1; i <= 5; ++i)
//    {
//        cin >> year;
//        if (year[0] == year[2] && year[3] - year[1] == 1)
//            ans++;
//    }
//    cout << ans << endl;
//
//    return 0;
//}