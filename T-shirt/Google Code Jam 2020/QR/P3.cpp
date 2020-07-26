#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <map>
#include <stdio.h>
#include <string.h>
#include <set>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define MP make_pair
#define PB push_back
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
const LL MOD = 1000000007;
const double PI = acos(-1.);
const double eps = 1e-9;

vector<int>G[1005];
int c[1005];

int dfs(int u,int w){
    c[u]=w;
    int rtn=0;
    for(auto v:G[u]){
        if(c[v]==-1){
            rtn=rtn|dfs(v,w^1);
        }else if(c[v]==w){
            rtn=1;
        }
    }
    return rtn;
}

void solve()
{
    int n;
    scanf("%d",&n);
    vector<PII>L;
    for (int i = 0; i < n; i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        L.PB(MP(a,b));
        G[i].clear();
        for(int j=0;j<i;j++){
            // [L[j].AA,L[j].BB) [a,b)
            if(a<L[j].BB && L[j].AA<b){
                G[i].PB(j);
                G[j].PB(i);
            }
        }
    }
    memset(c,-1,sizeof(c));
    int fail=0;
    for(int i=0;i<n;++i){
        if(c[i]==-1){
            int rtn = dfs(i,0);
            if(rtn==1)
                fail=1;
        }
    }
    if(fail){
        printf("IMPOSSIBLE\n");
    }else{
        for(int i=0;i<n;++i){
            if (c[i] == 0)
                printf("%c", 'C');
            else
                printf("%c", 'J');
        }
        printf("\n");
    }
}

int main()
{
    int i, j, k, _T;
    scanf("%d", &_T);
    for (int CA = 1; CA <= _T; CA++)
    {
        printf("Case #%d: ", CA);
        solve();
    }
    return 0;
}