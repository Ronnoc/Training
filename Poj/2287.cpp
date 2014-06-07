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
int main(){
	int i,j;
	multiset<int>A;
	multiset<int>::iterator it;
	int vis[1111];
	int a[1111];
	int b[1111];
	int n;
	while(~scanf("%d",&n)&&n){
		for(i=0;i<n;i++)scanf("%d",&a[i]);
		for(i=0;i<n;i++)scanf("%d",&b[i]);
		A.clear();
		for(i=0;i<n;i++)A.insert(a[i]);
		sort(b,b+n);
		reverse(b,b+n);
		for(i=0;i<n;i++)vis[i]=0;
		int ans=0;
		int ret=n;
		for(i=0;i<n;i++)if(!vis[i]){
			it=A.upper_bound(b[i]);
			if(it!=A.ED){
				vis[i]=1;
				A.erase(it);
				ans++;
			}
		}
		for(i=0;i<n;i++)if(!vis[i]){
			it=A.lower_bound(b[i]);
			if(it!=A.ED){
				vis[i]=1;
				A.erase(it);
			}
		}
		ans-=A.SZ;
		printf("%d\n",ans*200);
	}
	return 0;
}
