//#pragma comment(linker, "/STACK:1024000000,1024000000")
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

const double PI = acos(-1.);
const double eps = 1e-9;
LL modPow(LL a,LL b,LL MOD){
	LL ret=1;for(;b;b>>=1){
		if(b&1)ret=ret*a%MOD;a=a*a%MOD;
	}return ret;
}

const int MXN = 100005;
const int MAT = 7;
LL MOD = 1000000007;
template <typename T> class Matrix{
    public:
    int n,m;
    T a[MAT][MAT];
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
LL G(LL a,LL b){
	Matrix<LL>E(6,6),Z(6,6);
	rep(i,0,6)E[i][i]=1;
	Z[0][1]=1;
	Z[1][0]=1;Z[1][1]=2;
	Z[2][3]=1;
	Z[3][2]=1;Z[3][3]=Z[3][4]=4;
	Z[4][3]=2;Z[4][4]=1;
	Z[5][3]=Z[5][5]=1;
	MOD = b;
	while(a){
		if(a&1)E=E*Z;
		Z=Z*Z;
		a>>=1;
	}
	return E[5][3];
}
int p[MXN], pn;
bool flag[MXN];	//true为合数
//for(inv[1]=1,i=2;i<10000;i++)inv[i]=inv[MOD%i]*(MOD-MOD/i)%MOD;//MOD is prime
void sieve(int n) {
	pn = 0;
	for (int i = 2; i <= n; i++) {
		if (!flag[i]) {
			p[pn ++ ] = i;
		}
		for (int j = 0; j < pn && i * p[j] <= n; j++) {
			flag[i * p [j]] = true;
			if (i % p[j] == 0) 
				break;
		}
	}
}
int eulerPhi (int n) {			// test: phi(846720)=193536
	int res = n;
	for (int j = 0; p[j] * p[j] <= n; j++){		//可用质数加速
		int i=p[j];
		if (n % i == 0) {
			res = res / i * (i - 1);
			for (; n % i == 0; n /= i);
		}
	}
	if (n != 1) res = res / n * (n - 1);
	return res;
}
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
//模同余方程组中国剩余定理
//>验题:poj2891
//a_i*x=b_i {%m_i}  m_i可以不互质
//pair<b,m>			x=b {%m}
pair<LL, LL> linearMod( vector<LL>&A, vector<LL>&B, vector<LL>&M ) {
	LL x = 0, m = 1;
	for ( int i = 0; i < A.SZ; i++ ) {
		LL a = A[i] * m, b = B[i] - A[i] * x, d = __gcd( M[i], a );
		if ( b % d )return MP( 0, -1 );
		LL t = b / d * modInv( a / d, M[i] / d ) % ( M[i] / d );
		x += m * t;
		m *= M[i] / d;
		x %= m;
	}
	return MP( ( ( x % m ) + m ) % m, m );
}
map<int,int> gao_yz(int x){
	map<int,int>ret;
	rep(j,0,pn){
		if(p[j]*p[j]>x)break;
		int cnt=0;
		while(x%p[j]==0)x/=p[j],cnt++;
		if(cnt)ret[p[j]]=cnt;
	}
	if(x>1)ret[x]=1;
	return ret;
}

void solve(){
	int _n,_y,_x,_s;
	scanf("%d%d%d%d",&_n,&_y,&_x,&_s);
	LL n(_n),y(_y),x(_x),s(_s+1);
	LL ny=n*y;
	map<int,int>fs=gao_yz(s),fx=gao_yz(x);
	LL ans=1;
	LL phi = eulerPhi(s);
	for(map<int,int>::iterator it=fx.OP;it!=fx.ED;++it){
		LL p=(*it).AA;
		LL q=(*it).BB;
		if(fs.find(p)!=fs.ED){
			LL sq=fs[p];
			LL spq=1;
			rep(i,0,sq)spq*=p;
			LL aphi=phi/(spq/p*(p-1));
			LL part_ans=modPow(p,q*G(ny,aphi)%aphi,s);
			LL gny=30;
			if(ny==0)gny=0;
			if(ny==1)gny=1;
			if(ny==2)gny=5;
			LL qgny=q*gny;
			LL rp;
			if(qgny>=sq)rp=0;
			else rp=modPow(p,qgny,spq);
			VL A,B,M;
			A.PB(1LL);B.PB(rp);M.PB(spq);
			A.PB(1LL);B.PB(part_ans);M.PB(s/spq);
			PLL crt=linearMod(A, B, M);
			ans=ans*crt.AA%s;
		}else {
			ans=ans*modPow(p, q*G(ny,phi)%phi, s)%s;
		}
	}
	cout<<ans<<"\n";
}

int main(){
	sieve(MXN-5);
	int _T=1;
	scanf("%d",&_T);
	rep(CA,0,_T){
		//printf("Case #%d: ",CA+1);
		solve();
	}
	return 0;
}
