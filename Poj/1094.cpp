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
const double INF=1e20;
const double PI=acos( -1. );
const int MXN = 50;
const LL MOD = 1000000007;
int rk[33];
int kr[33];
vector<int>G[33];
int main(){
	int i,j;
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		if(n==0&&m==0)break;
		for(i=0;i<n;i++)rk[i]=0;
		for(i=0;i<n;i++)G[i].clear();
		LL DONE=MOD;
		string ans;
		for(int t=1;t<=m;t++){
			char s[5];
			scanf("%s",s);
			int u=s[0]-'A';
			int v=s[2]-'A';
			rk[v]++;
			G[u].PB(v);
			memcpy(kr,rk,sizeof rk);
			int multi=0,wa=0;
			queue<int>Q;
			for(i=0;i<n;i++)if(kr[i]==0)Q.push(i);
			string ss;
			while(!Q.empty()){
				if(Q.SZ>1)multi=1;
				int u=Q.front();
				Q.pop();
				ss+=(u+'A');
				for(i=0;i<G[u].SZ;i++){
					int v=G[u][i];
					kr[v]--;
					if(kr[v]==0)Q.push(v);
				}
			}
			if(DONE<MOD)continue;
			if(ss.SZ!=n)cmin(DONE,-MOD+t);
			if(!multi&&ss.SZ==n)cmin(DONE,1LL*t),ans=ss;
		}
		if(DONE<0)printf("Inconsistency found after %d relations.\n",DONE+MOD);
		else if(DONE==MOD)printf("Sorted sequence cannot be determined.\n");
		else {
			printf("Sorted sequence determined after %d relations: ",DONE);
			ans+='.';
			cout<<ans<<endl;
		}
	}
	return 0;
}
