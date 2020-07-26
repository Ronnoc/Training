#include <vector>
#include <cmath>
#include <stdio.h>
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


int f[105][105];
void solve()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            scanf("%d",&f[i][j]);
    int a=0,b=0,c=0;
    for(int i=0;i<n;++i)
        a+=f[i][i];
    for(int i=0;i<n;++i){
        set<int>P,Q;
        for(int j=0;j<n;++j){
            P.insert(f[i][j]);
            Q.insert(f[j][i]);
        }
        if(P.size()!=n)b++;
        if(Q.size()!=n)c++;
    }
    printf("%d %d %d\n",a,b,c);
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
