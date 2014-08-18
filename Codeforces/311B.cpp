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

LL dp[2][100005];
LL AT[100005];
int DT[100005];
int q[100005],op,ed;
int slope(LL x,LL y,LL p,LL q){
	if(1.0*y*p<1.0*x*q)return -1;
	return 1.0*y*p>1.0*x*q;
}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k;
	int n,m,p;
	while(~scanf("%d%d%d",&n,&m,&p)){
		int x=0,y=1;
		for(i=2;i<=n;i++)scanf("%d",&DT[i]);
		for(DT[1]=0,i=2;i<=n;i++)DT[i]+=DT[i-1];
		for(i=1;i<=m;i++){
			int h,t;
			scanf("%d%d",&h,&t);
			AT[i]=t-DT[h];
		}
		sort(AT+1,AT+m+1);
		memset(dp,0,sizeof dp);
		for(i=1;i<=m;i++)dp[x][i]=AT[i]*i;
		for(j=1;j<p;j++){
			op=ed=0;
			q[ed++]=0;
			LL *D=dp[x];
			for(i=1;i<=m;i++){
				while(ed-op>=2){
					int l=q[ed-2],r=q[ed-1];
					if(slope(r-l,D[r]-D[l],i-r,D[i]-D[r])>=0)ed--;
					else break;
				}
				while(ed-op>=2){
					int l=q[op],r=q[op+1];
					if(slope(r-l,D[r]-D[l],1,AT[i])<0)op++;
					else break;
				}
				dp[y][i]=D[q[op]]+(i-q[op])*AT[i];
				q[ed++]=i;
			}
			swap(x,y);
			for(i=1;i<=m;i++)cmin(dp[x][i],dp[y][i]);
		}
		LL Ans=dp[x][m];
		for(i=1;i<=m;i++)Ans-=AT[i];
		cout<<Ans<<endl;
	}
	return 0;
}
