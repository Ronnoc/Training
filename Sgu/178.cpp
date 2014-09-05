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

LL solve(LL p,int c){
	cout<<p<<" "<<c<<endl;
	if(p<=c+1)return 0;
//	if(p<=3*c+7)return 1;
	LL a=(p-c-1)/2;
	return 1+solve(a,c+1);
}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,n,m,u,v,T;
	LL p;
	while(cin>>p){
		if(p==1){cout<<0<<endl;continue;}
		for(i=1;;i++){
			LL sum=i,tp=i+1;
			for(j=1;j<=i+1;j++){
				sum+=tp;
				tp<<=1;
			}
			if(sum>=p)break;
		}
		cout<<i<<endl;
	}
	return 0;
}

