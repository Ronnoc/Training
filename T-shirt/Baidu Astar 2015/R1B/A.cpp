#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
#define MP make_pair
#define PB push_back
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
#define NAME ""
#define UsingFile 0

const int N = 100005;
int n;
LL x[N],y[N],t[N];
bool check(LL d){
    int i;
    LL le=x[n]+y[n]-d;
    LL re=x[n]+y[n]+d;
    for(i=n-1;i>=1;i--){
        LL dt=t[i+1]-t[i];
        le-=dt*2;
        re+=dt*2;
        LL li=x[i]+y[i]-d;
        LL ri=x[i]+y[i]+d;
        cmin(re,ri);
        cmax(le,li);
        if(le>re)return 0;
    }
    le=x[n]-y[n]-d;
    re=x[n]-y[n]+d;
    for(i=n-1;i>=1;i--){
        LL dt=t[i+1]-t[i];
        le-=dt*2;
        re+=dt*2;
        LL li=x[i]-y[i]-d;
        LL ri=x[i]-y[i]+d;
        cmin(re,ri);
        cmax(le,li);
        if(le>re)return 0;
    }
    return 1;
}
int main(){
    if(UsingFile)freopen(NAME".in","r",stdin);
    if(UsingFile)freopen(NAME".out","w",stdout);
    int i,j,k,_T;
    scanf("%d",&_T);
    for(int CA=1;CA<=_T;CA++){
        printf("Case #%d:\n",CA);
        scanf("%d",&n);
        vector<pair<LL,pair<LL,LL> > >L;
        for(i=1;i<=n;i++){
            LL a,b,c;
            scanf("%I64d%I64d%I64d",&a,&b,&c);
            a*=2;b*=2;
            L.PB(MP(c,MP(a,b)));
        }
        sort(L.OP,L.ED);
        for(i=0;i<L.SZ;i++)
            x[i+1]=L[i].BB.AA,y[i+1]=L[i].BB.BB,t[i+1]=L[i].AA;
        LL le=0,re=10000000000LL,ge=-1;
        while(re!=le){
            if(re-le<=1){
                if(check(le))ge=le;
                else ge=re;
                break;
            }
            LL mid=(le+re)>>1;
            if(check(mid))re=mid;
            else le=mid;
        }
        if(ge%2)printf("%I64d/2\n",ge);
        else printf("%I64d/1\n",ge/2);
    }
    return 0;
}

