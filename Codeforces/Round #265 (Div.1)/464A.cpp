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
char s[1005];
int a[1005];
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,T;
	int n,p;
	while(~scanf("%d%d",&n,&p)) {
		scanf("%s",s);
		if(p==1) {
			puts("NO");
			continue;
		}
		int len=strlen(s);
		for(i=0; i<len; i++)a[i]=s[i]-'a';
		a[len]=0;
		reverse(a,a+len);
		while(!a[len]) {
			a[0]++;
			for(i=0; i<len; i++)
				if(a[i]>=p)a[i]-=p,a[i+1]++;
				else break;
			for(i=len-1; i>=1; i--)if(a[i]==a[i-1]) {
					a[i-1]++;
					int t=0;
					for(j=i-2; j>=0; j--)a[j]=(t++)%3;
					break;
				}
			for(i=len-2; i>=1; i--)if(a[i+1]==a[i-1]) {
					a[i-1]++;
					int t=0;
					for(j=i-2; j>=0; j--)a[j]=(t++)%3;
					break;
				}
			int fail=0;
			for(j=0; j<len; j++)if(a[j]>=p)a[j]-=p,a[j+1]++;
			for(i=1; i<len; i++)if(a[i]==a[i-1])fail=1;
			for(i=1; i+1<len; i++)if(a[i-1]==a[i+1])fail=1;
			if(!fail)break;
		}
		reverse(a,a+len);
		int got=1;
		if(a[len])got=0;
		if(got) {
			for(i=0; i<len; i++)putchar('a'+a[i]);
			printf("\n");
		}
		else puts("NO");
	}
	return 0;
}
/*
900 26
pyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyxzyx
*/
