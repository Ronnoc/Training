#include<stdio.h>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long LL;

struct student
{
    LL sc,v;
    bool operator < (student A) const
    {
        return sc<A.sc;
    }
}st[100010];
priority_queue<LL>Q;
LL n,c,f;
LL s1[100010],s2[100010];

int main()
{
    //freopen("2.txt","r",stdin);
    LL i,m,sum;
    scanf("%I64d%I64d%I64d",&n,&c,&f);
    //while(~scanf("%I64d%I64d%I64d",&n,&c,&f)){
        for(i=1;i<=c;i++)
            scanf("%I64d%I64d",&st[i].sc,&st[i].v);
        sort(st+1,st+c+1);
        //for(i=1;i<=c;i++)printf("%I64d %I64d\n",st[i].sc,st[i].v);printf("\n");
        while(!Q.empty())Q.pop();
        m=(n-1)>>1;
        sum=0;
        for(i=1;i<=m;i++)
        {
            sum+=st[i].v;
            Q.push(st[i].v);
        }
        for(i=m+1;i<=c;i++)
        {
            s1[i]=sum;
            Q.push(st[i].v);
            sum=sum+st[i].v-Q.top();
            Q.pop();
        }
        sum=0;
        while(!Q.empty())Q.pop();
        for(i=c;i>c-m;i--)
        {
            sum+=st[i].v;
            Q.push(st[i].v);
        }
        for(i=c-m;i>=1;i--)
        {
            s2[i]=sum;
            Q.push(st[i].v);
            sum=sum+st[i].v-Q.top();
            Q.pop();
        }
        /*for(i=m+1;i<=c-m;i++)
            printf("%d %d\n",s1[i],s2[i]);*/
        for(i=c-m;i>=m+1;i--)
        {
            if(s1[i]+s2[i]+st[i].v<=f)break;
        }
        if(i<m+1)printf("-1\n");
        else printf("%I64d\n",st[i].sc);
    return 0;
}
