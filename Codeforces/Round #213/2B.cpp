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
int a[100010],n;
int is[100010];
void solve(){
	while(cin>>n){
		int i;
		for(i=1;i<=n;i++)scanf("%d",&a[i]);
		if(n<=2){cout<<n<<endl;break;}
		memset(is,0,sizeof is);
		for(i=3;i<=n;i++)is[i]= a[i]==(a[i-1]+a[i-2])?1:0;
//		for(i=1;i<=n;i++)cout<<is[i]<<" ";cout<<endl;
		int tot=0;
		int now=0;
		while(now<=n){
			int l=now,r=now;
			while(is[r])r++;
			tot=max(tot,r-l);
			now=r;
			while(now<=n&&!is[now])now++;
		}
		cout<<tot+2<<endl;
	}
}
int main(){
//	while(1)
		solve();
	return 0;
}
