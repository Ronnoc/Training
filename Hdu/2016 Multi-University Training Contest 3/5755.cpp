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
const double PI = acos(-1.);
const double eps = 1e-9;
LL modPow(LL a,LL b,LL MOD){
    LL ret=1;for(;b;b>>=1){
        if(b&1)ret=ret*a%MOD;a=a*a%MOD;
    }return ret;
}
#define MXN 999
int idx[MXN];
LL a[MXN][MXN], b[MXN];
int gaussTpivotMod(int m, int n) { //mod 下高斯消
    int i, j, k, row, col;
    LL maxp, t;
    int ret = 1;
    for (i = 0; i < m; i++)idx[i] = i;
    for (k = 0; k < n; k++) {
        for (maxp = 0, i = k; i < m; i++)
            for (j = k; j < n; j++)
                if (a[i][j] > maxp)
                    maxp = a[row = i][col = j];
        if (maxp == 0) 
            break;
        if (col != k)for (swap(idx[col], idx[k]), i = 0; i < m; i++)
                swap(a[i][col], a[i][k]);
        if (row != k)for (swap(b[k], b[row]), j = k; j < n; j++)
                swap(a[k][j], a[row][j]);
        rep(j,k,n)a[k][j]*=maxp;
        b[k]*=maxp;
        for (i = k + 1; i < m; i++) {
            LL mul = a[i][k];
            for (j = k; j < n; j++)
                a[i][j] -= a[k][j] * mul;
            b[i] -= mul * b[k];
        }
        rep(i,0,n)rep(j,0,n)a[i][j]=(a[i][j]%3+3)%3;
        rep(i,0,n)b[i]=(b[i]%3+3)%3;
    }
    for (i = n - 1; i >= 0; i--)
        for (j = i + 1; j < n; j++)
            b[i] -= a[i][j] * b[j];
    for (k = 0; k < n; k++)
        a[0][idx[k]] = b[k];
    for (k = 0; k < n; k++)
        b[k] = (a[0][k] % 3 + 3) % 3;
    return ret;
}

int w[33][33];
int k[33][33][33];
int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};
int add[33][33][33];
int c[33][33];
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
    rep(j,1,m){
        rep(i,0,n)rep(kk,0,n+1)add[i][j][kk]=(3-k[i][j-1][kk]%3)%3;
        rep(i,0,n){
            rep(kk,0,n+1)
                k[i][j][kk]+=2*add[i][j][kk];
            rep(t,0,4){
                int x=i+dx[t];
                int y=j+dy[t];
                if(x<0||x>=n)continue;
                if(y<0||y>=m)continue;
                rep(kk,0,n+1)
                    k[x][y][kk]+=add[i][j][kk];
            }
        }
        rep(i,0,n)rep(kk,0,n+1)k[i][j][kk]%=3;
    }
    rep(i,0,n)rep(j,0,m){
        rep(kk,0,n)a[i][kk]=(3+k[i][m-1][kk]%3)%3;
        b[i]=(3-k[i][m-1][n]%3)%3;
    }
    int gg=gaussTpivotMod(n,n);
    int sum=0;
    rep(i,0,n)c[i][0]=b[i];
    rep(i,0,n)rep(j,1,m){
        c[i][j]=add[i][j][n];
        rep(kk,0,n)c[i][j]+=add[i][j][kk]*b[kk];
    }
    rep(i,0,n)rep(j,0,m){
        c[i][j]=(c[i][j]%3+3)%3;
        sum+=c[i][j];
    }
    printf("%d\n",sum);
    rep(i,0,n)rep(j,0,m)rep(k,0,c[i][j]){
        printf("%d %d\n",i+1,j+1);
        w[i][j]+=2;
        rep(t,0,4){
            int x=i+dx[t];
            int y=j+dy[t];
            if(x<0||x>=n)continue;
            if(y<0||y>=m)continue;
            w[x][y]++;
        }
    }/*
    rep(i,0,n){
        rep(j,0,m)cout<<w[i][j]%3<<" ";
        cout<<"\n";
    }*/
}

/*
1 2 2
2 1
1 1
*/
int main(){
    int _T=1;
    scanf("%d",&_T);
    rep(CA,0,_T){
        solve();
    }
    return 0;
}