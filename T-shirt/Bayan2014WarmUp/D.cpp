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

int ST[250003][19];
int getGcd(int l,int r){
	int u=31-__builtin_clz(r-l+1);
	return __gcd(ST[l][u],ST[r+1-(1<<u)][u]);
}
map<int,LL>MA;
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,_T;
	int n;
	while(~scanf("%d",&n)){
		MA.clear();
		memset(ST,0,sizeof ST);
		for(i=0;i<n;i++)scanf("%d",&ST[i][0]);
		for(j=0;(1<<j)<=n;j++)for(i=0;i<n;i++)
			ST[i][j+1]=__gcd(ST[i][j],ST[i+(1<<j)][j]);
		for(i=0;i<n;i++){
			int ed=i;
			while(ed<n){
				int g=getGcd(i,ed);
				int le=ed,re=n-1,ge=-1;
				while(re>=le){
					if(re-le<=1){
						if(getGcd(i,re)==g){ge=re;break;}
						if(getGcd(i,le)==g)ge=le;
						break;
					}
					int mid=(le+re)>>1;
					if(getGcd(i,mid)==g)le=mid;
					else re=mid;
				}
				MA[g]+=ge-ed+1;
				ed=ge+1;
			}
		}
		int Q;
		scanf("%d",&Q);
		while(Q--){
			int w;
			scanf("%d",&w);
			map<int,LL>::iterator it=MA.find(w);
			if(it==MA.ED)printf("0\n");
			else printf("%I64d\n",(*it).BB);
		}
	}
	return 0;
}

