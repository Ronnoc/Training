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
#define UNIQUE(x) x.erase(unique(x.OP,X.ED),x.ED)
typedef long long LL;
typedef pair<int, int> PII;
char s[200005];
vector<pair<char,int> >L;
void solve(){
	while(~scanf("%s",s)){
		L.clear();
		int len=strlen(s);
		int i,j;
		char c=s[0];
		int now=0;
		for(i=0;i<=len;i++){
			if(s[i]==c)now++;
			else {
				L.PB(MP(c,now));
				now=1;c=s[i];
			}
		}
//		for(i=0;i<L.SZ;i++)cout<<"("<<L[i].AA<<","<<L[i].BB<<")"<<endl;
		for(i=0;i<L.SZ;i++)if(L[i].BB>2)L[i].BB=2;
		for(i=0;i<L.SZ;i++){
			if(L[i].BB==2){
				int r=i;
				while(r<L.SZ&&L[r].BB==2)r++;
				r--;
				int l=i;
				int dis=r-l+1;
				if(dis<=1)continue;
				for(j=0;l+j<=r;j++)if(j&1)L[l+j].BB=1;
				i=r;
			}
		}
		for(i=0;i<L.SZ;i++)for(j=0;j<L[i].BB;j++)cout<<L[i].AA;
		cout<<endl;
	}
}
int main(){
//	while(1)
		solve();
	return 0;
}
