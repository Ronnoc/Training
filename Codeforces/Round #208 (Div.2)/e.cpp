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
int mx[1111][1111],n,m;
int vis[1111][1111];
bool check(int p,int q){
	memset(vis,0,sizeof vis);
	queue<PII>Q;
	Q.push(MP(p,q));
	int i,j;
	while(!Q.empty()){
		PII u=Q.front();Q.pop();
		int i=u.AA,j=u.BB;
		if(vis[i][j])continue;
		vis[i][j]=1;
		if(j+1<=m&&mx[i][j+1])Q.push(MP(i,j+1));
		if(j-1>=1&&mx[i][j-1])Q.push(MP(i,j-1));
		if(i-1>=1&&mx[i-1][j])Q.push(MP(i-1,j));
		if(i+1<=n&&mx[i+1][j])Q.push(MP(i+1,j));
	}
	for(i=1;i<=n;i++)for(j=1;j<=m;j++)if(mx[i][j]&&!vis[i][j])return 0;
	return 1;
}
void solve(){
	cin>>n>>m;
	int i,j,p,q;
	for(i=1;i<=n;i++)for(j=1;j<=m;j++)cin>>mx[i][j];
	int found=0;
	for(i=1;!found&&i<=n;i++)for(j=1;!found&&j<=m;j++)if(mx[i][j]){found=1;p=i;q=j;}
	if(!check(p,q)){cout<<"-1\n";return;}
	int tot=0;
	for(i=1;i<=n;i++)for(j=1;j<=m;j++){
		if(!mx[i][j])continue;
		int now=0;
		if(j+1<=m&&mx[i][j+1])now++;
		if(j-1>=1&&mx[i][j-1])now++;
		if(i-1>=1&&mx[i-1][j])now++;
		if(i+1<=n&&mx[i+1][j])now++;
		if(now&1)tot++;
	}
	if(tot>=3){cout<<"-1\n";return;}
	vector<int>N,M;
	for(i=1;i<=n;i++)for(j=1;j<=m;j++){
		if(!mx[i][j])continue;
		if(j+1<=m&&mx[i][j+1])N.PB(i);
		if(j-1>=1&&mx[i][j-1])N.PB(i);
		if(i-1>=1&&mx[i-1][j])M.PB(j);
		if(i+1<=n&&mx[i+1][j])M.PB(j);
	}
	sort(N.OP,N.ED),sort(M.OP,M.ED);
	N.erase(unique(N.OP,N.ED),N.ED);
	M.erase(unique(M.OP,M.ED),M.ED);
	int dis=0;
	for(i=1;i<N.size();i++)dis=__gcd(N[i]-N[i-1],dis);
	for(i=1;i<M.size();i++)dis=__gcd(M[i]-M[i-1],dis);
	if(dis==0){
		if(M.empty()&&N.empty()){cout<<"-1\n";return;}
		if(!M.empty()){
			p=n+1,q=0;
			for(i=1;i<=n;i++)if(mx[i][M.back()])p=min(p,i),q=max(q,i);
			dis=__gcd(q-p,dis);
		}
		if(!N.empty()){
			p=m+1,q=0;
			for(i=1;i<=m;i++)if(mx[N.back()][i])p=min(p,i),q=max(q,i);
			dis=__gcd(q-p,dis);
		}
	}
	if(dis==1){cout<<"-1\n";return;}
	for(i=2;i<=dis;i++)if(dis%i==0)cout<<i<<" ";
}
int main(){
//	while(1)
		solve();
	return 0;
}
/*
3 3
0 0 0
0 1 0
0 0 0
5 5
1 1 1 1 1
0 0 0 0 1
0 0 0 0 1
0 0 0 0 0
0 0 0 0 0
6 6
1 1 1 0 0 0
1 0 1 0 0 0
1 1 1 0 0 0
0 0 0 1 1 1
0 0 0 1 0 1
0 0 0 1 1 1

5 5
0 0 1 1 1
0 0 1 0 1
1 1 1 1 1
0 0 1 0 0
0 0 1 0 0
*/
