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

int w[106];
int dp[105][10005];
int main(){
    int i,j,k,n;
    while(~scanf("%d%d",&n,&k)){
        for(i=1;i<=n;i++)scanf("%d",&w[i]);
        vector<PII>L;
        for(i=1;i<=n;i++)L.PB(MP(w[i],i));
        sort(L.OP,L.ED);
        vector<int>Z;
        for(i=0;i<L.SZ;i++)
            if(k>=L[i].AA){
                k-=L[i].AA;
                Z.PB(L[i].BB);
            }
        sort(Z.OP,Z.ED);
        printf("%d\n",Z.SZ);
        for(i=0;i<Z.SZ;i++)printf("%d ",Z[i]);
        printf("\n");
    }
    
    return 0;
}

