//�Ŷ��� ��7.7��һά
#include <stdio.h>

struct E
{
    int time;
    int val;
}E[101];

int dp[1001];//dp[j]��ʾʱ��j������ҩ�ܼ�ֵ

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

        for(i = 1; i <= m; i++)//��ÿһ��ҩ��
        {
            for(j = t; j >= E[i].time; j--)//ʱ�乻�òſ��ܲ�
                dp[j] = max_(dp[j],dp[j-E[i].time] + E[i].val);//һ�ָ��·�ʽ ȡ������Ƿ����
        }

        printf("%d\n",dp[t]);
    }
    return 0;
}
