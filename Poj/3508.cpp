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

char s[1000005];
int t[1000005];
int nt=0;
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,n,m,u,v,T=0;
	while(~scanf("%s",s)){
		int len=strlen(s);
		if(len==1&&s[0]=='0')break;
		reverse(s,s+len);
		t[0]=s[0]-'0';
		int up=0,flag=1;
		for(i=1;i<len;i++){
			int S=s[i]-'0';
			t[i]=S-up-t[i-1];
			if(t[i]<0)t[i]+=10,up=1;else up=0;
		}
		reverse(t,t+len);
		printf("%d. ",++T);
		if(!t[0])printf("IMPOSSIBLE");
		else for(i=0;i<len;i++)putchar('0'+t[i]);
		printf("\n");
	}
	return 0;
}
