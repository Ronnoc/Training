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
int a[2005][2005];
int l[2005][10];
int r[2005][10];
int n,m,k,s;
int g[10][10];
int c[111111];
void solve(){
	while(scanf("%d%d%d%d",&n,&m,&k,&s)!=EOF){
		int i,j,p,q;
		for(i=1;i<=n;i++)for(j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
		for(i=1;i<=n;i++){
			for(j=1;j<=9;j++)l[i][j]=m+1;
			for(j=1;j<=9;j++)r[i][j]=0;
			for(j=1;j<=m;j++)
				l[i][a[i][j]]=min(l[i][a[i][j]],j);
			for(j=1;j<=m;j++)
				r[i][a[i][j]]=max(r[i][a[i][j]],j);
		}
		memset(g,0,sizeof g);
		for(i=1;i<=n;i++)for(j=1;j<=n;j++)
			for(p=1;p<=9;p++)for(q=1;q<=9;q++){
				int tp=r[i][p]-l[j][q];
				if(l[j][q]==m+1)continue;
				if(r[i][p]==0)continue;
				g[p][q]=max(g[p][q],(j>i?j-i:i-j)+(tp>0?tp:-tp));
//				if((j>i?j-i:i-j)+(tp>0?tp:-tp)==8)cout<<i<<" "<<j<<" "<<p<<" "<<q<<" "<<tp<<endl;
				}
		int res=0;
		for(i=1;i<=s;i++)scanf("%d",&c[i]);
		for(i=2;i<=s;i++)res=max(max(res,g[c[i]][c[i-1]]),g[c[i-1]][c[i]]);
		printf("%d\n",res);
	}
}
int main(){
//	while(1)
		solve();
	return 0;
}
