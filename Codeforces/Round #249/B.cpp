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
	int i,j,k;
	char s[111];
	int n;
	while(~scanf("%s%d",s,&n)){
		int len=strlen(s);
		for(i=0;i<len;i++){
			char c=s[i];
			int t=0;
			for(j=1;i+j<len&&j<=n;j++)if(s[i+j]>c)
				c=s[i+j],t=j;
			n-=t;
			for(j=i+t;j>i;j--)swap(s[j],s[j-1]);
//			cout<<s<<" "<<n<<endl;
		}
		printf("%s\n",s);
	}
	return 0;
}
/*
1209 3
*/
