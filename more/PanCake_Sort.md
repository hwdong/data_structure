**PanCake_Sort （一摞烙饼的排序问题）**
http://www.geeksforgeeks.org/pancake-sorting/

Given an an unsorted array, sort the given array. You are allowed to do only following operation on array.

flip(arr, i): Reverse array from 0 to i   
Unlike a traditional sorting algorithm, which attempts to sort with the fewest comparisons possible, the goal is to sort the sequence in as few reversals as possible.

The idea is to do something similar to Selection Sort. We one by one place maximum element at the end and reduce the size of current array by one.

Following are the detailed steps. Let given array be arr[] and size of array be n.  
1) Start from current size equal to n and reduce current size by one while it’s greater than 1. Let the current size be curr_size. Do following for every curr_size

……a) Find index of the maximum element in arr[0..curr_szie-1]. Let the index be ‘mi’  
……b) Call flip(arr, mi)  
……c) Call flip(arr, curr_size-1)  

See following video for visualization of the above algorithm.  

http://www.youtube.com/embed/kk-_DDgoXfk

*简单排序*：

找出N个数种最大者，将这通过**两次**翻转放置到最底部，然后处理N-1，N-2等，直到全部排序完，所以一共需要交换2（N-1）次

```
void reverse(int cakes[], int beg, int end)
{
    int temp;
    while(beg < end){
        temp = cakes[beg];
        cakes[beg++] = cakes[end];
        cakes[end--] = temp;
    }
}
void cake_sort(int cakes[], int n)
{
    int ith, max_idx, cur_max, idx;
    for(ith=n-1; ith>=1; --ith)
    {
       cur_max = cakes[0];
       max_idx = 0;
       //目的找到目前最大的那个饼
        for(idx=1; idx<=ith; ++idx)
        {
            if(cakes[idx] > cur_max){
                cur_max = cakes[idx];
                max_idx = idx;
            }
        }
       if(max_idx != ith){
            reverse(cakes, 0, max_idx);
            reverse(cakes, 0, ith);
        }
     }
}
```

