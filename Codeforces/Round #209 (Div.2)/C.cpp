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
LL n,x;
LL a[111111];
LL b[111111];
map<LL,int>ac;
map<LL,int>::iterator iter;
const LL mod = 1000000007 ;
int main() {
	while (cin>>n>>x) {
		ac.clear();
		int i;
		for (i=1; i<=n; i++) cin>>a[i];
		LL tot=0;
		for (i=1; i<=n; i++) tot+=a[i];
		for (i=1; i<=n; i++) b[i]=tot-a[i];
		for (i=1; i<=n; i++)
			ac[b[i]]++;
		LL ans=0;
		for (iter=ac.begin(); iter!=ac.end(); ++iter) {
			pair<LL,int> temp=*iter;
			if (temp.BB%x!=0) {
				ans=temp.AA;
				break;
			} else {
				LL s=temp.BB/x;
				ac[temp.AA]=0;
				ac[temp.AA+1]+=s;
			}
		}
		ans=min (ans,tot);
		LL res=1;
		while (ans) {
			if (ans&1) res= (res*x) %mod;
			x= (x*x) %mod;
			ans/=2;
		}
		cout<<res<<endl;
	}
	return 0;
}
