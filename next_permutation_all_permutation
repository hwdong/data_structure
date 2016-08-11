**next_permutation**
  ![](http://img.blog.csdn.net/20131212235556093?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvbTY4MzAwOTg=/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)
  
```
  /*
1. Find the largest index k such that a[k] < a[k + 1]. If no such index exists, the permutation is the last permutation.
2. Find the largest index l such that a[k] < a[l]. Since k+1 is such an index, l is well defined and satisfies k < l.
3. Swap a[k] with a[l].
4. Reverse the sequence from a[k+1] up to and including the last element a[n].
*/

#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;
bool nextPermutation(vector<int> &a) {
	int len = a.size();
	int k = len - 2,l=len-1;
	while( k >= 0 && a[k] >= a[k + 1]) k--;
	if (k < 0) {
		reverse(a.begin(), a.end()); return false;
	}
	while(a[l]<=a[k]) l--;
	std::swap(a[k], a[l]);
	reverse(a.begin()+k+1,a.end());
	for (int i = 0; i < a.size(); i++) std::cout << a[i] << " "; std::cout << "\n";
	return true;
}

bool nextPermutation_(vector<int> &a) {
	vector<int>::reverse_iterator rfirst = a.rbegin();
	vector<int>::reverse_iterator rlast = a.rend();
	vector<int>::reverse_iterator pivot = next(rfirst);
	while (pivot != rlast && *pivot >= *prev(pivot)) ++pivot;
	if (pivot == rlast) {
		reverse(rfirst,rlast);
		return false;
	}
	vector<int>::reverse_iterator change = find_if(rfirst, pivot, bind1st(less<int>(), *pivot));
	std::swap(*pivot, *change);
	reverse(rfirst,pivot);
	for (auto value:a) std::cout << value << " "; std::cout << "\n";

	return true;
}

int main() {
	vector<int> a= { 1,2,3,4 };
	for (auto value : a) std::cout << value << " "; std::cout << "\n";
//	nextPermutation(a);
//	nextPermutation(a);
//	nextPermutation_(a);
//	nextPermutation_(a);
	while (nextPermutation(a));
	return 0;
}
```

We can also get all permution by  multiplication rule（乘法原理）  
![](http://img.blog.csdn.net/20131214161358218?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvbTY4MzAwOTg=/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

```
void AllPermutation(vector<int> &a, const int pos) {
	if (pos == a.size() - 1) {
		for (auto value : a) std::cout << value << " "; std::cout << "\n";
		return;
	}

	for (int i = pos; i < a.size(); i++) {
		swap(a[pos], a[i]); //select a[i] to pos location 
		AllPermutation(a, pos + 1);
		swap(a[pos], a[i]); //restore to the state before selecting a[i] as a[pos] 
	}
}
```
  
Refer to:
//http://blog.csdn.net/m6830098/article/details/17291259
