///*
//本题为填空题，只需要算出结果后，在代码中使用输出语句将所填结果输出即可。
//
//小蓝学习了最短路径之后特别高兴，他定义了一个特别的图，希望找到图 中的最短路径。
//
//小蓝的图由 2021 个结点组成，依次编号 1 至 2021。
//
//对于两个不同的结点 a, b，如果 a 和 b 的差的绝对值大于 21，则两个结点 
//之间没有边相连；如果 a 和 b 的差的绝对值小于等于 21，则两个点之间有一条 
//长度为 a 和 b 的最小公倍数的无向边相连。
//
//例如：结点 1 和结点 23 之间没有边相连；结点 3 和结点 24 之间有一条无 向边，
//长度为 24；结点 15 和结点 25 之间有一条无向边，长度为 75。
//
//请计算，结点 1 和结点 2021 之间的最短路径长度是多少。
//
//提示：建议使用计算机编程解决问题。
//*/
//
//#include <iostream>
//#include<cstring>
//using namespace std;
//
//int map[2022][2022];
//int path[2022];
//int dis[2022];
//
//int gcd(int a, int b)
//{
//    return b ? gcd(b, a % b) : a;
//}
//
//int lcm(int x, int y)
//{
//    return x * y / gcd(x, y);
//}
//
//void get_map()
//{
//    for (int i = 1; i < 2021; ++i)
//    {
//        for (int j = i + 1; j <= 2021; ++j)
//        {
//            if (abs(i - j) > 21)
//                map[i][j] = map[j][i] = 0x3f3f3f3f;
//            else
//                map[i][j] = map[j][i] = lcm(i, j);
//        }
//    }
//}
//
//void getShortestPath()
//{
//    int vis[2022];
//    memset(vis, 0, sizeof(vis));
//
//    for (int i = 1; i <= 2021; ++i)
//        dis[i] = map[1][i];
//    path[1] = -1;
//    vis[1] = 1;
//
//    for (int i = 1; i < 2021; ++i)
//    {
//        int minn = 0x3f3f3f3f;
//        int v = 0;
//        for (int j = 2; j <= 2021; ++j)
//        {
//            if (!vis[j] && dis[j] < minn)
//            {
//                minn = dis[j];
//                v = j;
//            }
//        }
//
//        vis[v] = 1;
//        for (int i = 2; i <= 2021; ++i)
//        {
//            if (!vis[i] && dis[v] + map[v][i] < dis[i])
//            {
//                dis[i] = dis[v] + map[v][i];
//                path[i] = v;
//            }
//        }
//    }
//}
//
//int main()
//{ 
//    get_map();
//    getShortestPath();
//    cout << dis[2021] << endl;
//
//    return 0;
//}