#include<stdio.h>
#include<string.h>
bool check(char x)
{
     if(x>='a'&&x<='z')return true;
     else if(x>='A'&&x<='Z')return true;
     return false;
     } 
int main()
{
    char s[65535];
    while(gets(s)!=0)
    {
                             long i,j,len;
                             len=strlen(s);
                             long count=0;
                             for(i=0;i<=len-1;i++)if(check(s[i])){count++;break;}
                             for(;i<=len-2;i++)
                             {
                                        if(!check(s[i])){for(j=i+1;j<=len-1;j++){if(check(s[j])){count++;break;}else break;  }  }   
                                                  }   
                             if(count!=0)printf("%ld\n",count);              
                             }
    return 0;
    }
