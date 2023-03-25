/* /*
* leetcode 456
给你一个整数数组 nums ，数组中共有 n 个整数。132 模式的子序列 
由三个整数 nums[i]、nums[j] 和 nums[k] 组成，并同时满足：i < j < k 和
nums[i] < nums[k] < nums[j] 。

如果 nums 中存在 132 模式的子序列 ，返回 true ；否则，返回 false 。

示例 1：
输入：nums = [1,2,3,4]
输出：false
解释：序列中不存在 132 模式的子序列。

示例 2：
输入：nums = [3,1,4,2]
输出：true
解释：序列中有 1 个 132 模式的子序列： [1, 4, 2] 。

示例 3：
输入：nums = [-1,3,2,0]
输出：true
解释：序列中有 3 个 132 模式的的子序列：[-1, 3, 2]、[-1, 3, 0] 和 [-1, 2, 0] 。

提示：
n == nums.length
1 <= n <= 2 * 10^5
-10^9 <= nums[i] <= 10^9
*/
/*
#include<iostream> 
#include<vector>
#include<stack>
using namespace std;

vector<int> nums({ 3,1,4,2 });

bool have132orNot()
{
	stack<int> stk;
	int s3 = INT_MIN;  //s3存最大的a[k]
	for (int i = nums.size()- 1; ~i; --i)
	{
		if (nums[i] < s3) return true;
		while (!stk.empty() && nums[i] > stk.top())
		{
			s3 = stk.top();
			stk.pop();
		}
		stk.push(nums[i]);
	}
	return false;
}


int main()
{
	cout << have132orNot() << endl;

	return 0; 
} */