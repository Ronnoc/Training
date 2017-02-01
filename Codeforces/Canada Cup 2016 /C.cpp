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
char s[33];
VI G[33];
int id[33][3];
bool conn(PII x,PII y){
	if(x==y)return 0;
	if(fabs(x.AA-y.AA)>1)return 0;
	if(fabs(x.BB-y.BB)!=1)return 0;
	return 1;
}
char ans[33][3];
void solve(){
	VPII L;
	rep(i,0,13)L.PB(MP(i,0));
	repd(i,12,0)L.PB(MP(i,1));
	memset(id,-1,sizeof id);
	rep(i,0,sz(L))id[L[i].AA][L[i].BB]=i;
	while(~scanf("%s",s)){
		rep(i,0,26)G[i].clear();
		rep(i,0,27)G[s[i]-'A'].PB(i);
		rep(i,0,26)if(sz(G[i])==2){
			int a=G[i][0],b=G[i][1];
			//printf("%c %d %d\n",i+'A',a,b);
			if(b==a+1){
				cout<<"Impossible\n";
			}else {
				rep(i,0,sz(L)){
					PII x=L[i],y=L[(i+(b-a-1))%sz(L)];
					if(conn(x,y)){
						int p=i,q=a;
						while(q!=b){
							ans[L[p].AA][L[p].BB]=s[q];
							p=(p+1)%sz(L);
							q++;
						}
						q=(q+1)%27;
						while(q!=a){
							ans[L[p].AA][L[p].BB]=s[q];
							p=(p+1)%sz(L);
							q=(q+1)%27;
						}
						break;
					}
				}
				rep(i,0,13)putchar(ans[i][0]);puts("");
				rep(i,0,13)putchar(ans[i][1]);puts("");
			}
			break;
		}
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