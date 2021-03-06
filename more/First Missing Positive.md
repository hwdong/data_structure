**First Missing Positive (第一个缺失的正整数)**

Given an unsorted integer array, find the first missing positive integer.
For example,  
Given [1,2,0] return 3,  
and [3,4,-1,1] return 2.  
Your algorithm should run in O(n) time and uses constant space.

例如3个元素的整数数组[1,2,0]如果没有缺失，应该是从第一个正整数1,然后2,3.  
4个元素的整数数组[3,4,-1,1]如果没有缺失，应该是从第一个正整数1,然后2,3,4.   
...   
一般的，如果有n个元素的数组，不缺失的话，从第一个正整数1开始，将包括1,2,3,...,n。即不缺失的话应该是由整数区间[1,n]的每一个数各出现一次。  

因此，不缺失的话，可以将正整数i放在第i个位置（下标为i-1），即A[i] = i+1 , (i=0,1,...,n-1).   
下面程序思路就是下标i的位置应该放正整数i+1或者说将正整数i+1放到下标位置i，对于不在范围[1,n]间的整数直接忽略。

```
int firstMissingPositive(vector<int>& nums) {
	int n = nums.size();
	// put num[i] in [1,n] in its location 
	for (int i = 0; i < n; i++)
		if (nums[i]<1 || nums[i]>n) continue;
		else {
			if (nums[i] != i + 1)
				swap(nums[nums[i] - 1], nums[i]);
		}
    //check if missing
	for (int i = 0; i <= n; i++)
		if (nums[i] != i + 1)
			return i + 1;
}
int main() {
	vector<int> nums= { 0,1,2,3 }; // 3,4,-1,1    //7,8,9,0

	std::cout << firstMissingPositive(nums) << std::endl;
	return 0;
}
```
