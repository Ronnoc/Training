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
#define SQ(x) ((x)*(x))
#define SSP system("pause")
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
typedef long long LL;
typedef pair<int, int> PII;
int l[111],r[111],n;
int main(){
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d%d",&l[i],&r[i]);
	int tot=0;
	for(int q=l[1]+1;q<=r[1];q++){
		int ok=0;
		for(i=2;i<=n;i++)if(q>l[i]&&q<=r[i])ok=1;
//		cout<<q<<" "<<ok<<endl;
		if(!ok)tot++;
	}
	cout<<tot<<endl;
	return 0;
}
