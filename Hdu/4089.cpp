#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <bitset>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define SZ size()
#define OP begin()
#define ED end()
#define BG begin()
#define SQ(x) ((x)*(x))
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
double F[2005][2005];
double k[2005];
double b[2005];
int main() {
	int i,j;
	int n,m,z;
	while(scanf("%d%d%d",&n,&m,&z)!=EOF){
		double p1,p2,p3,p4;
		scanf("%lf%lf%lf%lf",&p1,&p2,&p3,&p4);
		if(p4<1e-8){
			printf("0.00000\n");
			continue;
		}
		F[1][1]=p4/(p3+p4);
		for(i=2;i<=n;i++){
			k[1]=1;
			b[1]=0;
			for(j=2;j<=i;j++){
				k[j]=p2*k[j-1];
				b[j]=p2*b[j-1]+p3*F[i-1][j-1];
				if(j<=z)b[j]+=p4;
				b[j]/=1-p1,k[j]/=1-p1;
			}
			double A=(1-p1)-p2*k[i];
			double B=b[i]*p2+p4;
			double X=B/A;
			for(j=1;j<=i;j++)
				F[i][j]=k[j]*X+b[j];
		}
		printf("%.5f\n",F[n][m]);
	}
	return 0;
}
