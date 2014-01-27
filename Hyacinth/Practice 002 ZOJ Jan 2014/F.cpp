#include<stdio.h>
#include<math.h>
#include<iomanip>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long double LD;
const LD eps=1e-11;
int d[6];

LD _sqrt(LD t)
{
    LD l,r,i,mid;
    l=sqrt(t)-1e-7;r=sqrt(t)+1e-7;
    for(i=1;i<=12;i++)
    {
        mid=(l+r)/2;
        if(mid*mid<t+eps)l=mid;
        else r=mid;
    }
    return r;
}
LD ss(int a,int b,int c)
{
    if(a>b)swap(a,b);
    if(c<=b-a || c>=a+b)return -1.0;
    LD p=(a+b+c+0.0)/2,tt;
    tt=p*(p-a)*(p-b)*(p-c);
    return _sqrt(tt);
}
LD get()
{
    int i,j,k,l,a,b,c;
    LD S,ret=0;
    for(i=0;i<6;i++)
        for(j=i+1;j<6;j++)
            for(k=j+1;k<6;k++)
            {
                a=0;b=0;c=0;
                for(l=i;l<j;l++)
                    a+=d[l];
                for(l=j;l<k;l++)
                    b+=d[l];
                for(l=k;l<6;l++)
                    c+=d[l];
                for(l=0;l<i;l++)
                    c+=d[l];
                S=ss(a,b,c);
                ret=max(S,ret);
            }
    return ret;
}
int main()
{
    //freopen("2.txt","r",stdin);
    int l[3],r[3],i,j,k,kk;
    LD ans;
    while(~scanf("%d%d%d%d%d%d",&l[0],&r[0],&l[1],&r[1],&l[2],&r[2]))
    {
        ans=0;
        for(i=0;i<8;i++)
        {
            for(j=0;j<3;j++)
            {
                if(i&1)
                {
                    d[0]=l[j];
                    d[1]=r[j];
                }
                else
                {
                    d[0]=r[j];
                    d[1]=l[j];
                }
                for(k=0;k<3;k++)
                {
                    if(k==j)continue;
                    if(i&2)
                    {
                        d[2]=l[k];
                        d[3]=r[k];
                    }
                    else
                    {
                        d[2]=r[k];
                        d[3]=l[k];
                    }
                    for(kk=0;kk<3;kk++)
                    {
                        if(kk==j || kk==k)continue;
                        if(i&4)
                        {
                            d[4]=l[kk];
                            d[5]=r[kk];
                        }
                        else
                        {
                            d[4]=r[kk];
                            d[5]=l[kk];
                        }
                        ans=max(ans,get());
                    }
                }
            }
        }
        cout<<setprecision(15)<<ans<<endl;
    }
    return 0;
}
