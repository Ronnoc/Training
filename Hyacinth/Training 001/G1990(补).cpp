#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define AA first
#define BB second
typedef long long LL;

LL c[20010],d[20010],n,m;
pair<LL,LL>cow[20010];

bool cmp(pair<LL,LL>X,pair<LL,LL>Y)
{
    if(X.AA!=Y.AA)return X.AA<Y.AA;
    return X.BB<Y.BB;
}
LL lowbit(LL t)
{
    return t&(-t);
}
void add(LL k)
{
    LL t=k;
    while(k<=m)
    {
        c[k]+=1;
        d[k]+=t;
        k+=lowbit(k);
    }
}
LL sumc(LL k)
{
    LL sum=0;
    while(k>0){sum+=c[k];k-=lowbit(k);}
    return sum;
}
LL sumd(LL k)
{
    LL sum=0;
    while(k>0){sum+=d[k];k-=lowbit(k);}
    return sum;
}
int main()
{
    LL i,j,sum1=0,sum2=0,w,ans=0;
    scanf("%I64d",&n);
    for(i=1;i<=n;i++)
        scanf("%I64d%I64d",&cow[i].AA,&cow[i].BB);
    sort(cow+1,cow+n+1,cmp);
    m=20000;
    for(i=1;i<=n;i++)
    {
        w=sumc(cow[i].BB)*cow[i].BB-sumd(cow[i].BB);
        //printf("%I64d %I64d\n",i,w);
        w+=sum2-sumd(cow[i].BB)-(sum1-sumc(cow[i].BB))*cow[i].BB;
        //printf("%I64d %I64d %I64d %I64d\n",i,w,sumc(cow[i].BB),sumd(cow[i].BB));
        ans+=cow[i].AA*w;
        sum1++;
        sum2+=cow[i].BB;
        add(cow[i].BB);
    }
    printf("%I64d\n",ans);
    return 0;
}
