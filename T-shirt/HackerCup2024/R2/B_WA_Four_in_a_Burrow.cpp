#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
#include <cassert>
using namespace std;
#define RI(X) scanf("%d", &(X))
#define DRI(X) \
  int(X);      \
  scanf("%d", &X)
#define rep(i, a, n) for (int i = (a); i < (int)(n); i++)
#define repd(i, a, b) for (int i = (a); i >= (b); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define MP make_pair
#define PB push_back
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
const LL MOD = 1000000007;
const long double PI = acos(-1.);
const long double eps = 1e-9;
LL modPow(LL a, LL b, LL MOD)
{
  LL ret = 1;
  for (; b; b >>= 1)
  {
    if (b & 1)
      ret = ret * a % MOD;
    a = a * a % MOD;
  }
  return ret;
}

string st[9];
int g[9];
int vis[2][2];


int dx[4]={1,1,0,-1};
int dy[4]={0,1,1,1};

inline bool valid(int x,int y){
    return x>=0&&x<6&&y>=0&&y<7&&x>=g[y];
}

void dfs(int j){
    if(j==7){
        int win_c=0;
        int win_f=0;

        int count_c=0, count_f=0;
        rep(x,0,6)rep(y,0,7)if(x>=g[y]){
            if(st[x][y]=='C')count_c++;
            if(st[x][y]=='F')count_f++;
        }
        if(count_c==0)return;
        if(count_c==count_f){
            // any is f
            bool any_f = 0;
            rep(y,0,7)if(g[y]<6&&st[g[y]][y]=='F')any_f=1;
            if(!any_f)return;
        }else if (count_c == count_f+1){
            // any is c
            bool any_c = 0;
            rep(y,0,7)if(g[y]<6&&st[g[y]][y]=='C')any_c=1;
            if(!any_c)return;
        }else {
            return;
        }
        rep(x,0,6){
            rep(y,0,7)if(x>=g[y]){
                rep(di,0,4){
                    int fail=0;
                    for(int b=3;b>=1;b--){
                        int nx=x+dx[di]*b;
                        int ny=y+dy[di]*b;
                        if(!valid(nx,ny)){
                            fail=1;
                            break;
                        }
                    }
                    if(!fail){
                        int cf=0;
                        for(int b=3;b>=0;b--){
                            int nx=x+dx[di]*b;
                            int ny=y+dy[di]*b;
                            if(st[nx][ny]=='C')cf|=1;
                            if(st[nx][ny]=='F')cf|=2;
                        }
                        win_c|=(cf==1);
                        win_f|=(cf==2);
                    }
                }
            }
        }
        vis[win_c][win_f]=1;
        return;
    }
    for(int i=6;i>=0;i--){
        g[j]=i;
        dfs(j+1);
    }
}

void solve(){
    rep(i,0,6)cin>>st[i];
    memset(vis,0,sizeof vis);
    dfs(0);
    if(!vis[1][0]&&!vis[0][1]&&!vis[1][1]){
        printf("0\n");
        // printf("Nobody wins.\n");
    }else if(vis[1][0]&&!vis[0][1]){
        printf("C\n");
        // printf("C wins.\n");
    }else if(!vis[1][0]&&vis[0][1]){
        printf("F\n");
        // printf("F wins.\n");
    }else {
        printf("?\n");
        // printf("CF draw.\n");
    }
}

int main()
{
  int i, j, k, _T = 1;
  scanf("%d", &_T);
  for (int CA = 1; CA <= _T; CA++)
  {
    printf("Case #%d: ", CA);
    solve();
    cerr << "Case #" << CA << " of " << _T << " done." << endl;
  }
  fflush(stdout);
  return 0;
}