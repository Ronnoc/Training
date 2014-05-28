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
double h[1010];
int ldp[1010],rdp[1010];
int n;
int main(){
	int i,j;
	while(~scanf("%d",&n)){
		for(i=1;i<=n;i++)scanf("%lf",&h[i]);
		for(i=1;i<=n;i++)h[i]*=100000;
		vector<double>L;
		for(i=1;i<=n;i++){
			int id=lower_bound(L.OP,L.ED,h[i])-L.OP;
			if(id==L.SZ){
				L.PB(h[i]);
				ldp[i]=L.SZ;
			}else {
				ldp[i]=id+1;
				L[id]=h[i];
			}
		}
		L.clear();
		for(i=n;i>=1;i--){
			int id=lower_bound(L.OP,L.ED,h[i])-L.OP;
			if(id==L.SZ){
				L.PB(h[i]);
				rdp[i]=L.SZ;
			}else {
				rdp[i]=id+1;
				L[id]=h[i];
			}
		}
		for(i=2;i<=n;i++)cmax(ldp[i],ldp[i-1]);
		for(i=n-1;i>=1;i--)cmax(rdp[i],rdp[i+1]);
		int ans=max(rdp[1],ldp[n]);
		for(i=1;i<n;i++)cmax(ans,ldp[i]+rdp[i+1]);
		printf("%d\n",n-ans);
	}
	return 0;
}
