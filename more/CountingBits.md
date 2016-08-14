Today ,someone ask a question about "Counting Bits" in QQ Group.

**Counting Bits**
```
Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.   

Example:  
For num = 5 you should return [0,1,1,2,1,2].  

Follow up:  

It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?  
Space complexity should be O(n).   
Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.  
Show Hint    
```
I then wrote the following code after I observed the 规律。

```
/*
0   1      1   2     1     2           2    3     1     2    2    3    2  
0   1      10   11   100   101        110  111  1000  1001  1010 1011 1100   

The idea is similar to the computation of gray code: 计算长度按照1 ,2 ,4, 8递增。
后一遍的结果 是 前面的结果+1, 并累加到前面结果后面.   
时间复杂度为O(n)
*/
vector<int>  CountingBits(const int num) {
	vector<int> res;
	res.reserve(num+1);
	res.push_back(0);
	while (res.size() <= num) {
		int n = res.size();
		for (int j = 0; j<n&&res.size()<=num; j++)
			res.push_back(res[j] + 1);
	}
	return res;
}

void main_CountingBits() {
	int num = 19;
	vector<int> res = CountingBits(num);
	for (auto a : res)
		std::cout <<a<< " ";
	std::cout << "\n";
}
```

He also gives a code :
```
vector<int>  CountingBits_(const int num) {
	vector<int> res(num+1);
	for (int i = 0; i <= num; i++) {
		res[i] = res[i >> 1] + (i&1);
	}
	return res;
```
}
