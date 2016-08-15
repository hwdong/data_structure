copy from http://www.voidcn.com/blog/wangzhiyu1980/article/p-4982361.html  
**饮料供货**问题描述
公司采购饮料，采购的饮料有一个总量的限制 V0升，同时每种饮料有最大瓶数的限制C(i)，大家对每种饮料有一个满意度 H(i)，问怎样采购能使总的满意度最高。注: 饮料的包装规格都是2的n次方的整数。


想法 I : 动态规划
假设：
          饮料的种类为 n 
          每种饮料的购买量为 B(i)  (i  = 0.. n-1)
          每种饮料最大瓶数的限制  C(i)  (i  = 0.. n-1) 
          每种饮料的满意度为  H(i)  (i  = 0.. n-1)
          每种饮料的包装规格  V(i)  (i  = 0.. n-1)
          总的 容量为 V0
          满意度为   Happy

V0 = B(0) * V(0) + B(1) * V(1) + .... + B(n) * V(n)
Happy = B(0) * H(0) + B(1) * H(1) + .... + B(n) * H(n)

求的是 Max(Happy)。

一个最优的结果  Opt(V0，n)，是由中间若干个步骤的最优结果 Opt(V`，i) 推算出来的
Opt(V`，i) = MAX{   B(i)*H(i) + Opt(V`- B(i)*V(i), i-1)  } 

当前步骤的最优结果 = 上一步的最优结果 + 当前步骤的结果。
对每一步都进行最优结果的推算，最后得到的一定是最优的方案。

举例：   有3种饮料，  总的容量 为  8
每一种的瓶数限制  arrC[] = {5, 4, 6};
每一种的满意度     arrH[] = {3, 5, 2};
每种的容量            arrV[] = {2, 4, 8}

代码示例：
```
#include <iostream>
#include <iomanip> 

using namespace std;

#define V0 8
#define T  3
#define INF 255


int arrC[] = {5, 4, 6};
int arrH[] = {3, 5, 2};
int arrV[] = {2, 4, 8};

void printOpt(int arr[V0+1][T+1], int nLeni, int nLenj)
{
    int i =0, j = 0;

    cout << "=================================" << endl;
    for (i = 0; i < nLeni; i++)
    {
        for (j = 0; j < nLenj; j++)
        {
            cout.fill(' ');  
            cout.setf(ios::right);  
            cout.width(6);  
            cout << setprecision(6) << arr[i][j] << "  ";
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;
}

int Calc(int V)
{
    int i=0, j=0, k=0;
    int opt[V0+1][T+1];

    memset(opt, 0, sizeof(int) * (V0+1)*(T+1));
    opt[0][T] = 0;
    for (i = 1; i <= V0; i++)
    {
        opt[i][T] = -INF;
    }
    printOpt(opt, V0+1, T+1);

    for (j = T-1; j >=0; j--)
    {
        for (i = 0; i <= V0; i++)
        {
            opt[i][j] = -INF;
            for (k = 0; k < arrC[j]; k++)
            {
                if (i < k * arrV[j])
                    break;

                int h = opt[i - k * arrV[j]][j+1];
                if (h != -INF)
                {
                    h += arrH[j] * k;
                    if (h > opt[i][j])
                    {
                        opt[i][j] = h;
                        printOpt(opt, V0+1, T+1);
                    }
                }
            }
        }
    }
    printOpt(opt, V0+1, T+1);
    return opt[V0][0];
}

void main()
{
    int nHappy = 0;

    nHappy = Calc(V0);

    cout << nHappy << endl;

    cin >> nHappy;
}
```


http://www.cnblogs.com/gaopeng527/p/4604079.html 
