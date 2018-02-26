//�Ŷ��� ������ ��̬�滮 ��7.9��ȫ��������
#include <stdio.h>
#define INFINITE 0x7fffffff

struct E
{
    int val;
    int weight;
} E[501];//����һ��Ӳ��

int dp[10001];//dp[j]��ʾ�������Ӳ������Ϊjʱ����СӲ���ܼ�ֵ

int min_(int a,int b)
{
    return a < b ?a :b;
}

int main()
{
    int tmp,s;//����ޱ���������������
    while(scanf("%d%d",&tmp,&s)!=EOF)
    {
        s = s - tmp;
        int n;//n��Ӳ��
        scanf("%d",&n);
        int i,j;
        for(i = 1;i <= n;i++)
        {
            scanf("%d%d",&E[i].val,&E[i].weight);
        }
        //�趨dp��ֵ �˴���ȫ���������0-1�������ⲻͬ
        for(i = 1;i <= s; i++)
            dp[i] = INFINITE;

        dp[0] = 0;

        for(i = 1;i <= n;i++)
        {
            for(j = E[i].weight; j <=s ;j++)//��ȫ��������˳�����
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
