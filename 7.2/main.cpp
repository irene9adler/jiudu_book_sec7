//九度书 第七章 动态规划 例7.2错排公式
#include <stdio.h>
#define M 21
long long F[M];

int main()
{
    F[1] = 0;
    F[2] = 1;
    int i;
    for(i = 3;i < M; i++)
    {
        F[i] = (i - 1)* F[i-1] + (i - 1)* F[i-2];
    }
    int x;
    while(scanf("%d",&x)!=EOF)
    {
        printf("%I64d\n",F[x]);
    }
    return 0;
}
