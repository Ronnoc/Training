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

#define rep(i,a,n) for(int i=(a);i<(int)(n);i++)
#define MXN 33
int idx[MXN];
LL a[MXN][MXN], b[MXN];
LL extGcd (LL a, LL b, LL &x, LL &y) {
    LL ret = a;
    if (b) {
        ret = extGcd (b, a % b, y, x);
        y -= (a / b) * x;
    } else x = 1, y = 0;
    return ret;
}
LL modInv (LL a, LL m) {
    LL x, y;
    extGcd(a, m, x, y);
    return (m + x % m) % m;
}

void fit(LL &a,LL mod){a=(a%mod+mod)%mod;}
pair<LL,LL>singleMod(LL A,LL B,LL M){
    LL d = __gcd( M, A );
    if ( B % d )return MP( 0, -1 );
    LL m = M / d;
    LL t = B / d * modInv( A / d, m ) % m;
    return MP( ( ( t % m ) + m ) % m, m );
}
int gaussTpivotMod(int m, int n, LL mod) { //mod 下高斯消
    int ret = 0,fail = 0;
    rep(i,0,m){
        idx[i]=i;
        fit(b[i],mod);
        rep(j,0,n)fit(a[i][j],mod);
    }
    rep(k,0,n){
        LL maxp=0;int row,col;
        rep(i,k,m)rep(j,k,n)if(maxp==0)
            maxp=a[row=i][col=j];
        if(maxp==0){
            rep(i,k,m)fail|=b[i]!=0;
            if(fail)return -1;
            ret=n-k;
            break;
        }
        swap(idx[col],idx[k]);
        rep(i,0,m)swap(a[i][col],a[i][k]);
        swap(b[k], b[row]);
        rep(j,k,n)swap(a[k][j], a[row][j]);
        rep(i,k+1,m){
            while(a[i][k]){
                if(a[i][k]<a[k][k]){
                    swap(b[k],b[i]);
                    rep(j,0,n)swap(a[k][j], a[i][j]);
                }
                LL cnt=a[i][k]/a[k][k];
                rep(j,0,n)a[i][j]-=cnt*a[k][j];
                b[i]-=cnt*b[k];
                rep(j,0,n)fit(a[i][j],mod);
                fit(b[i],mod);
            }
        }
    } 
    for (int i = n - 1; i >= 0; i--){
        rep(j,i+1,n)
            b[i] -= a[i][j] * b[j];
        if(a[i][i])
            b[i]=singleMod(a[i][i],b[i],mod).AA;
    }
    rep(k,0,n)a[0][idx[k]] = b[k];
    rep(k,0,n)b[k]=a[0][k];
    rep(k,0,n)fit(b[k],mod);
    return ret;
}
int w[33][33];
int k[33][33][33];
int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};
int add[33][33][33];
LL c[33][33];
void solve(){
    int n,m;
    scanf("%d%d",&n,&m);
    rep(i,0,n)rep(j,0,m)scanf("%d",&w[i][j]);
    memset(k,0,sizeof(k));
    rep(i,0,n){
        int j=0;
        k[i][j][i]+=2;
        rep(t,0,4){
            int x=i+dx[t];
            int y=j+dy[t];
            if(x<0||x>=n)continue;
            if(y<0||y>=m)continue;
            k[x][y][i]++;
        }
    }
    rep(i,0,n)rep(j,0,m)k[i][j][n]=w[i][j];
    rep(j,1,m)rep(i,0,n){
        rep(kk,0,n+1)add[i][j][kk]=(3-k[i][j-1][kk]%3)%3;
        rep(kk,0,n+1)
            k[i][j][kk]+=2*add[i][j][kk];
        rep(t,0,4){
            int x=i+dx[t];
            int y=j+dy[t];
            if(x<0||x>=n)continue;
            if(y<0||y>=m)continue;
            rep(kk,0,n+1)
                k[x][y][kk]+=add[i][j][kk];
        }rep(kk,0,n+1)k[i][j][kk]%=3;
    }
    rep(i,0,n)rep(j,0,m){
        rep(kk,0,n)a[i][kk]=(3+k[i][m-1][kk]%3)%3;
        b[i]=(3-k[i][m-1][n]%3)%3;
    }
    int gg=gaussTpivotMod(n,n,3);
    rep(i,0,n)c[i][0]=b[i];
    rep(i,0,n)rep(j,1,m){
        c[i][j]=add[i][j][n];
        rep(kk,0,n)c[i][j]+=add[i][j][kk]*b[kk];
    }
    int sum=0;
    rep(i,0,n)rep(j,0,m){
        fit(c[i][j],3);
        sum+=c[i][j];
    }
    printf("%d\n",sum);
    rep(i,0,n)rep(j,0,m)rep(k,0,c[i][j])
        printf("%d %d\n",i+1,j+1);
}

int main(){
    int _T=1;
    scanf("%d",&_T);
    rep(CA,0,_T){
        solve();
    }
    return 0;
}