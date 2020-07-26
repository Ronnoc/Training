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
LL x[105],y[105];
void solve()
{
    DRI(N);
    int n=N;

    rep(i,0,N){
        cin>>x[i]>>y[i];
    }
    if(N<=4){
        cout<<" "<<N<<"\n";
        return;
    }
    int ans = 4;
    for(int i=0;i<N;++i)
        for(int j=i+1;j<N;++j){
            LL dx=x[j]-x[i],dy=y[j]-y[i];
            map<LL,int>cf;
            for(int k=0;k<N;++k){
                // y=dy/dx*x+b
                // dy*x+b*dx=y*dx
                LL f=y[k]*dx-x[k]*dy;
                if(cf.find(f)==cf.ED)cf[f]=0;
                cf[f]++;
            }
            int tmp=0,xxx=0;
            VI L;
            int c3=0,c1=0;
            for(auto pr:cf){
                int c=pr.BB;
                if(c==1)c1+=1;
            }
            if((n-c1)%2==0){
                if(c1>=2)tmp=n-(c1-2);
                else tmp=n;
            }else{
                if(c1>=1)tmp=n-(c1-1);
                else tmp=n;
            }
            cmax(ans,tmp);
            // cout<<tmp<<"\n";
        }
    cout << " " << ans << "\n";
}

int main()
{
    int i, j, k, _T=1;
    scanf("%d", &_T);
    for (int CA = 1; CA <= _T; CA++)
    {
        printf("Case #%d:", CA);
        solve();
    }
    return 0;
}