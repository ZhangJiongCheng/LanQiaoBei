/*
��һ������n���������ɵģ���1����֪k�Ǽ���n��Ԫ�أ�
��2�����y��n��Ԫ�أ���ô2y+1��3y+1����n��Ԫ��;
(3) ����������������⣬û�б�����ܹ���Ϊn��һ��Ԫ��.
����:�������k��x�����ж�x�Ƿ���n��Ԫ�أ�
   �����k���޷�������,x������100000�������ֻ���YES���������NO

����:
��������k��x�����ż����

�����
����ǣ������YES���������NO.

����ʾ����
0,22

���ʾ����
YES
*/
#include<iostream>
using namespace std;

long k, x;

bool f(long k, long x)
{
	if (k > x) return false;
	if (k == x) return true;
	return f(2 * k + 1, x) || f(3 * k + 1, x);
}

int main()
{
	scanf_s("%d,%d", &k, &x);
	if (f(k, x)) cout << "YES" << endl;
	else cout << "NO" << endl;

	return 0;
}