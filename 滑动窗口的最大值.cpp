///*
//����һ������ͻ������ڵĴ�С���ҳ����л�����������ֵ�����ֵ��
//���磬�����������{2,3,4,2,6,2,5,1}���������ڵĴ�С3����ôһ������6���������ڣ�
//���ǵ����ֵ�ֱ�Ϊ{4,4,6,6,6,5}���������{2,3,4,2,6,2,5,1}�Ļ�������������6���� 
//{[2,3,4]��2��6��2��5��1}��{2��[3,4,2]��6��2��5��1}�� {2��3��[4,2,6]��2��5��1}�� 
//{2��3��4��[2,6,2]��5��1}��{2��3��4��2��[6,2,5]��1}�� {2��3��4��2��6��[2,5,1]}��
//
//����������
//8 3
//2 3 4 2 6 2 5 1
//
//���������
//4 4 6 6 6 5
//*/
//
///*
//���������ص㣺
//1. �����Ǵ��ڵ�������
//2. ���д������ҵ����ݼ�
//3. ���е�ͷԪ���Ǵ����ڵ����ֵ
//*/
//#include<iostream>
//#include<vector>
//#include<deque>
//using namespace std;
//
//int n, m;//n��Ԫ�أ����ڴ�СΪm
//vector<int> nums;
//
//vector<int> maxValueInWindow()
//{
//	int size = nums.size();
//
//	deque<int> de; //�������Ԫ�ص��±�
//	vector<int> ans;
//	for (int i = 0; i < size; ++i)
//	{
//		int l = i - m;      //���ڵ���Ԫ�ص�ǰһ��Ԫ�ص��±�
//		if (!de.empty() && de.front() == l) 
//			de.pop_front();
//		while (!de.empty() && nums[de.back()] <= nums[i]) 
//			de.pop_back();
//		de.push_back(i);
//
//		if (i >= m - 1)  ans.push_back(nums[de.front()]);
//	}
//	return ans;
//}
//
//int main()
//{
//	cin >> n >> m;
//	int temp;
//	for (int i = 1; i <= n; ++i)
//	{
//		cin >> temp;  
//		nums.push_back(temp);
//	}
//
//	vector<int> ans = maxValueInWindow();
//	for (auto v : ans)
//		cout << v << " ";
//	cout << endl;
//	return 0;
//}