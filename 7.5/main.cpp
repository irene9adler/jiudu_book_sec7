//九度 第七章 动态规划 例7.5 搬寝室 好难理解
#include <stdio.h>
#include <algorithm>
#include <math.h>
#define INFINITE 0x7fffffff//定义整数范围的正无穷

int good[2001];//存行李重量
int dp[1001][2001];//dp[i][j] 表示前j件行李组成i对


using namespace std;


int main()
{
    int n,k;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        int i,j;
        for(i = 1;i <= n; i++)
        {
            scanf("%d",&good[i]);
            dp[0][i] = 0;//初始状态 不取那i对
        }

        sort(good,good + n);

        for(i = 1; i <= k; i++)
        {
            for(j = 2*i; j <= n ;j++)
            {
                if(j > 2*i)
                  dp[i][j] = dp[i][j-1];//如果j>2*i(就循环第一次不满足） 说明前j-1个已经能组成i对并且肯定这样dp值是最小的 最后两个物品可以不配对
                else
                    dp[i][j] = INFINITE;//j = 2*i 最后两件物品必须配对

                if(dp[i][j] > dp[i-1][j-2] + pow(good[j]-good[j-1],2))//在以上两种情况下
                   dp[i][j] = dp[i-1][j-2] + pow(good[j]-good[j-1],2);//由dp[i-1][j-2]转移过来的值优于正无穷和由dp[i][j-1]转移过来的值
             //如果j和j-1 配对 疲劳度由dp[i-1][j-2]增 pow(good[j]-good[j-1],2) 如果j和j-1不配对 疲劳度等于dp[i][j-1]

            }
        }
     printf("%d\n",dp[k][n]);
    }
    return 0;
}
