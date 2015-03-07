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

int main(){
    if(!VER)freopen(NAME".in","r",stdin);
    if(!VER)freopen(NAME".out","w",stdout);
    int i,j,k,_T;
    int n;
    while(~scanf("%d%d",&n,&k)){
        int ans=0;
        while(n--){
            scanf("%d",&i);
            int cnt=0;
            while(i){
                if(i%10==4||i%10==7)cnt++;
                i/=10;
            }
            if(cnt<=k)ans++;
        }
        cout<<ans<<"\n";
    }
    return 0;
}

