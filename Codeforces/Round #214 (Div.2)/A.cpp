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
#include <fstream>
#include <iomanip>
#include <numeric>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <functional>

using namespace std;

#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define SORT(x) sort(x.OP,x.ED)
#define UNIQUE(x) x.erase(unique(x.OP,x.ED),x.ED)
typedef long long LL;
typedef pair<int, int> PII;
int n;
int a[5];
int b[5];
int c[5];
int d[5];
int l[5],r[5];
void solve(){
	while(cin>>n){
		int i;
		for(i=1;i<=4;i++)
			cin>>a[i]>>b[i]>>c[i]>>d[i];
		for(i=1;i<=4;i++)l[i]=min(a[i],b[i]);
		for(i=1;i<=4;i++)r[i]=min(c[i],d[i]);
		int e=0;
		for(i=1;i<=4;i++)if(l[i]+r[i]<=n)e=i;
		if(!e)printf("-1\n");
		else {
			printf("%d %d %d\n",e,l[e],n-l[e]);
			
		}
	}
}
int main(){
//	while(1)
		solve();
	return 0;
}
