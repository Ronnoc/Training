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

int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,T;
	LL n,a,b;
	while(cin>>n>>a>>b){
		n*=6;
		if(a*b>=n){
			cout<<a*b<<endl<<a<<" "<<b<<endl;
			continue;
		}
		LL N=-1,A,B;
		for(LL i=a;i*i<=n;i++){
			LL j=(n-1)/i+1;
			if(j<b)j=b;
			if(i*j>=n){
				if(~N){if(i*j<N)N=i*j,A=i,B=j;}
				else N=i*j,A=i,B=j;
			}
		}
		for(LL j=b;j*j<=n;j++){
			LL i=(n-1)/j+1;
			if(i<a)i=a;
			if(i*j>=n){
				if(~N){if(i*j<N)N=i*j,A=i,B=j;}
				else N=i*j,A=i,B=j;
			}
		}
		cout<<N<<endl<<A<<" "<<B<<endl;
	}
	return 0;
}
