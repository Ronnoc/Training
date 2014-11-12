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

int a[100005];
int b[100005];
int fa[100005];
int fb[100005];
int main() {
	#define NAME ""
	//freopen(NAME".in","r",stdin);
	//freopen(NAME".out","w",stdout);
	int i,j,k,_T;
	int n;
	while(~scanf("%d",&n)){
		for(i=1;i<=n;i++)scanf("%d",&a[i]);
		for(i=1;i<=n;i++)b[i]=-a[i];
		vector<int>L;
		for(i=1;i<=n;i++){
			int id=lower_bound(L.OP,L.ED,a[i])-L.OP;
			if(id==L.SZ)L.PB(a[i]);
			else L[id]=a[i];
			fa[i]=id+1;
		}
		L.clear();
		for(i=n;i>=1;i--){
			int id=lower_bound(L.OP,L.ED,b[i])-L.OP;
			if(id==L.SZ)L.PB(b[i]);
			else L[id]=b[i];
			fb[i]=id+1;
		}
		int ans=L.SZ;
		map<int,int>S;
		for(i=1;i<=n;i++){
			if(fa[i]+fb[i]-1!=ans){
				continue;
			}
			S[fa[i]]++;
		}
		for(i=1;i<=n;i++){
			if(fa[i]+fb[i]-1!=ans){
				putchar('1');
				continue;
			}
			if(S[fa[i]]==1)putchar('3');
			else putchar('2');
		}
		putchar('\n');
	}
	return 0;
}
