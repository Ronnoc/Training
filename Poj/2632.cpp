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

int st[105][105];
int n,m,A,B;
int id[105];
char s[105][3];
char a[105][3];
int t[105];
int x[105],y[105],d[105];
int dx[]={0,-1,0 ,1};
int dy[]={1,0 ,-1,0};
int main(){
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j;
	int T;
	scanf("%d",&T);
	for(int CA=1;CA<=T;++CA){
		scanf("%d%d%d%d",&A,&B,&n,&m);
		for(i=1;i<=n;i++)scanf("%d%d%s",&x[i],&y[i],s[i]);
		for(i=1;i<=m;i++)scanf("%d%s%d",&id[i],a[i],&t[i]);
		memset(st,0,sizeof st);
		for(i=1;i<=n;i++)st[x[i]][y[i]]=i;
		for(i=1;i<=n;i++)if(s[i][0]=='N')d[i]=0;
		for(i=1;i<=n;i++)if(s[i][0]=='W')d[i]=1;
		for(i=1;i<=n;i++)if(s[i][0]=='S')d[i]=2;
		for(i=1;i<=n;i++)if(s[i][0]=='E')d[i]=3;
		int fail=0;
		for(i=1;i<=m;i++){
			int &I=id[i];
			int &X=x[I],&Y=y[I],&D=d[I];
			if(a[i][0]=='L')D=(D+t[i])%4;
			else if(a[i][0]=='R')D=(D+200-t[i])%4;
			else {
				st[X][Y]=0;
				while(t[i]--){
					X+=dx[D];
					Y+=dy[D];
					if(X==0||Y==0||X==A+1||Y==B+1){
						printf("Robot %d crashes into the wall\n",I);
						fail=1;
					}
					else if(st[X][Y]){
						printf("Robot %d crashes into robot %d\n",I,st[X][Y]);
						fail=1;
					}
					if(fail)break;
				}
				st[X][Y]=I;
			}
			if(fail)break;
		}
		if(!fail)printf("OK\n");
		//printf("Case #%d:",CA);
	}
	return 0;
}
