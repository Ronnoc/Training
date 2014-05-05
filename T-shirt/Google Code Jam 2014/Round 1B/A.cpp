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
const double INF=1e20;
const double PI=acos( -1. );
const int MXN = 50;
const LL MOD = 1000000007;
vector<int>G[111];
string play(char *s,int id){
	string ret;
	for(int i=0;s[i];i++)if(s[i]!=s[i+1])ret+=s[i];
	int now=0,i;
	for(i=0;i<ret.SZ;i++){
		int l=now;
		while(s[now]==ret[i])now++;
		int r=now;
		G[id].PB(r-l);
	}
	return ret;
}
int main(){
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	int i,j,k;
	int T;
	scanf("%d",&T);
	for(int CASE=1;CASE<=T;++CASE){
		int n;
		scanf("%d",&n);
		char s[111][111];
		for(i=1;i<=n;i++)scanf("%s",s[i]);
		for(i=1;i<=n;i++)G[i].clear();
//		cout<<s[1]<<" "<<s[2]<<endl;
		printf("Case #%d: ",CASE);
		vector<string>L;
		for(i=1;i<=n;i++)L.PB(play(s[i],i));
		SORT(L);
		if(L[0]!=L[L.SZ-1]){
			printf("Fegla Won\n");
			continue;
		}
//		for(i=1;i<=n;i++){
//			for(j=0;j<G[i].SZ;j++)cout<<G[i][j]<<" ";
//			cout<<endl;
//		}
		int ans=0;
		for(int i=0;i<G[1].SZ;i++){
			vector<int>S;
			S.clear();
			for(j=1;j<=n;j++)S.PB(G[j][i]);
			SORT(S);
			int add=MOD;
			for(j=1;j<=100;j++){
				int now=0;
				for(k=0;k<S.SZ;k++)now+=fabs(S[k]-j);
//				cout<<j<<"~"<<now<<endl;
				cmin(add,now);
			}
//			cout<<add<<" ";
			ans+=add;
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
1
2
fffbbbbbbbbbbbbbggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg fffffbbgggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg
*/
