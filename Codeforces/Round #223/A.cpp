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

typedef long long LL;
typedef pair<int, int> PII;
int n;
int q[111111];
int a[111111];
int b[111111];
LL len[111111];
int dp[111111];
int query(LL x){
	int id=lower_bound(len+1,len+n+1,x)-len;
	if(q[id]==1)return a[id];
	LL tp=len[id-1];
	LL w=x-tp;
	LL z=w/a[id];
	if(z>1)w-=(z-1)*a[id];
	while(w>a[id])w-=a[id];
	if(dp[w]!=-1)return dp[w];
	return dp[w]=query(w);
}
void solve(){
	while(cin>>n){
		memset(dp,-1,sizeof dp);
		int i,j;
		len[0]=0;
		for(i=1;i<=n;i++){
			cin>>q[i];
			if(q[i]==1){cin>>a[i];len[i]=len[i-1]+1;}
			else {cin>>a[i]>>b[i];len[i]=len[i-1]+1LL*a[i]*b[i];}
		}
		int m;
		cin>>m;
		LL x;
		while(m--){
			cin>>x;
			cout<<query(x)<<" ";
		}cout<<endl;
	}
}
int main(){
//	while(1)
		solve();
	return 0;
}
