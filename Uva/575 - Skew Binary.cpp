#include<stdio.h>
#include<string.h>
int main()
{
    long long skew[32];
    skew[1]=1;
    int i;
    for(i=1;i<=31;i++)skew[i+1]=2*skew[i]+1;
    char s[50];
    while(scanf("%s",s)!=EOF)
    {
                             int len=strlen(s);
                             int zj[50];
                             int j;
                             long long sum=0;
                             for(j=1;j<=len;j++)zj[j]=s[len-j]-'0';
                             for(j=1;j<=len;j++)sum+=zj[j]*skew[j];
                             if(sum==0)break;
                             printf("%lld\n",sum);
                             }
    } 
