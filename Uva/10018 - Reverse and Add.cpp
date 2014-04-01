#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 999+10
void op();
void zfx(char *s,int *zheng,int *fan)
{
     int len=strlen(s);
     int i;
     for(i=1;i<=len;i++)fan[i]=s[i-1]-'0';
     for(i=1;i<=len;i++)zheng[i]=fan[len-i+1]; 
     
     }
void gjdplus(int *a,int*b,int *o)                        //¼Ó·¨                
{
     int i;
     for(i=1;i<=N-1;i++){o[i]=a[i]+b[i];}
     for(i=1;i<=N-1;i++)
     {
                   if(o[i]>=10){o[i]-=10;o[i+1]+=1;}
                   }
     }
bool check(char *s)
{
     int len=strlen(s);
     int i;
     for(i=0;i<len;i++){if(s[i]!=s[len-i-1]){return true;}}
     return false;
     }
int main()
{
    int s,i;
    scanf("%d",&s);
    for(i=1;i<=s;i++)op();
    //system("pause");
    return 0;
    }
void op()
{
     //freopen("in.txt","r",stdin);
     //freopen("out.txt","w",stdout); 
     int count=0,leno,i;
     char s[N];int zheng[N]={0},fan[N]={0},o[N]={0};
     scanf("%s",s);
     leno=strlen(s);
     zfx(s,zheng,fan);
     gjdplus(zheng,o,o);
     while(check(s))
     {
     int len=strlen(s);    
     zfx(s,zheng,fan);
     gjdplus(zheng,fan,o);    
     /*
     puts(s);
     for(i=1;i<=len;i++)printf("%d ",fan[i]);printf("fan\n");
     for(i=1;i<=len;i++)printf("%d ",zheng[i]);printf("zheng\n");
     for(i=1;i<=leno;i++)printf("%d ",o[i]);printf("o\n");
     */
     for(i=N-2;i>=0;i--)
     {
                        if(o[i+1]==0 && o[i]!=0){leno=i;break;}
                        }
     for(i=1;i<=leno;i++)sprintf(s+i-1,"%d",o[i]);   
     count++; 
                           }
     printf("%d ",count);
     for(i=1;i<=leno;i++)printf("%d",o[i]);printf("\n");
     
     }
