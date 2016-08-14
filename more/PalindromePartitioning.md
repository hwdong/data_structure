**Palindrome Partitioning I**

Given a string s, partition s such that every substring of the partition is a palindrome.  
Return all possible palindrome partitioning of s.  
For example, given s = "aab",  
Return    
```
[
    ["aa","b"],
    ["a","a","b"]
  ]
```  

```
/*DFS深度递归： 对区间[pos,n]之间进行递归，
   1）先确定pos开头的第一个回文S[pos,i]；
   2）对于后续序列[i+1,n]重复这一过程
  第一个回文的结束为止可能是pos到n之间的任何一个位置i(pos<=i<=n),对于每个option(可能性)都要尝试一下
  */
  bool IsPalindrome(const string &str) {
	int low = 0, high = str.size() - 1;
	while (low <= high&&str[low] == str[high]) {
		low++; high--;
	}
	return low > high;
}
//对[pos,s.size()-1]之间进行DFS递归，partition记录从根深度前进过程中发现的每个回文（即一条完整的分割），直到到达叶子节点。
//所有深度路径上的回文序列都放入res中。
void PalindromePartitioning(string S, const int pos, vector<string> &partition,
	vector<vector<string>> &res) 
{
	if (pos == S.size()) {
		res.push_back(partition); return;
	}
	for (int i = pos; i < S.size(); i++) {
		string str = S.substr(pos, i - pos + 1);
		if (IsPalindrome(str)) {
			partition.push_back(str);
			PalindromePartitioning(S, i + 1, partition, res);
			partition.pop_back();
		}
	}
}

int main() {
	string S = "aab";// "abccb";
	vector<string> partition;
	vector<vector<string>> res;
	PalindromePartitioning(S,0,partition,res);
	for (auto partition : res) {
		for (auto str : partition) std::cout << str<< ", ";
		std::cout <<std::endl;
	}
	return 0;
}
```
解法2（动态规划）： 采用https://github.com/hwdong/data_structure/blob/master/more/LongestPalindromicSubstring.md的代码
  
