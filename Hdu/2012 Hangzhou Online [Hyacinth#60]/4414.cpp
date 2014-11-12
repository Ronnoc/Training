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

int n;
char s[55][55];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
bool valid(int x,int y){
	if(x<0||x>=n)return 0;
	if(y<0||y>=n)return 0;
	return 1;
}
bool near(int x,int y,int t){
	int p,q;
	if(t<2){
		p=x+dx[2];
		q=y+dy[2];
		if(valid(p,q)&&s[p][q]=='#')return 1;
		p=x+dx[3];
		q=y+dy[3];
		if(valid(p,q)&&s[p][q]=='#')return 1;
	}else {
		p=x+dx[0];
		q=y+dy[0];
		if(valid(p,q)&&s[p][q]=='#')return 1;
		p=x+dx[1];
		q=y+dy[1];
		if(valid(p,q)&&s[p][q]=='#')return 1;
	}
	return 0;
}
int main() {
	#define NAME ""
	//freopen(NAME".in","r",stdin);
	//freopen(NAME".out","w",stdout);
	int i,j,k,d,_T;
	while(~scanf("%d",&n)&&n){
		for(i=0;i<n;i++)scanf("%s",s[i]);
		int ans=0,x,y;
		for(i=0;i<n;i++)for(j=0;j<n;j++)if(s[i][j]=='#'){
			int T[4];
			int fail=0;
			for(d=0;d<4;d++){
				T[d]=0;
				while(1){
					int x=i+T[d]*dx[d];
					int y=j+T[d]*dy[d];
//					cerr<<x<<","<<y<<"~\n";
					if(!valid(x,y)||s[x][y]=='o')break;
					if(T[d]&&near(x,y,d))fail=1;
					T[d]++;
				}
				T[d]--;
			}
//			cerr<<fail<<"?";
//			for(k=0;k<4;k++)cerr<<T[k]<<" ";
//			cerr<<"@ "<<i<<","<<j<<"\n";
			for(k=0;k<4;k++)if(T[k]!=T[0])fail=1;
			if(fail)continue;
			if(T[0]<1)continue;
			ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
7
ooooooo
o#ooo#o
###o###
o#ooo#o
ooooo#o
oooo###
ooooo#o
7
ooooooo
oo#oooo
oo#$ooo
#####oo
oo#oo#o
oo#o###
ooooo#o
*/
