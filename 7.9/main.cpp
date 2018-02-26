//九度书 第七章 动态规划 例7.9完全背包问题
#include <stdio.h>
#define INFINITE 0x7fffffff

struct E
{
    int val;
    int weight;
} E[501];//描述一个硬币

int dp[10001];//dp[j]表示储蓄罐中硬币重量为j时的最小硬币总价值

int min_(int a,int b)
{
    return a < b ?a :b;
}

int main()
{
    int tmp,s;//储蓄罐本身重量和总重量
    while(scanf("%d%d",&tmp,&s)!=EOF)
    {
        s = s - tmp;
        int n;//n种硬币
        scanf("%d",&n);
        int i,j;
        for(i = 1;i <= n;i++)
        {
            scanf("%d%d",&E[i].val,&E[i].weight);
        }
        //设定dp初值 此处完全背包问题和0-1背包问题不同
        for(i = 1;i <= s; i++)
            dp[i] = INFINITE;

        dp[0] = 0;

        for(i = 1;i <= n;i++)
        {
            for(j = E[i].weight; j <=s ;j++)//完全背包问题顺序遍历
            {
                if(dp[j-E[i].weight]!=INFINITE)
                    {
                        dp[j] = min_(dp[j],dp[j-E[i].weight] + E[i].val);
                    }
            }
        }
        if(dp[s]!=INFINITE) printf("the min amount of money is %d\n",dp[s]);
        else printf("no result\n");
    }
    return 0;
}
