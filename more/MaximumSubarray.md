**Maximum Subarray**  
Given an array of integers,  
find a contiguous subarray which has the largest sum.  

Example  
Given the array [−2,2,−3,4,−1,2,1,−5,3],  
the contiguous subarray [4,−1,2,1] has the largest sum = 6.

Note  
The subarray should contain at least one number.

Challenge  
Can you do it in time complexity O(n)?  

```
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std; 

/*  
动态规划：设状态f[j]记录以 S[j]为结尾的最大连续子序列和，则：
     f[j] = max { f[j - 1] + S[j], S[j]} ;   1<=j<=n  
     target = max { f[j]} ;   1<=j<=n
*/
int MaximumSubarray(vector<int>& nums) {
	int maxSub = INT_MIN,Sub= 0;
	for (auto a : nums) {
		Sub = max(Sub +a, a);
		maxSub = max(maxSub, Sub);
	}
	return maxSub;
}

//  max{ 前缀和 - 最小前缀和}
int MaximumSubarray_(vector<int>& nums) {
	int sum = 0, minsum = 0,maxSub = INT_MIN;
	for (auto a : nums) {		
		sum += a;
		maxSub = max( maxSub ,sum - minsum );
		minsum = std::min(minsum, sum);
	}
	return maxSub;
}

int main() {
	vector<int> nums = {-2, 2,-3, 4, -1, 2, 1,-5, 3 };
	std::cout << MaximumSubarray(nums) << std::endl;
	std::cout << MaximumSubarray_(nums) << std::endl;
	return 0;
}
```
//http://www.kancloud.cn/kancloud/data-structure-and-algorithm-notes/73086

