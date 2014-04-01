#include<stdio.h>
#include<string.h>
int leno=0;
int max(int a,int b)
{
    if(a>b)return a;
    else return b;
    }
void gjdplus(int *a,int *o)                                                     //∞—a+µΩo…œ 
{
     int i;
     for(i=1;i<=110;i++)o[i]+=a[i];
     for(i=1;i<=110;i++)
     {
                           if(o[i]>=10){o[i]-=10;o[i+1]+=1;}
                           }
     }
void fx(char *a,int *b)
{
     int i;
     int lena=strlen(a);
     for(i=0;i<lena;i++)b[lena-i]=a[i]-'0';
     }
int main()
{
    char a[110];
    int o[110];int i,leno;
    memset(a,'0',sizeof(char)*110);
    memset(o,0,sizeof(int)*110);
    while(scanf("%s",a)!=EOF && !(a[0]=='0'&&a[1]=='\0'))
    {
                             int aa[110];
                             memset(aa,0,sizeof(int)*110);          
                             fx(a,aa);
                             gjdplus(aa,o);
                             memset(a,'0',sizeof(char)*110);
                             }
    for(i=108;i>=1;i--)
    {
                       if(o[i+1]==0&&o[i]!=0){leno=i;break;}
                       }
    for(i=leno;i>=1;i--)printf("%d",o[i]);printf("\n");
    return 0;
    }
