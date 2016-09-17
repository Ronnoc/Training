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
const double PI = acos(-1.);
const double eps = 1e-9;
LL modPow(LL a,LL b,LL MOD){
    LL ret=1;for(;b;b>>=1){
        if(b&1)ret=ret*a%MOD;a=a*a%MOD;
    }return ret;
}

const int Maxn = 1<<17|1;
struct RMQ {
    int n;
    int st[17][Maxn];
    void init(int v[], int L) {
        int i, j, k;
        n = L;
        for(i = 0; i <= n; i++) st[0][i] = v[i];
        for(j = 1, k = 0; (1<<j) <= n; j++, k++) {
            for(i = 0; i + (1<<j) - 1<= n; i++) {
                st[j][i] = __gcd(st[j - 1][i], st[j - 1][i + (1<<k)]);
            }
        }
    }
    int query(int l, int r) {   //求[l, r]
        int k = 31 - __builtin_clz(r - l + 1);
        return __gcd(st[k][l], st[k][r - (1<<k) + 1]);
    }
}rmq;
inline int LB(int x) {return x & (-x);}
struct BIT {
    LL _[Maxn];
    int n;
    void init(int m) {
        n = m + 5;
        for (int i = 0; i <= n; i++)_[i] = 0;
    }
    LL query(int w) {
        LL ret = 0;
        for (w += 3; w > 0; w -= LB(w))ret += _[w];
        return ret;
    }
    void update(int w, LL d) {
        for (w += 3; w < n; w += LB(w))_[w] += d;
    }
    int find_Kth(int k) {        //UESTC_Dagon
        int ans=0,cnt=0;
        for(int i=22;i>=0;i--){
            ans+=1<<i;
            if(ans>=n||cnt+_[ans]>=k)ans-=1<<i;
            else cnt+=_[ans];
        }
        return ans - 2;
    }
}Y;
int a[Maxn];
vector<PII>G[Maxn];
int b[Maxn];
int main(){
    int N,Q;
    while(~scanf("%d%d",&N,&Q)){
        for(int i=1;i<=N;i++)G[i].clear();
        for(int i=1;i<=N;i++)scanf("%d",&a[i]);
        for(int i=1;i<=Q;i++){
            int l,r;
            scanf("%d%d",&l,&r);
            G[r].PB(MP(l,i));
        }
        rmq.init(a,N);
        Y.init(N);
        map<int,int>F;
        for(int i=1;i<=N;i++){
            int right=i;
            vector<PII>tmp;
            while(right>=1){
                int aim=rmq.query(right,i);
                if(F.find(aim)==F.ED||F[aim]<right){
                    if(F.find(aim)!=F.ED)
                        Y.update(F[aim],-1);
                    Y.update(F[aim]=right,1);
                }
                int le=1,re=right,ge=-1;
                while(re>=le){
                    if(re-le<=1){
                        if(rmq.query(le, i)==aim)ge=le;
                        else ge=re;
                        break;
                    }
                    int me=(le+re)/2;
                    if(rmq.query(me,i)==aim)re=me;
                    else le=me;
                }
                right=ge-1;
            }
            rep(j,0,G[i].SZ){
                int id=G[i][j].BB;
                int le=G[i][j].AA;
                b[id]=Y.query(i)-Y.query(le-1);
            }
        }
        rep(i,1,Q+1)printf("%d\n",b[i]);
    }
    return 0;
}