#include<stdio.h>
#include<string.h>
int max(int a,int b)
{
    if(a<b)return b;
    else return a; 
    }
void fx(char *a)
{
     
     int len=strlen(a);
     int i;
     char b[30]; 
     strcpy(b,a);
     for(i=0;i<=len-1;i++)a[i]=b[len-i-1];
     } 
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    char a[20],b[20];
    memset(a,'0',sizeof(char));
    memset(b,'0',sizeof(char));
    while(scanf("%s%s",a,b)!=EOF && !(a[0]=='0' && strlen(a)==1 && b[0]=='0' && strlen(b)==1))
    {
           int count=0,i;int c[20]={0};int fa=1,fb=1;
           int lena=strlen(a),lenb=strlen(b);
           int mmax=max(lena,lenb)+1;
           //for(i=1;i<mmax;i++)printf("%d ",c[i]);printf("\n");
           fx(a);fx(b);
           for(i=1;i<mmax;i++){if(fa && a[i-1]>='0' && a[i-1]<='9')c[i]+=a[i-1]-'0';else fa=0;if(fb && b[i-1]>='0' && b[i-1]<='9')c[i]+=b[i-1]-'0';else fb=0;}
           /*for(i=1;i<mmax;i++)printf("%d ",c[i]);printf("\n");
           for(i=0;i<mmax-1;i++)printf("%c ",a[i]);printf("\n");
           for(i=0;i<mmax-1;i++)printf("%d ",a[i]-'0');printf("\n");
           for(i=0;i<mmax-1;i++)printf("%c ",b[i]);printf("\n");
           for(i=0;i<mmax-1;i++)printf("%d ",b[i]-'0');printf("\n");*/
           for(i=1;i<mmax;i++)
           {
                              if(c[i]>=10){count++;c[i+1]++;}
           }
           //for(i=1;i<mmax;i++)printf("%d ",c[i]);printf("\n");
           if(count==0)printf("No carry operation.\n");
           else if (count==1) printf("1 carry operation.\n");  
           else printf("%d carry operations.\n",count);
           memset(a,'0',sizeof(char));
           memset(b,'0',sizeof(char));
           memset(c,0,sizeof(int));
           for(i=1;i<=20;i++)c[i]=0;
           }
    return 0;
    }
