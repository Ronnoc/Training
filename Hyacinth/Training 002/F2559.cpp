#include<stdio.h>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
#define AA first
#define BB second
#define MP make_pair

deque<pair<LL,LL> >Q;
LL n;
LL a[100010],l[100010],r[100010];

int main()
{
    //freopen("2.txt","r",stdin);
    LL i,ans;
    pair<LL,LL>A;
    while(1)
    {
        scanf("%I64d",&n);
        if(n==0)break;
        for(i=1;i<=n;i++)
            scanf("%I64d",&a[i]);
        Q.clear();
        Q.push_back(MP(0LL,-1LL));
        for(i=1;i<=n;i++)
        {
            while(!Q.empty())
            {
                A=Q.back();
                if(A.BB>a[i])Q.pop_back();
                else break;
            }
            A=Q.back();
            l[i]=i-A.AA;
            Q.push_back(MP(i,a[i]));
        }

        Q.clear();
        Q.push_back(MP(n+1,-1LL));
        for(i=n;i>=1;i--)
        {
            while(!Q.empty())
            {
                A=Q.back();
                if(A.BB>=a[i])Q.pop_back();
                else break;
            }
            A=Q.back();
            r[i]=A.AA-i;
            Q.push_back(MP(i,a[i]));
        }
        ans=0;
        for(i=1;i<=n;i++)
        {
            //printf("%I64d %I64d\n",l[i],r[i]);
            ans=max(ans,a[i]*(l[i]+r[i]-1));
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
