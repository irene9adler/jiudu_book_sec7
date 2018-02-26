//九度书 例7.7变一维
#include <stdio.h>

struct E
{
    int time;
    int val;
}E[101];

int dp[1001];//dp[j]表示时间j内最多采药总价值

int max_(int a, int b)
{
    if(a >= b) return a;
    else return b;
}
int main()
{
    int t,m;
    while(scanf("%d%d",&t,&m)!=EOF)
    {
        int i,j;
        for(i = 1; i <= m ;i++)
            scanf("%d%d",&E[i].time,&E[i].val);

        for(j = 0 ; j <= t; j++)
            dp[j] = 0;

        for(i = 1; i <= m; i++)//对每一种药草
        {
            for(j = t; j >= E[i].time; j--)//时间够用才可能采
                dp[j] = max_(dp[j],dp[j-E[i].time] + E[i].val);//一种更新方式 取大决定是否更新
        }

        printf("%d\n",dp[t]);
    }
    return 0;
}
