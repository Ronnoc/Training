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
int main(){
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j;
	int w[9],h[9];
	while(cin>>w[0]>>h[0]){
		for(i=1;i<6;i++)cin>>w[i]>>h[i];
		for(i=0;i<6;i++)if(w[i]<h[i])swap(w[i],h[i]);
		int FLAG=0,same=0;
		map<PII,int>S;
		for(i=0;i<6;i++)if(w[i]==h[i]){
			same=1;
			int got=0;
			for(j=i+1;j<6;j++)if(w[j]==w[i]&&h[j]==w[i])got=j;
			if(!got)continue;
			int has=1;
			for(j=0;j<6;j++)if(w[j]!=w[i]&&h[j]!=w[i])has=0;
			if(!has)continue;
			set<int>T;
			for(j=0;j<6;j++)if(j!=i&&j!=got)T.insert(w[j]+h[j]-w[i]);
			if(T.SZ==1)FLAG=1;
		}
		if(!same){
			set<int>T;
			for(i=0;i<6;i++)S[MP(w[i],h[i])]++;
			for(i=0;i<6;i++)T.insert(w[i]);
			for(i=0;i<6;i++)T.insert(h[i]);
			if(T.SZ==3){
				FLAG=1;
				for(i=0;i<6;i++)if(S[MP(w[i],h[i])]!=2)FLAG=0;
			}
		}
		if(FLAG)printf("POSSIBLE\n");
		else printf("IMPOSSIBLE\n");
	}
	return 0;
}
