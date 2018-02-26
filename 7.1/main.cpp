//九度书 第七章动态规划 递推例7.1
#include <stdio.h>
#define M 91
//int F [M];
long long F[M];
int main()
{
    F[1] = 1;
    F[2] = 2;
    int i;
    for(i = 3;i < M ;i++)
    {
        F[i] = F[i-1] + F[i-2];
    }
    int x;
    while(scanf("%d",&x)!=EOF)
    {
        printf("%I64d\n",F[x]);
    }
    return 0;
}
