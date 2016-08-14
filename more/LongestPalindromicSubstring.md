**Longest Palindromic Substring**  
Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.

Subscribe to see which companies asked this question

```
//以某个元素为中心，分别计算偶数长度的回文最大长度和奇数长度的回文最大长度。时间复杂度O(n ^ 2)，空间O（1）

string longestPalindrome(string s)
{
	const int len = s.size();
	if (len <= 1)return s;
	int start, maxLen = 0;
	for (int i = 1; i < len; i++)	{
		//寻找以i-1,i为中点偶数长度的回文
		int low = i - 1, high = i;
		while (low >= 0 && high < len && s[low] == s[high])	{
			low--;			high++;
		}
		if (high - low - 1 > maxLen)  {
			maxLen = high - low - 1;
			start = low + 1;
		}

		//寻找以i为中心的奇数长度的回文
		low = i - 1; high = i + 1;
		while (low >= 0 && high < len && s[low] == s[high])	{
			low--;			high++;
		}
		if (high - low - 1 > maxLen)	{
			maxLen = high - low - 1;
			start = low + 1;
		}
	}
	return s.substr(start, maxLen);
}


/*
动态规划：设状态f(i,j)表示区间[i,j]是否为回文，则有状态转移方程：
			  | true                      , j==i;
	 f(i,j) = | S[i]=S[j]                 , j==i+1;
			  | S[i]=S[j] && f(i+1,j-1)   , j>i+1;
*/
string longestPalindrome_(const string& s) {
	const int n = s.size();
	vector<vector<bool> > f(n, vector<bool>(n, false));
	int max_len = 1, start = 0; // 
	for (int i = n - 1; i >= 0; i--) {
		f[i][i] = true;
		for (size_t j = i + 1; j < n; j++) { // [i, j]
			f[i][j] = (s[j] == s[i] && (j - i < 2 || f[i + 1][j - 1]));
			if (f[i][j] && max_len < (j - i + 1)) {
				max_len = j - i + 1;
				start = i;
			}
		}
	}
	return s.substr(start, max_len);
}

int main_() {
	string S = "12212321";// "abccb";
	std::cout << longestPalindrome(S) << std::endl;
	std::cout << longestPalindrome_(S) << std::endl;
	return 0;
}
```
