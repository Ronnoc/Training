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
const double PI=acos(-1.);
const LL MOD = 1000000007;
int n,a,b,Z[2];
int p[100005];
int vis[100005];
int o[100005];
map<int,int>MA;
map<int,int>::iterator it;
void dfs_clr(int t,int la,bool flag=true){
	int le=a-t;
	int re=b-t;
	it=MA.find(t);
	vis[(*it).BB]=0;
	if(flag){
		if(MA.find(le)!=MA.ED)dfs_clr(le,t,0);
		if(MA.find(re)!=MA.ED)dfs_clr(re,t,0);
	}else {
		if(le!=la&&MA.find(le)!=MA.ED)dfs_clr(le,t,0);
		if(re!=la&&MA.find(re)!=MA.ED)dfs_clr(re,t,0);
	}
}
int dfs(int t,int w){
	int p=Z[w]-t;
	int q=Z[1-w]-t;
	int ret=1;
	vis[MA[t]]=1;
	o[MA[t]]=w;
	it=MA.find(p);
	if(it==MA.ED)return 0;
	if(!vis[(*it).BB])
		ret&=dfs(p,w);
	it=MA.find(q);
	if(it!=MA.ED)
		if(!vis[(*it).BB])
			ret&=dfs(q,w);
	return ret;
}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,T;
	while(~scanf("%d%d%d",&n,&a,&b)){
		Z[0]=a;
		Z[1]=b;
		for(i=0;i<n;i++)scanf("%d",&p[i]);
		MA.clear();
		for(i=0;i<n;i++)MA[p[i]]=i;
		for(i=0;i<n;i++)vis[i]=o[i]=0;
		int fail=0;
		for(i=0;i<n;i++)if(MA.find(a-p[i])==MA.ED&&MA.find(b-p[i])==MA.ED)fail=1;
		if(fail){printf("NO\n");continue;}
//		cout<<"~";
		for(i=0;i<n;i++)if(!vis[i]){
			dfs_clr(p[i],0);
//			cout<<i<<endl;
			int ok=dfs(p[i],0);
			if(!ok){
				dfs_clr(p[i],0);
				ok=dfs(p[i],1);
				if(!ok){fail=1;break;}
			}
		}
//		cout<<"!";
		if(fail){printf("NO\n");continue;}
		else {
			printf("YES\n");
			printf("%d",o[0]);
			for(i=1;i<n;i++)printf(" %d",o[i]);
			printf("\n");
		}
	}
	return 0;
}
