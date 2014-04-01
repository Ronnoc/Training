#include<stdio.h>
#define N 999
long long tenpow(long long n)    //10的n次幂 
{
     int i;
     long long m=1;
     for(i=1;i<=n;i++)
     {m*=10;}
     return m; 
     }
int ws(long long n)         //位数 
{
    int i=1,p;
    long long s,t,ss,tt;
    for (i=9;i>=0;i--)
    {   ss=tenpow(i+1);
        tt=tenpow(i);
        s=n%ss; 
        t=n%tt; 
        if(n==s && n!=t){p=i+1;return p;}
        }
    }
int main()
{
	int p,xx;
    int a[N],b[N],c[N];                                          //b[]大数,c[]小数    xx为下限                                               // 
    long long n[N],big,small,jiangyou;
    //printf("请输入一个至少3位至多9位数"); 
   while( scanf("%lld",&n[1])==1)
   {
    p=ws(n[1]); 
    int count=1,j,l,k,m,flag=1,i,q,ff=1; 
	small=0,big=0;
for(j=1;j<=p;j++){a[j]=0;}
jiangyou=n[count];
for(j=1;j<=p;j++)
                     {
                     a[p-j+1]=jiangyou%10;
                     jiangyou/=10;
                     }
m=p*(p-1)/2;
for(i=1;i<=10;i++){b[i]=a[i];c[i]=a[i];}
for(i=1;i<=m;i++)  
{  
for(j=1;j<=p-1;j++)  
    {
                     if(b[j]>=b[j+1])   {q=b[j];b[j]=b[j+1];b[j+1]=q;  }  
    }  
}  
for(i=1;i<=m;i++)  
{  
for(j=1;j<=p-1;j++)  
    {
                     if(c[j]<=c[j+1])   {q=c[j];c[j]=c[j+1];c[j+1]=q;  }  
    }  
}
int ccc=1;
for(i=p;i>=1;i--)if(c[i]!=0)break;ccc=i++;
int temp;//printf("%d 9%d\n",ccc,p);
temp=c[ccc];c[ccc]=c[p];c[p]=temp;
for(i=1;i<=p;i++){big+=b[i]*tenpow(i-1);}
for(i=1;i<=p;i++){small+=c[i]*tenpow(i-1);}
count++;
n[count]=big-small;
printf("%lld - %lld = %lld = 9 * %lld\n",big,small,n[count],n[count]/9); 
}
return 0;
	} 
