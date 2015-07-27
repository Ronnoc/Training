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
        vector<int>L,R;
        for(i=0;i<n;i++){
            scanf("%d",&k);
            L.PB(k),R.PB(k);
        }
        sort(R.OP,R.ED);
        int cnt=0;
        for(i=0;i<L.SZ;i++){
            cnt+=L[i]!=R[i];
        }
        if(cnt<=2)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}

