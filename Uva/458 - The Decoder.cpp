#include<stdio.h>
#include<string.h>
int main()
{
    char s[10000];
    while(scanf("%s",s)!=EOF)
    {
                             int i,len;
                             len=strlen(s);
                             for(i=0;i<=len-1;i++)s[i]-=7;
                             puts(s);                     
                             }
    return 0;
    }
