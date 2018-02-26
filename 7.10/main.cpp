//九度书 第七章 动态规划 例7.10 多重背包问题
#include <stdio.h>

struct E
{
    int money;
    int weight;
} E[2001];//描述米的价格和重量 最多m（100）种米 每种最多20袋 每组最少1个

int dp[101];//di[j]表示总花费价钱j时米的最大总重量

int max_(int a,int b)
{
    return a > b ? a : b;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m;//n表示经费总额 m表示米的种类
        scanf("%d%d",&n,&m);
        int i,j;
        int p,h,k;//p表示每袋米价格 h表示每袋米重量 k表示该类米有几袋
        int cnt = 0;//cnt是对每种米拆分后的全部米有多少组
        for(i = 1; i <= m ;i++)
      {
            scanf("%d%d%d",&p,&h,&k);

        //下面开始往0-1背包转化 把k件物品拆分成1 2 4 ...k-2^c+1 的若干组
        int c = 1;//c值表示该组有几袋这种米
        while(k - c > 0)
        {
            printf("c = %d\n",c);
            k = k - c;
            cnt ++;
            E[cnt].money = c * p;
            E[cnt].weight = c * h;
            c = c * 2;
        }
        cnt ++;
        printf("cnt = %d\n",cnt);
        E[cnt].money = p * k;
        E[cnt].weight = h * k;//这两句不是很懂 大概是最后一个？
       }//for循环（每种米）结束

       for(j = 1; j <= n; j++)
         dp[j] = 0;//初值

       for( i = 1; i <= cnt; i++)//cnt
       {
           printf("E[%d].money = %d\n",i,E[i].weight);
           for(j = n; j >= E[i].money; j--)//转化为0-1背包后 逆序找dp[j]
           {
               dp[j] = max_(dp[j],dp[j-E[i].money] + E[i].weight);
               printf("dp[%d] = %d\n",j,dp[j]);
           }
       }
       printf("%d\n",dp[n]);
    }
    return 0;
}
