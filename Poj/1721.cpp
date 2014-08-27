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

LL two[1005];
int a[1005],b[1005];
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,u,v,w,p,q,r,n,m;
	while(~scanf("%d%d",&n,&m)){
		for(i=1;i<=n;i++)scanf("%d",&a[i]);
		two[0]=1;
		for(p=1;p<=1000;p++){
			two[p]=two[p-1]*2%n;
			if(two[p]==1)break;
		}
//		cout<<"~"<<p<<endl;
		m%=p;
		m=(p-m)%p;
		while(m--){
			for(i=1;i<=n;i++)b[i]=a[a[i]];
			for(i=1;i<=n;i++)a[i]=b[i];
		}
		for(i=1;i<=n;i++)printf("%d\n",a[i]);
	}
	return 0;
}
