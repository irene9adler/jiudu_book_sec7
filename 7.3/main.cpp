//�Ŷ��� ������ ��̬�滮 ��7.3 �����������
#include <stdio.h>
#define M 26

int time[M];//������ǰ�ʱ��������ڵ��߶�
int zixulie[M];//�������i������������еĳ���
int max_(int a,int b)
{
    if(a >= b) return a;
    else return b;
}

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int i,j;
        int max_i;
        for(i = 0;i < n; i++)
            scanf("%d",&time[i]);

            for(i = 0; i < n ;i++)
            {
                max_i = 1;
                for(j = 0; j < i; j++)
                {
                    if(time[j] <= time[i]){
                      max_i = max_(max_i,zixulie[j] + 1);//F[i] = max{1,F[j] + 1}|j<i && a[j] < a[i]����������е��ƹ�ʽ
                    }
                }
                zixulie[i] = max_i;
            }

            int res = 1;
            for(i = 0;i < n; i++)
                res = max_(res,zixulie[i]);

            printf("%d\n",res);
    }

    return 0;
}
