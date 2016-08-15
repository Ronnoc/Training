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

const int MXN = 100005;
int s[3][MXN];
int t[3][MXN];
int is[3];
void solve(){
	int n,CA=0;
	while(~RI(n)&&n){
		printf("Case #%d:\n",++CA);
		rep(i,0,3)is[i]=0;
		rep(z,0,n){
			char ss[7];
			scanf("%s",ss);
			if(ss[1]=='u'){
				int w;
				char p[3];
				scanf("%s%d",p,&w);
				int id=p[0]-'A';
				s[id][is[id]]=w;
				t[id][is[id]]=z;
				is[id]++;
			}
			if(ss[1]=='o'){
				char p[3];
				scanf("%s",p);
				int id=p[0]-'A';
				if(is[id]==0)id=2;
				is[id]--;
				printf("%d\n",s[id][is[id]]);
			}
			if(ss[1]=='e'){
				char p[3],q[3];
				scanf("%s%s",p,q);
				int id[2];
				id[0]=id[1]=0;
				while(id[0]<is[0]&&id[1]<is[1]){
					if(t[0][id[0]]<t[1][id[1]])s[2][is[2]++]=s[0][id[0]++];
					else s[2][is[2]++]=s[1][id[1]++];
				}
				while(id[0]<is[0])s[2][is[2]++]=s[0][id[0]++];
				while(id[1]<is[1])s[2][is[2]++]=s[1][id[1]++];
				is[0]=is[1]=0;
			}
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