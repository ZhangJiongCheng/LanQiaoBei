///*
//����Ϊ����⣬ֻ��Ҫ���������ڴ�����ʹ�������佫������������ɡ�
//
//С��ѧϰ�����·��֮���ر���ˣ���������һ���ر��ͼ��ϣ���ҵ�ͼ �е����·����
//
//С����ͼ�� 2021 �������ɣ����α�� 1 �� 2021��
//
//����������ͬ�Ľ�� a, b����� a �� b �Ĳ�ľ���ֵ���� 21����������� 
//֮��û�б���������� a �� b �Ĳ�ľ���ֵС�ڵ��� 21����������֮����һ�� 
//����Ϊ a �� b ����С�������������������
//
//���磺��� 1 �ͽ�� 23 ֮��û�б���������� 3 �ͽ�� 24 ֮����һ���� ��ߣ�
//����Ϊ 24����� 15 �ͽ�� 25 ֮����һ������ߣ�����Ϊ 75��
//
//����㣬��� 1 �ͽ�� 2021 ֮������·�������Ƕ��١�
//
//��ʾ������ʹ�ü������̽�����⡣
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