#include<stdio.h>
#include<string.h>
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int q=0;
    char s[200];
    while(gets(s))
    {
                  int i,len=strlen(s);
                  for(i=0;i<len;i++)
                  {
                                    if(s[i]=='"')
                                    {
                                                 q=!q;
                                                 if(q)printf("``");
                                                 else printf("''");
                                                 }
                                    else printf("%c",s[i]);
                                    
                                    } 
                  printf("\n");
                  }
    }
