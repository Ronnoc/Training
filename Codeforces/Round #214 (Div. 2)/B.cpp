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
int n,k;
int a[111111];
int g[111111];
void solve(){
	while(cin>>n>>k){
		int i,j;
		for(i=0;i<n;i++)cin>>a[i];
		for(i=0;i<k;i++){
			g[i]=0;
			for(j=i;j<n;j+=k)g[i]+=a[j];
		}
		int mx=1e9,id=-1;
		for(i=0;i<k;i++)
			if(g[i]<mx)mx=g[i],id=i;
		printf("%d\n",id+1);
	}
}
int main(){
//	while(1)
		solve();
	return 0;
}
