**Missing Number**

Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

For example,  
Given nums = [0, 1, 3] return 2.

Note:  
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?

```
#include <vector>
#include <iostream>
using namespace std;

//time complexity O(n),space cmoplexityO(1)
int missingNumber(vector<int>& nums) {
	int sum = 0, n = nums.size();
	for (auto a:nums) {
		sum += a;
	}
	return n%2?(n+1)/2*n - sum: n/2*(n+1)-sum;	
}

//time complexity O(n),space cmoplexityO(1)
int missingNumber_(vector<int>& nums) {
	int res = 0;
	for (int i = 0; i < nums.size(); i++)
		res += i+1 - nums[i];
	return res;
}

//time complexity O(n),space cmoplexityO(1)
int missingNumber_2(vector<int>& nums) {
	int res = 0; 
	for (int i = 0; i < nums.size(); i++)
		res ^= (i + 1) ^ nums[i];
	return res;
}

//time complexity O(nlogn),space cmoplexityO(1)
#include <algorithm>
int missingNumber_3(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	int left = 0, right = nums.size();
	while (left < right) {
		int mid = left + (right - left) / 2;
		if (nums[mid] > mid) right = mid;
		else left = mid + 1;
	}
	return right;
}

//time complexity O(n),space cmoplexityO(n)
#include <unordered_map>
int missingNumber_4(vector<int>& nums) { 
	unordered_map<int, bool> map;
	for (auto a : nums)
		map[a] = true;
	int n = nums.size();
	for (int i = 0; i <= n; i++)
		if (map.find(i) == map.end())
			return i;
}

int main() {
	vector<int> nums= { 0,1,2,3 };
	std::cout << missingNumber(nums)<<std::endl;
	std::cout << missingNumber_(nums) << std::endl;
	std::cout << missingNumber_2(nums) << std::endl;
	std::cout << missingNumber_3(nums) << std::endl;
	std::cout << missingNumber_4(nums) << std::endl;
	return 0;
}
```

Refer to ://http://www.cnblogs.com/grandyang/p/4756677.html
