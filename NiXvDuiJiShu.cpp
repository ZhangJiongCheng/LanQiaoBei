///*
//������������
//
//���ڸ���������A������������Ե�����������
//
//image.png
//
//��������ʽ��
//
//�������1�����������
//
//һ����������ռһ�У���һ��������ʾ����ĳ��ȣ���������������еĸ�������Ԫ�أ��м䶼��һ���ո�ֿ���
//
//����ĳ��� l ��Χ 1<=l<=10^6
//
//ÿ������A[i]�ķ�ΧΪ  1<=A[i]<=2000
//
//�������ʽ��
//
//���һ����������ʾ����Եĸ�����
//
//���������롿
//5 1 2 3 5 4
//
//�����������
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
//    //���������������ɺ���Ҫ�����Խ�߽��������ж���
//    //����Ҫ����������������ݽ��й鲢��������������м����������
//    int* tem = new int[n + 1];
//    int i = 0;
//    int lp = left;
//    int rp = mid + 1;
//    ll num = 0;
//    while (lp <= mid && rp <= right)
//    {
//        if (a[lp] > a[rp])   //��a[lp]>a[rp]���������������lp��ʼ��ÿ��������a[rp]�γ��������
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

//�����Ƕ�̬�滮�㷨
#include <iostream>
using namespace std;

typedef long long ll;

const int N = 1e6 + 10;
int n;
int a[N];
int f[N];   //f[i]��ʾ��i������ǰ��i-1�����γɵ��������

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