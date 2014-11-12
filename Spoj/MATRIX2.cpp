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
const double PI=acos(-1.);
const LL MOD = 1000000007;

int P[1005][1005];
int Q[1005][1005];
int V[1005][1005];
int n,m,a,b,c,d;
int F[1005][1005];
void increasePush(deque<PII>&Q,int a,int b){
	while(!Q.empty()&&Q.back().AA>=a)
		Q.pop_back();
	Q.push_back(MP(a,b));
}
int main() {
#define NAME ""
	//freopen(NAME".in","r",stdin);
	//freopen(NAME".out","w",stdout);
	int i,j,k,_T,p,q;
	scanf("%d",&_T);
	while(_T--) {
		scanf("%d%d%d%d%d%d",&n,&m,&a,&b,&c,&d);
		for(i=1; i<=n; i++) {
			scanf("%d",&P[i][1]);
			for(j=2; j<=m; j++)
				P[i][j]=(P[i][j-1]*71+17)%100+1;
			for(j=1; j<=m; j++)Q[i][j]=Q[i][j-1]+P[i][j];
		}
		for(i=1; i<=n; i++)for(j=1; j<=m; j++)
				Q[i][j]+=Q[i-1][j];
		for(p=1;p+c<n;p++)for(q=1;q+d<m;q++)
			V[p][q]=Q[p+c][q+d]+Q[p][q]-Q[p][q+d]-Q[p+c][q];
		for(i=1;i+c<n;i++){
			deque<PII>Q;
			int len=b-d-1;
			for(j=1;j<=len;j++)
				increasePush(Q,V[i][j],j);
			for(j=1;j+len<m;j++){
				while(Q.front().BB<j)
					Q.pop_front();
				F[i][j]=Q.front().AA;
				increasePush(Q,V[i][j+len],j+len);
			}
		}
		for(j=1;j+d<m;j++){
			deque<PII>Q;
			int len=a-c-1;
			for(i=1;i<=len;i++)
				increasePush(Q,F[i][j],i);
			for(i=1;i+len<n;i++){
				while(Q.front().BB<i)
					Q.pop_front();
				V[i][j]=Q.front().AA;
				increasePush(Q,F[i+len][j],i+len);
			}
		}
		int ans=0;
		for(i=0; i+a<=n; i++)
			for(j=0; j+b<=m; j++) {
				int sum=Q[i+a][j+b]+Q[i][j]-Q[i][j+b]-Q[i+a][j];
				cmax(ans,sum-V[i+1][j+1]);
			}
		printf("%d\n",ans);
	}
	return 0;
}
/*
1
4 4 3 4 1 1
1 2 3 4
*/
