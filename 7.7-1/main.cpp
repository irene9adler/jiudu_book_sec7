//�Ŷ��� �����¶�̬�滮 �������� ��7.7 0-1����
//��һ��ʱ���ڲ�ҩ������ֵ û���õ����� ʹ�ö�̬�滮 ��ʼ״̬ ת�Ʒ���
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
int dp[101][1001];//dp[i][j]��ʾ��i����ҩ �ڱ�����ʱ�䲻����j������� ���ڲ�ҩ���ܼ�ֵ
int main()
{
    int t,m;//��ʱ��t ��ҩ����m
    while(scanf("%d%d",&t,&m)!=EOF)
    {
        int i,j;
        for(i = 1; i <= m;i++)
            scanf("%d%d",&E[i].time,&E[i].val);

        for(j = 1; j <= t; j++)
           dp[0][i] = 0;//��ʼ״̬ ���Ų�ҩ ʱ��Ϊ0

        for(i = 1; i <= m; i++)//��ÿ����ҩ
        {
            for(j = t; j >= E[i].time; j--)//ʱ�乻�ɲ�ҩi
            {
                dp[i][j] = max_(dp[i-1][j],dp[i-1][j-E[i].time] + E[i].val);//����״̬ת�Ʒ�ʽȡ���
            }
                for(j = 1;j < E[i].time; j++)
                dp[i][j] = dp[i-1][j];//ʱ�䲻���ɲ�ҩi��״̬ת�Ʒ�ʽ
        }
        printf("%d\n",dp[m][t]);
    }
    return 0;
}
