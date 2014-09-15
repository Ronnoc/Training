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
struct frac{
	LL a,b;
	frac(LL p=0,LL q=1){a=p,b=q;LL g=__gcd(p,q);a/=g,b/=g;if(b<0)b=-b,a=-a;}
	frac operator + (frac f){LL g=__gcd(b,f.b);LL B=b/g,C=f.b/g;return frac(a*C+f.a*B,B*C*g);}
	frac operator - (frac f){return (*this)+frac(-f.a,f.b);}
};
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,T;
	int n;
	while(scanf("%d",&n)!=EOF){
		frac A;
		for(i=1;i<=n;i++)A=A+frac(n,i);
		LL a,p=A.a,q=A.b;
		a=p/q;
		p-=a*q;
		if(p){
			char s[111];
			sprintf(s,"%I64d",a);
			int lena=strlen(s);
			sprintf(s,"%I64d",q);
			int lenq=strlen(s);
			for(i=0;i<=lena;i++)printf(" ");
			printf("%I64d\n",p);
			printf("%I64d ",a);
			for(i=1;i<=lenq;i++)printf("-");
			printf("\n");
			for(i=0;i<=lena;i++)printf(" ");
			printf("%I64d\n",q);
		}else printf("%I64d\n",a);
	}
	return 0;
}
