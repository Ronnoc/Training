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

char s[100005];
char t[100005];
int g[33][33];
int cost(int p,int q) {
	return g[p][q];
}
int play(int p,int q,int m) {
	if(p>q)swap(p,q);
	int ret=0;
	if(m<p){ret+=p-m;m=p;}
	if(m>q){ret+=m-q;m=q;}
	ret+=min(q-p+m-p,q-p+q-m);
	return ret;
}
int main() {
#define NAME ""
	//freopen(NAME".in","r",stdin);
	//freopen(NAME".out","w",stdout);
	int i,j,k,_T;
	for(i=0; i<26; i++)for(j=0; j<26; j++)g[i][j]=MOD;
	for(i=0; i<26; i++)g[i][i]=0;
	for(i=0; i<26; i++)g[i][(i+1)%26]=g[(i+1)%26][i]=1;
	for(k=0; k<26; k++)
		for(i=0; i<26; i++)
			for(j=0; j<26; j++)
				cmin(g[i][j],g[i][k]+g[k][j]);
	int n,m;
	while(~scanf("%d%d",&n,&m)) {
		scanf("%s",s+1);
		int len=strlen(s+1);
		for(i=len,j=1; i>=1; j++,i--)
			t[i]=s[j];
		int z=1;
		while(z<=len&&t[z]==s[z])z++;
		if(z>len) {
			cout<<0<<"\n";
			continue;
		}
		int y=(len+1)/2;
		while(y&&t[y]==s[y])y--;
		
		int ans=min(play(z,y,m),play(len+1-y,len+1-z,m));
		cmin(ans,min(play(z,y,len),play(len+1-y,len+1-z,len))+m);
		cmin(ans,min(play(z,y,1),play(len+1-y,len+1-z,1))+len-m+1);
//		cerr<<ans<<"\n";
		for(i=1; i+i<=len; i++)
			ans+=cost(s[i]-'a',t[i]-'a');
		cout<<ans<<"\n";
	}
	return 0;
}
/*
23 23
aaacaaaaaaaaaaaaaaabaaa
*/
