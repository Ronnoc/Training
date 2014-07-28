#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define SORT(x) sort(x.OP,x.ED)
#define SQ(x) ((x)*(x))
#define SSP system("pause")
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
typedef long long LL;
typedef pair<int, int> PII;
const double eps=1e-8;
const double PI=acos( -1. );
const LL MOD = 1000000007;
int main(){
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k;
	int T;
	scanf("%d",&T);
	for(int CA=1;CA<=T;++CA){
		int n;
		vector<pair<int,int> >L;
		scanf("%d",&n);
		for(i=0;i<n;i++){
			int c,u,v,U,V;
			scanf("%d %2d:%2d %2d:%2d",&c,&u,&v,&U,&V);
			v+=u*60;
			V+=U*60;
			L.PB(MP(v,c));
			L.PB(MP(V,-c));
		}
		sort(L.OP,L.ED);
		int now=0,ans=0;
		for(i=0;i<L.SZ;i++){
			now+=L[i].BB;
			cmax(ans,now);
		}
		cout<<ans<<endl;
		//printf("Case #%d:",CA);
	}
	return 0;
}
