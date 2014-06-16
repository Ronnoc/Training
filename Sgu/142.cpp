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
char s[500005];
vector<int>L;
int main(){
	int i,j;
	int len;
	scanf("%d",&len);
	scanf("%s",s);
	int ans=0;
	while(1){
		++ans;
		L.clear();
		for(i=0;i+ans<=len;i++){
			int now=0;
			for(j=0;j<ans;j++)now=now*2+s[i+j]-'a';
			L.PB(now);
		}
		SORT(L);
		L.erase(unique(L.OP,L.ED),L.ED);
		L.PB(-1);
		for(i=0;i<1<<ans;i++)if(L[i]!=i)break;
		if(i>>ans&1)continue;
		else {
			printf("%d\n",ans);
			for(j=ans-1;j>=0;j--)if(i>>j&1)printf("b");else printf("a");
			printf("\n");
			break;
		}
	}
	return 0;
}
