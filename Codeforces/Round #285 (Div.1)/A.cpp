#include<bits/stdc++.h>
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

int d[1<<16],s[1<<16];
int main(){
    //    freopen(NAME".in","r",stdin);
    //    freopen(NAME".out","w",stdout);
    int i,j,k,_T;
    int n;
    while(~scanf("%d",&n)){
        set<PII>S;
        for(i=0;i<n;i++)scanf("%d%d",&d[i],&s[i]);
        for(i=0;i<n;i++)
            S.insert(MP(d[i],i));
        vector<PII>E;
        while(!S.empty()){
            PII tp=*S.begin();
            int p=tp.BB,q=s[tp.BB];
            S.erase(S.find(MP(d[p],p)));
            if(d[p]==0)continue;
            S.erase(S.find(MP(d[q],q)));
            s[p]^=q,s[q]^=p;
            d[p]--,d[q]--;
            S.insert(MP(d[q],q));
            E.PB(MP(p,q));
        }
        printf("%d\n",E.SZ);
        for(i=0;i<E.SZ;i++)
            printf("%d %d\n",E[i].AA,E[i].BB);
    }
    return 0;
}

