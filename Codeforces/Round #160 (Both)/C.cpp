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

int a[100005],n,m;
int main(){
    if(!VER)freopen(NAME".in","r",stdin);
    if(!VER)freopen(NAME".out","w",stdout);
    int i,j,k,_T;
    while(~scanf("%d",&m)){
        int f=100005;
        for(i=1;i<=m;i++){
            scanf("%d",&k);
            cmin(f,k);
        }
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        reverse(a,a+n);
        LL ans=0;
        for(i=0;i<n;){
            for(j=0;i<n&&j<f;j++,i++)
                ans+=a[i];
            for(j=0;i<n&&j<2;j++,i++);
        }
        cout<<ans<<"\n";
    }
    return 0;
}

