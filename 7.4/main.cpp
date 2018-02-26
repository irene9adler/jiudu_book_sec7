//九度书 第七章 动态规划 例7.4 最长公共子序列
#include <stdio.h>
#include <string.h>
#define M 101

int zixulie[M][M];//保存i j处最长公共子序列的大小
int max_(int a,int b)
{
    if(a >= b) return a;
    else return b;
}
int main()
{
    char s1[M];
    char s2[M];
    int l1,l2;
    scanf("%s",s1);
    scanf("%s",s2);
    l1 = strlen(s1);
    l2 = strlen(s2);

    int i,j;
    for(i = 0;i < l1; i++)
        zixulie[i][0] = 0;

    for(j = 0; j< l2; j++)
        zixulie[0][j] = 0;
    //以上是最长公共子序列的初始条件
    for(i = 0; i < l1; i++)
    {
        for(j = 0;j < l2; j++)
        {
            if(s1[i] != s2[j])
              zixulie[i][j] = max_(zixulie[i][j-1] , zixulie[i-1][j]);
            else
               zixulie[i][j] = zixulie[i-1][j-1] + 1;
            //以上是最长公共子序列的递推公式
        }
    }//把最长公共子序列数组计算完

    printf("%d\n",zixulie[l1-1][l2-1]);
    return 0;
}
