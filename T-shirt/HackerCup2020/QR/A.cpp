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
#define RI(X) scanf("%d", &(X))
#define DRI(X) int (X); scanf("%d", &X)
#define rep(i,a,n) for(int i=(a);i<(int)(n);i++)
#define repd(i,a,b) for(int i=(a);i>=(b);i--)
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
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
const LL MOD = 1000000007;
const long double PI = acos(-1.);
const long double eps = 1e-9;
LL modPow(LL a,LL b,LL MOD){
    LL ret=1;for(;b;b>>=1){
        if(b&1)ret=ret*a%MOD;a=a*a%MOD;
    }return ret;
}
string I,O;
int vis[55][55];
void solve()
{
    DRI(n);
    cin>>I>>O;
    memset(vis,0,sizeof vis);
    rep(i,0,n)vis[i][i]=1;
    rep(i,0,n){
        for(int j=i+1;j<n;++j){
            if(vis[i][j-1]&&O[j-1]=='Y'&&I[j]=='Y'){
                vis[i][j]=1;
            }else break;
        }
    }
    for(int i=n-1;i>=0;--i){
        for(int j=i-1;j>=0;--j){
            if(vis[i][j+1]&&O[j+1]=='Y'&&I[j]=='Y'){
                vis[i][j]=1;
            }else break;
        }
    }
    rep(i,0,n){
        rep(j,0,n){cout<<(vis[i][j]?'Y':'N'); }
        cout<<"\n";
    }
}

int main()
{
    int i, j, k, _T=1;
    scanf("%d", &_T);
    for (int CA = 1; CA <= _T; CA++)
    {
        printf("Case #%d:\n", CA);
        solve();
    }
    return 0;
}