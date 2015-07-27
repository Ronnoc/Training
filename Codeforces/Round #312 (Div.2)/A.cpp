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
        vector<pair<int,int> >L,R;
        for(i=0;i<n;i++){
            int x,a;
            scanf("%d%d",&x,&a);
            if(x<0)L.PB(MP(-x,a));
            else R.PB(MP(x,a));
        }
        sort(L.OP,L.ED);
        sort(R.OP,R.ED);
        int ans=0;
        if(L.SZ<=R.SZ){
            for(i=0;i<L.SZ;i++)ans+=L[i].BB;
            for(i=0;i<L.SZ+1&&i<R.SZ;i++)ans+=R[i].BB;
        }else {
            for(i=0;i<R.SZ;i++)ans+=R[i].BB;
            for(i=0;i<R.SZ+1&&i<L.SZ;i++)ans+=L[i].BB;
        }
        cout<<ans<<"\n";
    }
    return 0;
}

