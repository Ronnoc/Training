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
int u[5555];
int d[5555];
int ans[5555];
int inv[5555];
int ybig,ysml;
bool leftof(int id,int x,int y){
	int x1=d[id],y1=ysml;
	int x2=u[id],y2=ybig;
	int dx1=x2-x1,dy1=y2-y1;
	int dx=x-x1,dy=y-y1;
	int tp=dx*dy1-dy*dx1;
//	if(tp>0)cout<<x<<" "<<y<<" left of "<<id<<endl;
//	else cout<<x<<" "<<y<<" right of "<<id<<endl;
	return tp>0;
}
void solve(){
	int i,j;
	int n,m,x1,y1,x2,y2,x,y;
	int T=0;
	while(scanf("%d",&n)!=EOF&&n){
//		if(T++)printf("\n");
		printf("Box\n");
		memset(ans,0,sizeof ans);
		memset(inv,0,sizeof inv);
		scanf("%d%d%d%d%d",&m,&x1,&y1,&x2,&y2);
		ybig=y1;
		ysml=y2;
		u[0]=x1;
		d[0]=x1;
		u[n+1]=x2;
		d[n+1]=x2;
		for(i=1;i<=n;i++)scanf("%d%d",&u[i],&d[i]);
		sort(u+1,u+n+1);
		sort(d+1,d+n+1);
//		for(i=0;i<=n;i++){
//			printf("%2d_%2d %2d_%2d\n",u[i],y1,u[i+1],y1);
//			printf("%2d_%2d %2d_%2d\n",d[i],y2,d[i+1],y2);
//			cout<<endl;
//		}
		while(m--){
			scanf("%d%d",&x,&y);
			if(x>u[n+1]||x<u[0])continue;
			if(y>ybig||y<ysml)continue;
			int l=0,r=n,now;
			while(r>=l){
				if(r-l<=1){
					if(leftof(r,x,y))now=r;
					else now=l;
					break;
				}
				int mid=(r+l)/2;
				if(leftof(mid,x,y))l=mid;
				else r=mid;
			}
			ans[now]++;
		}
//		for(i=0;i<=n;i++)cout<<ans[i]<<" ";cout<<endl;
		for(i=0;i<=n;i++)inv[ans[i]]++;
		for(i=1;i<=n;i++)if(inv[i])
			printf("%d: %d\n",i,inv[i]);
	}
}
int main(){
//	while(1)
		solve();
	return 0;
}
