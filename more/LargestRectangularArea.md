**Largest Rectangular Area**
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

![](http://www.leetcode.com/wp-content/uploads/2012/04/histogram.png)  
Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].  

![](http://www.leetcode.com/wp-content/uploads/2012/04/histogram_area.png)  
The largest rectangle is shown in the shaded area, which has area = 10 unit.  
For example,  
Given height = [2,1,5,6,2,3],  
return 10.  


![](http://d1gjlxt8vb0knt.cloudfront.net//wp-content/uploads/histogram1.png)  

**算法思想**：
   *For every bar ‘x’, we calculate the area with ‘x’ as the smallest bar in the rectangle*. If we calculate such area for every bar ‘x’ and find the maximum of all areas, our task is done. How to calculate area with ‘x’ as smallest bar? We need to know index of the first smaller (smaller than ‘x’) bar on left of ‘x’ and index of first smaller bar on right of ‘x’. Let us call these indexes as ‘left index’ and ‘right index’ respectively.
   
**算法过程**：  
1) Create an empty stack.

2) Start from first bar, and do following for every bar ‘hist[i]’ where ‘i’ varies from 0 to n-1.  
……a) If stack is empty or hist[i] is higher than the bar at top of stack, then push ‘i’ to stack.  
……b) If this bar is smaller than the top of stack, then keep removing the top of stack while top of the stack is greater. Let the removed bar be hist[tp]. Calculate area of rectangle with hist[tp] as smallest bar. For hist[tp], the ‘left index’ is previous (previous to tp) item in stack and ‘right index’ is ‘i’ (current index). 

3) If the stack is not empty, then one by one remove all bars from stack and do step 2.b for every removed bar.

**算法演示**：
下面给出栈的变化情况（注意：程序中栈存储的实际是hist数组的元素下标，而图示直接用对应的数组元素演示栈的变换情况！）
```
i=0,                  , S = |6|  
i=1, S.Pop(),         , S = | |, area = 6*1 = 6;

     S.push(hist[1]) ,  S = |2|,    
                            |5|  
i=2, S.push(hist[2]) ,  S = |2|, 

1=3, S.Pop(),           S = |2|, area = 5*(3-1-1) = 5;  
                            |4|  
     S.push(hist[3]) ,  S = |2|, 
     
                            |5|       
                            |4|  
i=4, S.push(hist[4]) ,  S = |2|,   
i=5, S.Pop(),               |4| 
                        S = |2|,  area = 5*(5-3-1)  = 5        
                           
     S.Pop(),           S = |2|,  area = 4*(5-1-1)  = 12       
     S.Pop(),           S = | |,  area = 2*(5)  = 10
     S.push(hist[5]) ,  S = |1|, 
                        S = |6|,
i=6, S.push(hist[6]) ,  S = |1|,   
     S.Pop(),           S = |1|,  area = 6*(7-5-1)  = 6
     S.Pop(),           S = |1|,  area = 1*(7)  = 7
```
//http://www.geeksforgeeks.org/largest-rectangle-under-histogram/

--------------------------------------------------------
**Maximal Rectangle**
```
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.
```
例如
```
    0 0 0 0
    1 1 1 1
    1 1 1 0
    0 1 0 0
```
```
    0  0  0  0
   |--------|
   |1  1  1 |1
   |1  1  1 |0
   |--------|
    0  1  0  0
```
*解法1*：

*解法2（直方图解法）*：就是对于矩阵的每一行，，计算以这行为底的直方图（即该行每个‘1’字符上面有多少个连续的'1'）。然后用*Largest Rectangular Area*中的方法计算该行对应直方图中的最大矩形。 对每一行重复这一过程！
如上述例子中，第1行的直方图是 (0 0 0 0 ),第2行的直方图是 (1 1 1 1 ),第3行的直方图是 (2 2 2 0 ),第4行的直方图是 (0 3 0 0 )

*解法3（左右夹逼法）*：以H[j]记录元素[i][j] 的这一列的'1'的高度，以L[j]、R[j]分别记录以元素[i][j]的高度H[j]为高的矩形的左右边界。   
因此该矩形面积为H[j]*(R[j]-L[j]+1)。 以上述例子演示改过程如下：  
```
  m = 4, n = 4
  maxL = 0, minR = n-1=3;
  
 i=0: H[j]:  0             0             0             0
      L[j]:  0             0             0             0
      R[j]:  3             3             3             3 
 i=1: H[j]:  1             1             1             1
      L[j]:  0             0             0             0
      R[j]:  3             3             3             3 
 i=2: H[j]:  2             2             2             0
      L[j]:  0             0             0             0,maxL = 4
      R[j]:  2             2             2             3,minR = 2
 i=2: H[j]:  0             3             0             0
      L[j]:  0,maxL = 1    1             0,maxL = 3    0,maxL = 4
      R[j]:  3             1             3,minR = 1    3,minR = 2    
      
```
代码如下：
```
int maximalRectangle(vector<vector<char> > &matrix) {  
    int m = matrix.size();  
    if (m == 0) return 0;  
    int n = matrix[0].size();  
    if (n == 0) return 0;  
    vector<int> h(n);  
    vector<int> l(n);  
    vector<int> r(n, n - 1);  
    int maxArea = 0, maxL = 0, minR = m - 1;  
    for (int i = 0; i < m; i++)      {  
        maxL = 0, minR = n-1;  
        for (int j = 0; j < n; j++)    {  
            if (matrix[i][j] == '0')    { 
                maxL = j + 1;     //右边元素的矩形的最左边界从j+1开始
                h[j] = 0;          l[j] = 0;          r[j] = n - 1;  
            }  
            else  {  
                h[j]++;  
                l[j] = max(l[j], maxL);  //元素[i][j]对应矩形的最左边界 :上一行该列元素[i-1][j]对应矩形的最左边界 和 
                                         //                               本行当前的最左边界，两者取最大值
            }  
        }  
          
        for (int j = n - 1; j >= 0; j--)  {  
            if (matrix[i][j] == '0')  {  
                minR = j - 1;  //左边元素的矩形的最右边界从j-1开始
                r[j] = n - 1; 
            }  
            else  {  
                r[j] = min(r[j], minR);  //上一行该列元素的最右边界和本行目前最右边界，两者的最小值，作为该元素的最右边界
                maxArea = max(maxArea, h[j] * (r[j] - l[j] + 1));  
            }  
        }  
    }  
    return maxArea;  
}  
```

http://blog.csdn.net/PeerlessBloom/article/details/39648359

http://liangjiabin.com/blog/2015/04/leetcode-maximal-rectangle.html

http://leetcode.tanglei.name/content/matrix/Maximal-Rectangle.html
