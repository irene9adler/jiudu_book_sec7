//�Ŷ��� ������ ��̬�滮 ��7.10 ���ر�������
#include <stdio.h>

struct E
{
    int money;
    int weight;
} E[2001];//�����׵ļ۸������ ���m��100������ ÿ�����20�� ÿ������1��

int dp[101];//di[j]��ʾ�ܻ��Ѽ�Ǯjʱ�׵����������

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
        int n,m;//n��ʾ�����ܶ� m��ʾ�׵�����
        scanf("%d%d",&n,&m);
        int i,j;
        int p,h,k;//p��ʾÿ���׼۸� h��ʾÿ�������� k��ʾ�������м���
        int cnt = 0;//cnt�Ƕ�ÿ���ײ�ֺ��ȫ�����ж�����
        for(i = 1; i <= m ;i++)
      {
            scanf("%d%d%d",&p,&h,&k);

        //���濪ʼ��0-1����ת�� ��k����Ʒ��ֳ�1 2 4 ...k-2^c+1 ��������
        int c = 1;//cֵ��ʾ�����м���������
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
        E[cnt].weight = h * k;//�����䲻�Ǻܶ� ��������һ����
       }//forѭ����ÿ���ף�����

       for(j = 1; j <= n; j++)
         dp[j] = 0;//��ֵ

       for( i = 1; i <= cnt; i++)//cnt
       {
           printf("E[%d].money = %d\n",i,E[i].weight);
           for(j = n; j >= E[i].money; j--)//ת��Ϊ0-1������ ������dp[j]
           {
               dp[j] = max_(dp[j],dp[j-E[i].money] + E[i].weight);
               printf("dp[%d] = %d\n",j,dp[j]);
           }
       }
       printf("%d\n",dp[n]);
    }
    return 0;
}
