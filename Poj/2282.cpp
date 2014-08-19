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
const double PI=acos ( -1. );
const LL MOD = 1000000007;
int num[11];
LL f[11][11];
LL ten[11],now;
LL dfs ( int i, int s, int e,int first=1 ) {
	if ( i==-1 ) return !s&&first;
	if ( !first&&!e && ~f[i][s] ) return f[i][s];
	LL ret = 0;
	int u = e?num[i]:9;
	for ( int d = 0; d <= u; ++d ){
		if(d==s&&(d||!first)){
			LL all=ten[i];
			if(e&&d==u)all=now%all+1;
			ret+=all;
//			cout<<now<<" "<<i<<" "<<d<<" "<<s<<" "<<e<<" "<<first<<" + "<<all<<endl;
		}
		ret += dfs ( i-1, s, e&&d==u,first&&!d );
	}
	return (e|first)?ret:f[i][s]=ret;
}
int main() {
	//freopen("","r",stdin);
//	freopen("x.txt","w",stdout);
	int i,j,k,p,q;
	memset(f,-1,sizeof f);
	for(ten[0]=1,i=1;i<=11;i++)ten[i]=ten[i-1]*10;
	while(~scanf("%d%d",&p,&q)){
		if(p>q)swap(p,q);
		if(!p&&!q)break;
		int tot[11];
		memset(tot,0,sizeof tot);
		p--;
		if(p){
			i=-1;
			now=p;
			while(p){
				num[++i]=p%10;
				p/=10;
			}
			p=now;
			for(j=0;j<=9;j++)
				tot[j]-=dfs(i,j,1);
//			for(j=0;j<=9;j++)cout<<tot[j]<<" ";cout<<endl;
		}
		i=-1;
		now=q;
		while(q){
			num[++i]=q%10;
			q/=10;
		}
		q=now;
		for(j=0;j<=9;j++)
			tot[j]+=dfs(i,j,1);
		cout<<tot[0];
		for(j=1;j<=9;j++)cout<<" "<<tot[j];
		cout<<endl;
	}
	return 0;
}
