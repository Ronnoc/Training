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

double t[555];
int n,A,B,C,p,q,r;
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k;
	int T,a,b,c;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d%d%d%d",&n,&A,&B,&C,&p,&q,&r);
		memset(t,0,sizeof t);
		double foo=1.0-1.0/(A*B*C);
		t[0]=1;
		for(a=1;a<=A;a++)for(b=1;b<=B;b++)for(c=1;c<=C;c++)
			t[a+b+c]+=1.0/(A*B*C);
		t[p+q+r]-=1.0/(A*B*C);
		for(i=0;i<=A+B+C;i++)t[i]/=foo;
		
		for(i=1;i<=n;i++){
//			cout<<"E[0]="<<t[0];
//			for(j=1;j<=n;j++)cout<<"+"<<t[j]<<"*E["<<j<<"]";
//			cout<<endl;
			t[0]+=t[i];
			for(a=1;a<=A;a++)for(b=1;b<=B;b++)for(c=1;c<=C;c++)
				t[i+a+b+c]+=t[i]/(A*B*C);
			t[i+p+q+r]-=t[i]/(A*B*C);
			foo=1.0-t[i]/(A*B*C);
			for(j=i+1;j<=i+A+B+C&&j<=n;j++)t[j]/=foo;
			t[0]/=foo;
			t[i]=0;
		}
		printf("%.15f\n",t[0]);
	}
	return 0;
}
/*
5
0 2 2 2 1 1 1
1 2 2 2 1 1 1
2 2 2 2 1 1 1
3 2 2 2 1 1 1
4 2 2 2 1 1 1
*/
