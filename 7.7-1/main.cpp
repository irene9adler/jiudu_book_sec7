//九度书 第七章动态规划 背包问题 例7.7 0-1背包
//求一定时间内采药的最大价值 没有用到排序 使用动态规划 初始状态 转移方程
#include <stdio.h>

struct E
{
    int time;
    int val;
}E[101];

int max_(int a,int b)
{
    if(a >= b) return a;
    else return b;
}
int dp[101][1001];//dp[i][j]表示第i个草药 在背包总时间不超过j的情况下 包内草药的总价值
int main()
{
    int t,m;//总时间t 草药总数m
    while(scanf("%d%d",&t,&m)!=EOF)
    {
        int i,j;
        for(i = 1; i <= m;i++)
            scanf("%d%d",&E[i].time,&E[i].val);

        for(j = 1; j <= t; j++)
           dp[0][i] = 0;//初始状态 不放草药 时间为0

        for(i = 1; i <= m; i++)//对每个草药
        {
            for(j = t; j >= E[i].time; j--)//时间够采草药i
            {
                dp[i][j] = max_(dp[i-1][j],dp[i-1][j-E[i].time] + E[i].val);//两种状态转移方式取大的
            }
                for(j = 1;j < E[i].time; j++)
                dp[i][j] = dp[i-1][j];//时间不够采草药i的状态转移方式
        }
        printf("%d\n",dp[m][t]);
    }
    return 0;
}
