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
/*
+------------------------+
|#.#.#.#.#.#.#.#.#.#.#.|D|)
|#.#.#.#.#.#.#.#.#.#.#.|.|
|#.......................|
|#.#.#.#.#.#.#.#.#.#.#.|.|)
+------------------------+
*/
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,_T;
	int n;
	while(~scanf("%d",&n)) {
		char s[][33]= {
			"+------------------------+",
			"|#.#.#.#.#.#.#.#.#.#.#.|D|)",
			"|#.#.#.#.#.#.#.#.#.#.#.|.|",
			"|#.......................|",
			"|#.#.#.#.#.#.#.#.#.#.#.|.|)",
			"+------------------------+"
		};
		int len=strlen(s[0]);
		for(j=0; j<len&&n; j++)
			for(i=0; i<6&&n; i++)if(s[i][j]=='#')s[i][j]='O',n--;
		for(i=0; i<6; i++)cout<<s[i]<<"\n";
	}
	return 0;
}
