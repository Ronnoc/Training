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

const double eps = 1e-8;
const int MOD = 1000000007;
#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define SORT(X) sort(X.OP,X.ED)
#define SQ(x) ((x)*(x))
typedef long long LL;
typedef pair<int, int> PII;
bool isprime(int x){
	for(int i=2;i*i<=x;i++)if(x%i);else return 0;
	return 1;
}
bool isp[11111];
vector<int>G[1111];
void solve(){
	int i,j;
	vector<int>p;
	for(i=1001;i<=9999;i+=2)if(isp[i]=isprime(i))p.PB(i);
	for(i=0;i<p.SZ;i++){
		int p0=p[i]/10,q0=p[i]%10;
		int p1=p0/10,q1=p0%10;
		int p2=p1/10,q2=p1%10;
		int p3=p2/10,q3=p2%10;
		for(j=0;j<=9;j++){
			if(isp[p[i]+(j-q0)*1]&&q0!=j)G[i].PB(lower_bound(p.OP,p.ED,p[i]+(j-q0)*1)-p.OP);
			if(isp[p[i]+(j-q1)*10]&&q1!=j)G[i].PB(lower_bound(p.OP,p.ED,p[i]+(j-q1)*10)-p.OP);
			if(isp[p[i]+(j-q2)*100]&&q2!=j)G[i].PB(lower_bound(p.OP,p.ED,p[i]+(j-q2)*100)-p.OP);
			if(isp[p[i]+(j-q3)*1000]&&q3!=j)G[i].PB(lower_bound(p.OP,p.ED,p[i]+(j-q3)*1000)-p.OP);
		}
	}
//	for(i=0;i<G[5].SZ;i++)cout<<p[G[5][i]]<<" "<<endl;
	int T;
	scanf("%d",&T);
	while(T--){
		int u,v;
		scanf("%d%d",&u,&v);
		u=lower_bound(p.OP,p.ED,u)-p.OP;
		v=lower_bound(p.OP,p.ED,v)-p.OP;
		int d[1111];
		for(i=0;i<p.SZ;i++)d[i]=MOD;
		d[u]=0;
		queue<int>q;
		q.push(u);
		while(!q.empty()){
			if(d[v]!=MOD)break;
			int x=q.front();
			q.pop();
			for(i=0;i<G[x].SZ;i++){
				int y=G[x][i];
				if(d[y]>d[x]+1)d[y]=d[x]+1,q.push(y);
			}
		}
		if(d[v]==MOD)printf("Impossible\n");
		else printf("%d\n",d[v]);
	}
}
int main(){
//	while(1)
		solve();
	return 0;
}
