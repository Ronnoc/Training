#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
#define MP make_pair
#define PB push_back
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
const LL MOD = 1000000007;
const double PI = acos(-1.);
const double eps = 1e-9;
int main(){
	int i,j,k,_T;
	int p,a,b;
	scanf("%d%d%d",&p,&a,&b);
	if(b>p)printf("-1\n");
	else if(p>=a+b)printf("%d\n",p);
	else printf("%d\n",a+b);
	return 0;
}