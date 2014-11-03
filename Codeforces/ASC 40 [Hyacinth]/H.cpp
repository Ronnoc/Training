#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define MP make_pair
#define PB push_back
#define AA first
#define BB second
#define SZ size()
#define OP begin()
#define ED end()
#define BG begin()
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
#define SQ(x) ((x)*(x))

bool isprime(int x) {
	if(x<2)return 0;
	for(int i=2; i*i<=x; i++)if(x%i==0)return 0;
	return 1;
}
int main() {
	int i,j;
	freopen("Hans.txt","w",stdout);
	vector<double>L;
	i=0;
	while(L.SZ<30) {
		++i;
		if(isprime(i))L.PB(i);
	}
	double pro=1;
	for(i=0; i<L.SZ; i++) {
		pro*=L[i];
	}
	for(int m=1; m<=30; m++) {
		double best=1;
		for(i=0;i<m;i++)best*=L[i];
		best-=1;
		int mask=0;
		for(i=0; i<1<<m; i+=2) {
			double le=1,re=1;
			for(j=0; j<m; j++)
				if(i>>j&1)le*=L[j];
				else re*=L[j];
			if(le>re)swap(le,re);
			if(re-le<best)best=re-le,mask=i;
		}
		printf("%d,",mask);
	}
	return 0;
}
