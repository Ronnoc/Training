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

const int MXN = 22+5;
template <typename T> class Matrix{
    public:
    int n,m ;
    T a[MXN][MXN];
    Matrix() {memset(a , 0 , sizeof(a));}
    Matrix(int _n , int _m) {
        n = _n , m = _m , memset(a , 0 , sizeof(a));
    };
    T* operator[] (int i) {return a[i];}
    Matrix friend operator * (Matrix A , Matrix B){
        Matrix ans(A.n , B.m);
        for (int i = 0 ; i < A.n ; ++ i)
            for (int j = 0 ; j < A.m ; ++ j)if(A[i][j]!=0)
                for (int k = 0 ; k < B.m ; ++ k)
                    ans[i][k]=(ans[i][k]+A[i][j]*B[j][k])%MOD;
        return ans;
    }
};
void solve(){
	Matrix<LL>E,A;
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	E.n=E.m=A.n=A.m=(m+1)*2;
	rep(i,0,E.n)E[i][i]=1;
	rep(i,0,m+1)rep(j,0,2)rep(p,0,k)rep(q,0,k){
		int fi=(p==q)?i+1:0,fj=j;
		if(fi<=m){
			fj|=fi==m;
			A[i*2+j][fi*2+fj]++;
		}
	}
	while(n){
		if(n&1)E=A*E;
		A=A*A;
		n>>=1;
	}
	LL ans=0;
	rep(i,0,m+1)ans+=E[0][i*2+1];
	ans%=MOD;
	printf("%d\n",(int)ans);
}

int main(){
	int _T=1;
	scanf("%d",&_T);
	rep(CA,0,_T){
		//printf("Case #%d: ",CA+1);
		solve();
	}
	return 0;
}