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

int main(){
	int i,j;
	int T;
	cin>>T;
	while(T--){
		int n,l,r;
		cin>>n>>l>>r;
		int k=n/r;
		while(k*r<n)k++;
		int flag=0;
		if(k*l<=n&&k*r>=n)flag=1;
		k=n/l;
		while(k*l>n)k--;
		if(k*l<=n&&k*r>=n)flag=1;
		if(flag)cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}
