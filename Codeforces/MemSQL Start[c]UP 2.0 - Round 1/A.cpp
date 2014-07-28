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
char mp[22][22]={"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};
int main(){
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,n;
	while(~scanf("%d",&n)){
		char s[111];
		scanf("%s",s);
		int len=strlen(s);
		for(i=0;i<8;i++){
			int li=strlen(mp[i]);
			if(li!=len)continue;
			int flag=1;
			for(j=0;s[j];j++)if(s[j]!='.'&&s[j]!=mp[i][j])flag=0;
			if(flag){
				cout<<mp[i]<<endl;
			break;
			}
		}
	}
	return 0;
}