上述方法得到的不一定是最优解（翻转次数最少的），可以用
```
*穷举法+剪枝*，从所有可能的方案中选择最优解（翻转次数最少的）。因为翻转都是顶部煎饼(0)和其余的某个煎饼(i=1,2,...,n-1)进行翻转，我们可以用DFS搜索枚举每一步（ Search(step）)的这n-1次翻转，即step=0表示进行第一次翻转，在这基础上进行step=1即第二次翻转，...如此进行下去，直到排好序，最后的step就是这一翻转方案需要的次数。程序中的m_nSearch记录所有穷举探索中的总的翻转次数而不是某个翻转方案的次数。
Search(int step){
    //递归出口
   if(剪枝)退出;
   if(排好序) {检查是否更优};
   //递归
   for(int i = 1; i<n;i++){
      Revert(0,i) ;//选择翻转0和i元素
      Search(step+1); //深入探索下一步(step+1)
      Revert(0,i) ; //回退到当前step
   }
}
```
```
#include "stdio.h"
#include <iostream>
#include <assert.h>
/**********************************************************************/
//
// 烙饼排序实现
//
/**********************************************************************/
class CPrefixSorting
{
public:
	CPrefixSorting()
	{
		m_nCakeCnt = 0;
		m_nMaxSwap = 0;
	}
	//
	// 计算烙饼翻转信息
	// @param
	// pCakeArray   存储烙饼索引数组
	// nCakeCnt 烙饼个数
	//
	void Run(int* pCakeArray, int nCakeCnt)
	{
		Init(pCakeArray, nCakeCnt);
		m_nSearch = 0;
		Search(0);
	}
	//
	// 输出烙饼具体翻转的次数
	//
	void Output()
	{
		for(int i = 0; i < m_nMaxSwap; i++)
		{
			printf("%d ", m_SwapArray[i]);
		}

		printf("\n |Search Times| : %d\n", m_nSearch);
		printf("Total Swap times = %d\n", m_nMaxSwap);
	}
private:
	//
	// 初始化数组信息
	// @param
	// pCakeArray   存储烙饼索引数组
	// nCakeCnt 烙饼个数
	//
	void Init(int* pCakeArray, int nCakeCnt)
	{
		assert(pCakeArray != NULL);
		assert(nCakeCnt > 0);
		m_nCakeCnt = nCakeCnt;
		// 初始化烙饼数组
		m_CakeArray = new int[m_nCakeCnt];
		assert(m_CakeArray != NULL);
		for(int i = 0; i < m_nCakeCnt; i++)
		{
			m_CakeArray[i] = pCakeArray[i];
		}
		// 设置最多交换次数信息
		m_nMaxSwap = UpBound(m_nCakeCnt);
		// 初始化交换结果数组
		m_SwapArray = new int[m_nMaxSwap];
		assert(m_SwapArray != NULL);
		// 初始化中间交换结果信息
		m_ReverseCakeArray = new int[m_nCakeCnt];
		for(int i = 0; i < m_nCakeCnt; i++)
		{
			m_ReverseCakeArray[i] = m_CakeArray[i];
		}
		m_ReverseCakeArraySwap = new int[m_nMaxSwap];
	}



	// 寻找当前翻转的上界
	int UpBound(int nCakeCnt)
	{
		return (nCakeCnt-1)*2;
	}
	//
	// 寻找当前翻转的下界
	//
	//
	int LowerBound(int* pCakeArray, int nCakeCnt)
	{
		int t, ret = 0;
		// 根据当前数组的排序信息情况来判断最少需要交换多少次
		for(int i = 1; i < nCakeCnt; i++)
		{
			// 判断位置相邻的两个烙饼，是否为尺寸排序上相邻的
			t = pCakeArray[i] - pCakeArray[i-1];
			if((t == 1) || (t == -1))
			{
			}
			else
			{
				ret++;
			}
		}
		return ret;
	}
	// 排序的主函数
	void Search(int step)
	{
		int i, nEstimate;
		m_nSearch++;
		// 估算这次搜索所需要的最小交换次数
		nEstimate = LowerBound(m_ReverseCakeArray, m_nCakeCnt);
		if(step + nEstimate > m_nMaxSwap||step >= m_nMaxSwap)
			return;
		// 如果已经排好序，即翻转完成，输出结果
		if(IsSorted(m_ReverseCakeArray, m_nCakeCnt))
		{
			if(step < m_nMaxSwap)
			{
				m_nMaxSwap = step;
				for(i = 0; i < m_nMaxSwap; i++)
					m_SwapArray[i] = m_ReverseCakeArraySwap[i];
			}
			return;
		}
		// 递归进行翻转
		for(i = 1; i < m_nCakeCnt; i++)
		{
			Revert(0, i);
			m_ReverseCakeArraySwap[step] = i;
			Search(step + 1);
			Revert(0, i);
		}
	}
	//
	// true : 已经排好序
	// false : 未排序
	//
	bool IsSorted(int* pCakeArray, int nCakeCnt)
	{
		for(int i = 1; i < nCakeCnt; i++)
		{
			if(pCakeArray[i-1] > pCakeArray[i])
			{
				return false;
			}
		}
		return true;
	}
	//
	// 翻转烙饼信息
	//   
	void Revert(int nBegin, int nEnd)
	{
		assert(nEnd > nBegin);
		int i, j, t;
		// 翻转烙饼信息
		for(i = nBegin, j = nEnd; i < j; i++, j--)
		{
			t = m_ReverseCakeArray[i];
			m_ReverseCakeArray[i] = m_ReverseCakeArray[j];
			m_ReverseCakeArray[j] = t;
		}
	}
private:
	int* m_CakeArray;   // 烙饼信息数组
	int m_nCakeCnt;     // 烙饼个数
	int m_nMaxSwap;     // 最多交换次数。根据前面的推断，这里最多为m_nCakeCnt * 2
	int* m_SwapArray;   // 交换结果数组
	int* m_ReverseCakeArray;        // 当前翻转烙饼信息数组
	int* m_ReverseCakeArraySwap;    // 当前翻转烙饼交换结果数组
	int m_nSearch;                  // 当前搜索次数信息
};
void main(){
	CPrefixSorting problem;
//	int cakeArray[] = {3,2,1,6,5,4};
	int cakeArray[] = {4,2,1,3};
	problem.Run(cakeArray,4);
	problem.Output();
	return;
}
```
