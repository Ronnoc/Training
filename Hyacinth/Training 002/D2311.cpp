#include<stdio.h>
int dp[210][210];
void init()
{
    int i,j,k;
    bool is[1000];
    for(i=2;i<=200;i++)
        for(j=2;j<=200;j++)
        {
            for(k=0;k<1000;k++)
                is[k]=0;
            for(k=2;i-k>=2;k++)
                is[dp[k][j]^dp[i-k][j]]=1;
            for(k=2;j-k>=2;k++)
                is[dp[i][k]^dp[i][j-k]]=1;
            for(k=0;is[k];k++);
            dp[i][j]=k;
        }
}
int main()
{
    //freopen("2.txt","r",stdin);
    int w,h;
    init();
    while(~scanf("%d%d",&w,&h))
    {
        printf("%s\n",(dp[w][h]!=0)?"WIN":"LOSE");
    }
    return 0;
}
