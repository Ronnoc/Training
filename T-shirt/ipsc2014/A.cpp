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
	freopen("a2.in","r",stdin);
	freopen("a2.out","w",stdout);
	int i,j;
	int T;
	cin>>T;
	for(int CASE=1;CASE<=T;++CASE){
		string P,Q;
		cin>>P>>Q;
		string a,b;
		for(i=0;i<Q.SZ&&i<P.SZ;i++)
			if(Q[i]!=P[i])break;
		for(j=i;j<Q.SZ;j++)a+="<";
		for(j=i;j<P.SZ;j++)a+=P[j];
		a+="*";
		b="*"+P+"*";
		if(a.SZ<b.SZ)cout<<a<<endl;
		else cout<<b<<endl;
		//printf("Case #%d:",CASE);
	}
	return 0;
}
