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
直方图解法就是对于矩阵的每一行，，计算以这行为底的直方图（即该行每个‘1’字符上面有多少个连续的'1'）。然后用*Largest Rectangular Area*中的方法计算该行对应直方图中的最大矩形。 对每一行重复这一过程！

http://liangjiabin.com/blog/2015/04/leetcode-maximal-rectangle.html
