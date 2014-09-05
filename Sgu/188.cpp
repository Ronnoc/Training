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

int L[22],V[22];
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,n,m,u,v,T;
	while(~scanf("%d%d",&n,&T)){
		for(i=0;i<n;i++)scanf("%d",&L[i]);
		for(i=0;i<n;i++)scanf("%d",&V[i]);
		int ans[22];
		memset(ans,0,sizeof ans);
		for(int t=0;t<T;t++){
			for(i=0;i<n;i++)for(j=0;j<n;j++){
				if(V[i]*V[j]>0)continue;
				int dl=(L[j]-L[i]+1000)%1000;
				int dv=V[i]-V[j];
				int flag=0;
				if(dv<0){
					if(dl&&dl>=dv+1000)flag=1;
				}else {
					if(dl&&dl<=dv)flag=1;
				}
				if(flag)ans[i]++;
			}
			for(i=0;i<n;i++)L[i]=(L[i]+V[i]+1000)%1000;
		}
		printf("%d",ans[0]);
		for(i=1;i<n;i++)printf(" %d",ans[i]);
		printf("\n");
	}
	return 0;
}
