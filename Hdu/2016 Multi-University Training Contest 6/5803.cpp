#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<cstdlib>
#include<cctype>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
#include<sstream>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<fstream>
#include<numeric>
#include<iomanip>
#include<bitset>
#include<list>
#include<stdexcept>
#include<functional>
#include<utility>
#include<ctime>
#include<cassert>
using namespace std;
#define rep(i,a,n) for(int i=(a);i<(int)(n);i++)
#define repd(i,a,b,d) for(int i=(a);i!=(b);i+=d)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define MP make_pair
#define PB push_back
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VL;
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
const LL MOD = 1000000007;
const double PI = acos(-1.);
const double eps = 1e-9;
LL modPow(LL a,LL b,LL MOD){
    LL ret=1;for(;b;b>>=1){
        if(b&1)ret=ret*a%MOD;a=a*a%MOD;
    }return ret;
}
int f[61][5][5][16];
int dig[4][61];
int fit(int w){
    return min(max(w,-2),2);
}
int dfs(int id,int s1,int s2,int even=15){
    if(id==-1)return s1>0&&s2>=0;
    int &ret=f[id][s1+2][s2+2][even];
    if(~ret)return ret;
    ret=0;
    int t[4];
    rep(i,0,4)t[i]=(even>>i&1)?dig[i][id]:1;
    rep(x0,0,t[0]+1){
        rep(x1,0,t[1]+1){
            rep(x2,0,t[2]+1){
                rep(x3,0,t[3]+1){
                    int mask=even;
                    mask&=(x0==dig[0][id])<<0
                        |(x1==dig[1][id])<<1
                        |(x2==dig[2][id])<<2
                        |(x3==dig[3][id])<<3;
                    ret+=dfs(id-1,fit(s1*2+x0+x2-x1-x3),fit(s2*2+x0+x3-x1-x2),mask);
                    if(ret>=MOD)ret-=MOD;
                }
            }
        }
    }
    return ret;
}
const int MXN = 100005;

void solve(){
    memset(f,-1,sizeof f);
    memset(dig,0,sizeof dig);
    LL A[4];
    int t[4];
    rep(i,0,4){
        cin>>A[i];
        t[i]=0;
        while(A[i]){
            dig[i][t[i]++]=A[i]&1;
            A[i]>>=1;
        }
    }
    int ndig=*max_element(t,t+4);
    int ans=dfs(--ndig,0,0);
    printf("%d\n",ans);
}

int main(){
    std::ios::sync_with_stdio(false);
    int _T=1;
    cin>>_T;
    rep(CA,0,_T){
        solve();
    }
    return 0;
}