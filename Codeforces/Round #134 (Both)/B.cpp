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
#define UsingFile 0

int main(){
    if(UsingFile)freopen(NAME".in","r",stdin);
    if(UsingFile)freopen(NAME".out","w",stdout);
    int i,j,k,_T;
    int n;
    while(~scanf("%d",&n)){
        vector<int>L;
        for(i=1;i*i<=n;i++)if(n%i==0)
            L.PB(i),L.PB(n/i);
        sort(L.OP,L.ED);
        L.erase(unique(L.OP,L.ED),L.ED);
        int v[11];
        memset(v,0,sizeof v);
        while(n){
            v[n%10]=1;
            n/=10;
        }
        int cnt=0;
        for(i=0;i<L.SZ;i++){
            int x=L[i];
            int got=0;
            while(x){
                if(v[x%10])got=1;
                x/=10;
            }
            if(got)cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}

