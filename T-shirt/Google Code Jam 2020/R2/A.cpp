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
void solve()
{
    LL L,R;
    bool swaped=false;
    cin>>L>>R;
    if(L<R)swap(L,R),swaped=true;//L>=R;
    LL diff = L-R;
    // (1+n)*n/2
    LL x = LL(sqrt(diff * 2));
    while (x * (x + 1) / 2 <= diff)x++;
    while(x*(x+1)/2>diff)x--;
    LL ans = x;
    L-=ans*(ans+1)/2;
    if(L==R)swaped=false;
    LL le=0,re=2000000000LL,ge;
    while(re>=le+1){
        if(re-le<=1){
            ge=le;break;
        }
        LL me=(le+re)/2;
        // L ans+1 ... ans+2*me-1
        // R ans+2 ... ans+2*me
        LL sl = (ans+1+ans+2*me-1)*me/2;
        LL sr = (ans+2+ans+2*me)*me/2;
        if(L>=sl && R>=sr)le=me;
        else re=me;
    }
    L-=(ans+1+ans+2*ge-1)*ge/2;
    R-=(ans+2+ans+2*ge)*ge/2;
    ans+=ge*2;
    if(swaped)swap(L,R);
    while(max(L,R)>=ans+1){
        if(R>L)R-=ans+1;
        else L-=ans+1;
        ans++;
    }
    cout<<ans<<" "<<L<<" "<<R<<"\n";
}

int main()
{
    int i, j, k, _T=1;
    scanf("%d", &_T);
    for (int CA = 1; CA <= _T; CA++)
    {
        printf("Case #%d: ", CA);
        solve();
    }
    return 0;
}