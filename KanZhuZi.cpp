﻿///*
//这天, 小明在砍竹子, 他面前有 n 棵竹子排成一排, 一开始第 i 棵竹子的 
//高度为hi.
//
//他觉得一棵一棵砍太慢了, 决定使用魔法来砍竹子。魔法可以对连续的一段相同高度的竹子使用, 
//假设这一段竹子的高度为 H, 那么
//
//用一次魔法可以 把这一段竹子的高度都变为sqrt(H/2+1)。小明 知道他最少使用多少次魔法可以
//让所有的竹子的高度都变为 1 。
//
//输入格式
//第一行为一个正整数 n, 表示竹子的棵数。
//
//第二行共 n 个空格分开的正整数hi表示每棵竹子的高度。
//
//输出格式
//一个整数表示答案。
//
//样例输入
//6
//2 1 4 2 6 7
//
//样例输出
//5
//
//样例说明
//其中一种方案：
//→214262
//→214222
//→211222
//→111222
//→111111
//​
//共需要 5 步完成
//*/
//#include <iostream>
//#include<cmath>
//using namespace std;
//
//typedef long long ll;
//
//const int N = 2e5 + 10;
//const int M = 10;
//
//int n, m;
//ll f[N][M];  //f[i][j]表示第i棵竹子第j层的高度
//
////可以先假设不存在连续的竹子等高，即每一棵竹子都只能一刀一刀砍，然后枚举每一层每一棵竹子，
////如果有连续的两棵竹子等高，就减少一刀
//
//int main()
//{
//    cin >> n;
//    
//    ll stk[M];
//    int top;
//    int res = 0;
//    for (int i = 1; i <= n; ++i)
//    {
//        ll h;
//        cin >> h;
//
//        top = 0;
//        while (h > 1) stk[++top] = h, h = sqrtl(h / 2 + 1);
//        res += top;
//        m = max(m, top);
//
//        for (int j = 1, k = top; k; ++j, --k)
//            f[i][j] = stk[k];
//    }  
//
//    for (int i = 1; i <= m; ++i)
//    {
//        for (int j = 2; j <= n; ++j)
//        {
//            if (f[j][i] && f[j][i] == f[j - 1][i])
//                res--;
//        }
//    }
//    cout << res << endl;
//
//    return 0;
//}