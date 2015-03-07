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
#define VER 1

int n,a[100005];
int f[100005];
int main(){
    if(!VER)freopen(NAME".in","r",stdin);
    if(!VER)freopen(NAME".out","w",stdout);
    int i,j,k,_T;
    while(~scanf("%d",&n)){
        for(i=1;i<=n;i++)scanf("%d",&a[i]);
        for(i=1;i<=n;i++)f[a[i]]=i;
        int m;
        LL p=0,q=0;
        scanf("%d",&m);
        while(m--){
            scanf("%d",&k);
            p+=f[k];
            q+=n+1-f[k];
        }
        cout<<p<<" "<<q<<"\n";
    }
    return 0;
}

