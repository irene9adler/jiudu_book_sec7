//�Ŷ� ������ ��̬�滮 ��7.5 ������ �������
#include <stdio.h>
#include <algorithm>
#include <math.h>
#define INFINITE 0x7fffffff//����������Χ��������

int good[2001];//����������
int dp[1001][2001];//dp[i][j] ��ʾǰj���������i��


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
            dp[0][i] = 0;//��ʼ״̬ ��ȡ��i��
        }

        sort(good,good + n);

        for(i = 1; i <= k; i++)
        {
            for(j = 2*i; j <= n ;j++)
            {
                if(j > 2*i)
                  dp[i][j] = dp[i][j-1];//���j>2*i(��ѭ����һ�β����㣩 ˵��ǰj-1���Ѿ������i�Բ��ҿ϶�����dpֵ����С�� ���������Ʒ���Բ����
                else
                    dp[i][j] = INFINITE;//j = 2*i ���������Ʒ�������

                if(dp[i][j] > dp[i-1][j-2] + pow(good[j]-good[j-1],2))//���������������
                   dp[i][j] = dp[i-1][j-2] + pow(good[j]-good[j-1],2);//��dp[i-1][j-2]ת�ƹ�����ֵ�������������dp[i][j-1]ת�ƹ�����ֵ
             //���j��j-1 ��� ƣ�Ͷ���dp[i-1][j-2]�� pow(good[j]-good[j-1],2) ���j��j-1����� ƣ�Ͷȵ���dp[i][j-1]

            }
        }
     printf("%d\n",dp[k][n]);
    }
    return 0;
}
