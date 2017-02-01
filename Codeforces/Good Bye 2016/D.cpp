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
const LL MOD = 1000000007;
const double PI = acos(-1.);
const double eps = 1e-9;
LL modPow(LL a,LL b,LL MOD){
	LL ret=1;for(;b;b>>=1){
		if(b&1)ret=ret*a%MOD;a=a*a%MOD;
	}return ret;
}

const int MXN = 100005;
int mp[505][505];
int t[33];
int MDX[8]={0,1,1,1,0,-1,-1,-1};
int MDY[8]={1,1,0,-1,-1,-1,0,1};
void solve(){
	int n;
	while(~scanf("%d",&n)){
		memset(mp,0,sizeof mp);
		set<pair<PII,int> >S;
		S.insert(MP(MP(250,250),0));
		while(n--){
			vector<pair<PII,int> >L(S.OP,S.ED);
			S.clear();
			DRI(len);
			rep(i,0,sz(L)){
				int x=L[i].AA.AA,y=L[i].AA.BB,d=L[i].BB;
				rep(j,1,len+1)
					mp[x+MDX[d]*j][y+MDY[d]*j]=1;
				S.insert(MP(MP(x+len*MDX[d],y+len*MDY[d]),(d+7)%8));
				S.insert(MP(MP(x+len*MDX[d],y+len*MDY[d]),(d+1)%8));
			}
		}
		int ans=0;
		rep(i,0,500)rep(j,0,500)ans+=mp[i][j];
		cout<<ans<<"\n";
	}
}

int main(){
	int _T=1;
	//scanf("%d",&_T);
	rep(CA,0,_T){
		//printf("Case #%d: ",CA+1);
		solve();
	}
	return 0;
}