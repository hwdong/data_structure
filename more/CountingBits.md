Today ,someone ask a question about "Counting Bits" in QQ Group. I then wrote the following code after I observed the 规律。

```
/*
0   1      1   2     1     2           2    3     1     2    2    3    2  
0   1      10   11   100   101        110  111  1000  1001  1010 1011 1100   

The idea is similar to the compute of gray code: 计算长度按照1 ,2 ,4, 8递增。
后一遍的结果 是 前面的结果+1, 并累加到前面结果后面
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

He also give a code :
```
vector<int>  CountingBits_(const int num) {
	vector<int> res(num+1);
	for (int i = 0; i <= num; i++) {
		res[i] = res[i >> 1] + (i&1);
	}
	return res;
```
}
