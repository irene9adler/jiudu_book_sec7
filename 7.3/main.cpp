//九度书 第七章 动态规划 例7.3 最长递增子序列
#include <stdio.h>
#define M 26

int time[M];//保存的是按时间排序的炮弹高度
int zixulie[M];//保存的是i处最长递增子序列的长度
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
                      max_i = max_(max_i,zixulie[j] + 1);//F[i] = max{1,F[j] + 1}|j<i && a[j] < a[i]最长递增子序列递推公式
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
