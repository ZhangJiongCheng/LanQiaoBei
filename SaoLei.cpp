///*
//问题描述
//小明最近迷上了一款名为《扫雷》的游戏。其中有一个关卡的任务如下, 在一个二维平面上放置着
//n 个炸雷, 第i 个炸雷(xi,yi,ri) 表示在坐标(xi,yi)处 存在一个炸雷, 它的爆炸范围是以半径为
//ri 的一个圆。
//
//为了顺利通过这片土地, 需要玩家进行排雷。玩家可以发射m 个排雷火 箭, 
//小明已经规划好了每个排雷火箭的发射方向, 第 j 个排雷火箭 (xj,yj,rj)表示这个排雷火箭将会在
//(xj,yj)处爆炸, 它的爆炸范围是以半径为rj的一个圆, 在其爆炸范围内的炸雷会被引爆。
//同时, 当炸雷被引爆时, 在其爆炸范围内的 炸雷也会被引爆。现在小明想知道他这次共引爆了几颗炸雷?
//
//你可以把炸雷和排雷火箭都视为平面上的一个点。一个点处可以存在多个炸雷和排雷火箭。
//当炸雷位于爆炸范围的边界上时也会被引爆。
//
//输入格式
//输入的第一行包含两个整数n、m.
//
//接下来的n 行, 每行三个整数, 表示一个炸雷的信息。
//
//再接下来的m 行, 每行三个整数 , 表示一个排雷火箭的信息。
//
//输出格式
//输出一个整数表示答案。
//
//样例输入
//2 1
//2 2 4
//4 4 2
//0 0 5
//
//样例输出
//2
//*/
//#include <iostream>
//#include<cstring>
//using namespace std;
//
//typedef long long LL;
//const int N = 5e4 + 10;
//const int M = 999997;
//struct node
//{
//    int x, y, r;
//}lei[N];
//LL h[M];      
//int id[M];       //id[t]=i表示第t号坑放的是第i号地雷
//bool vis[M];   //判断第i个坑是否被炸过
//int n, m;
// 
//LL get_key(int x, int y)   //获取哈希值
//{
//    return x * (LL)(1e9 + 1) + y;   //只需够乱即可
//}
//
//int find(int x, int y)   //找在哈希表中的坑
//{
//    LL key = get_key(x, y);
//    int t = (key % M + M) % M;
//
//    while (h[t] != -1 && h[t] != key)   //线性探测
//        if (++t == M)
//            t = 0;
//
//    return t;
//}
//
//int sqr(int x)
//{
//    return x * x;
//}
//
//void dfs(int x, int y, int r)
//{
//    vis[find(x, y)] = 1;
//
//    for (int i = x - r; i <= x + r; ++i)
//    {
//        for (int j = y - r; j <= y + r; ++j)
//        {
//            if (sqr(i - x) + sqr(j - y) <= sqr(r))
//            {
//                int t = find(i, j);
//                if (id[t] && !vis[t])
//                    dfs(i, j, lei[id[t]].r);
//            }
//        }
//    }
//}
//
//int main()
//{
//    cin >> n >> m;
//
//    memset(h, -1, sizeof(h));
//    for (int i = 1; i <= n; ++i)
//    {
//        int x, y, r;
//        cin >> x >> y >> r;
//        lei[i] = { x,y,r };
//
//        int t = find(x, y);
//        h[t] = get_key(x, y);
//
//        if (!id[t] || lei[id[t]].r < r)
//            id[t] = i;
//    }
//
//    while (m--)
//    {
//        int x, y, r;
//        cin >> x >> y >> r;
//        for (int i = x - r; i <= x + r; ++i)
//        {
//            for (int j = y - r; j <= y + r; ++j)
//            {
//                if (sqr(i - x) + sqr(j - y) <= sqr(r))
//                {
//                    int t = find(i, j);
//                    if (id[t] && !vis[t])
//                        dfs(i, j, lei[id[t]].r);
//                }
//            }
//        }
//    }
//
//    int res = 0;
//    for (int i = 1; i <= n; ++i)
//        res += vis[find(lei[i].x, lei[i].y)];
//
//    cout << res << endl;
//
//    return 0;
//}