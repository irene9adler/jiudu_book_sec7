//�Ŷ��� ������ ��̬�滮 ��7.4 �����������
#include <stdio.h>
#include <string.h>
#define M 101

int zixulie[M][M];//����i j������������еĴ�С
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
    //����������������еĳ�ʼ����
    for(i = 0; i < l1; i++)
    {
        for(j = 0;j < l2; j++)
        {
            if(s1[i] != s2[j])
              zixulie[i][j] = max_(zixulie[i][j-1] , zixulie[i-1][j]);
            else
               zixulie[i][j] = zixulie[i-1][j-1] + 1;
            //����������������еĵ��ƹ�ʽ
        }
    }//����������������������

    printf("%d\n",zixulie[l1-1][l2-1]);
    return 0;
}
