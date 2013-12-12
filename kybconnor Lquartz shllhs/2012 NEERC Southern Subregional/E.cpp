//kybconnor
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

typedef long long LL;
typedef pair<int, int> PII;
char s[222];
void solve() {
	int n,c0,c1,c2;
	while (~scanf ("%d%d%d",&n,&c0,&c1)) {
		scanf ("%s",s);
		if (c0+c1>n) {
			printf ("-1\n");
			continue;
		}
		int i,j,k;
		c2=n-c1-c0;
		int t[5];
		int p[5];
		for(i=0;i<3;i++)t[i]=0;
		p[0]=c0;
		p[1]=c1;
		p[2]=c2;
		int len=strlen(s);
		if(len!=n){
			printf ("-1\n");
			continue;
		}
		for(i=0;i<len;i++){
			if(s[i]=='0')t[0]++;
			else if(s[i]=='1')t[1]++;
			else t[2]++;
		}
		int g[5][5];
		for(i=0;i<3;i++)for(j=0;j<3;j++)g[i][j]=0;
		for(i=0;i<3;i++)for(j=0;j<3;j++){
			while(t[i]>p[i]&&t[j]<p[j])t[j]++,t[i]--,g[i][j]++;
		}
		int ans=0;
		for(i=0;i<3;i++)for(j=0;j<3;j++)if(g[i][j]){
			int tot=g[i][j];
			ans+=tot;
			for(k=0;tot&&k<len;k++)if(s[k]=='0'+i)s[k]='0'+j,tot--;
		}
		printf("%d\n",ans);
		printf("%s\n",s);
	}
}
int main() {
//	while(1)
	solve();
	return 0;
}
