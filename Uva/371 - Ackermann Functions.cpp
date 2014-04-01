#include<stdio.h>
long long f(long long x)
{
     long long count=0,p=x;
     if(p==1)return 3;
     while(p!=1)
     {
                              if(p%2==1){p=(3*p+1)/2;count+=2;}
                              else {p/=2;count++;} 
                              }
     return count;
     }
long long max(long long a,long long b)
{
     if(a>b)return a;
     else return b;
     }     
int main()
{
    long long a,b;
    while(scanf("%lld%lld",&a,&b)!=EOF)
    {
		if(a==0 && b==0)break;
                                       long long maax=-1,wz=a,i,aa=a,bb=b;
                                       if(a>b){bb=a;aa=b;}
                                       for(i=aa;i<=bb;i++)
                                       {
																		  if(f(i)>maax)wz=i;
                                                                          maax=max(maax,f(i));
                                                                          }
                                       /*if(maax!=1)*/printf("Between %lld and %lld, %lld generates the longest sequence of %lld values.\n",aa,bb,wz,maax);
                                       //else printf("Between %lld and %lld, %lld generates the longest sequence of %lld value.\n",a,b,wz,maax);
									   }
    return 0;}
