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
#define UNIQUE(x) x.erase(unique(x.OP,x.ED),x.ED)
typedef long long LL;
typedef pair<int, int> PII;

void solve(){
	int n,k;
	while(cin>>n>>k){
		int res=0;
		int x,i;
		for(i=1;i<=n;i++){
			scanf("%d",&x);
			set<int>S;
			while(x){S.insert(x%10);x/=10;}
			int wa=0;
			for(int j=0;j<=k;j++)if(S.find(j)==S.ED)wa=1;
			if(!wa)res++;
		}
		cout<<res<<endl;
	}
}
int main(){
//	while(1)
		solve();
	return 0;
}
