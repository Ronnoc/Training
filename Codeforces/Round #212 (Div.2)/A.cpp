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
#define UNIQUE(x) x.erase(unique(x.OP,X.ED),x.ED)
typedef long long LL;
typedef pair<int, int> PII;
char mp[9][9];
set<int>p[9][9];
set<int>q[9][9];
set<int>::iterator iter;
bool in(int x,int y){
	if(x<0||y<0)return 0;
	if(x>7||y>7)return 0;
	return 1;
}
void solve(){
	int n;
	while(~scanf("%d",&n)){
		while(n--){
			int i,j,k,l;
			for(i=0;i<8;i++)scanf("%s",mp[i]);
			for(i=0;i<8;i++)for(j=0;j<8;j++)p[i][j].clear();
			for(i=0;i<8;i++)for(j=0;j<8;j++)q[i][j].clear();
			vector<PII>L;
			L.clear();
			for(i=0;i<8;i++)for(j=0;j<8;j++)if(mp[i][j]=='K')L.PB(MP(i,j));
			for(i=0;i<=10;i++)for(j=0;j<=10;j++)for(k=0;k<=10;k++)for(l=0;l<=10;l++){
				int x=L[0].AA+i*2+j*2-k*2-l*2;
				int y=L[0].BB+i*2-j*2+k*2-l*2;
				if(in(x,y)&&mp[x][y]!='#')p[x][y].insert(i+j+k+l);
			}
			for(i=0;i<=10;i++)for(j=0;j<=10;j++)for(k=0;k<=10;k++)for(l=0;l<=10;l++){
				int x=L[1].AA+i*2+j*2-k*2-l*2;
				int y=L[1].BB+i*2-j*2+k*2-l*2;
				if(in(x,y)&&mp[x][y]!='#')q[x][y].insert(i+j+k+l);
			}
			int flag=0;
			for(i=0;i<8;i++)for(j=0;j<8;j++){
				for(iter=p[i][j].OP;iter!=p[i][j].ED;++iter)
					if(!q[i][j].empty()&&q[i][j].find(*iter)!=q[i][j].ED)flag=1;
//				cout<<"!"<<endl;
			}
			if(flag)printf("YES\n");else printf("NO\n");
		}
	}
}
int main(){
//	while(1)
		solve();
	return 0;
}
