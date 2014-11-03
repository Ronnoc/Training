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
int n;
char s[3005][3005];
double G[3005][3005];
double D[3005];
double q[3005],r[3005];
int main() {
	int i,j,k,T;
	double a=0.85;
	while(~scanf("%d",&n)){
		for(i=0;i<n;i++)scanf("%s",s[i]);
		for(i=0;i<n;i++){
			int cnt=0;
			for(j=0;j<n;j++)if(s[i][j]=='1')cnt++;
			for(j=0;j<n;j++){
				if(s[i][j]=='1')G[j][i]=0.85/cnt;
				else G[j][i]=0;
			}
		}
		for(i=0;i<n;i++)for(j=0;j<n;j++)G[i][j]+=0.15/n;
		for(i=0;i<n;i++)G[i][i]-=1;
		for(i=0;i<n;i++)for(j=0;j<n;j++)if(i!=j)G[i][j]*=-1;
		for(i=0;i<n;i++){
			D[i]=1./G[i][i];
			G[i][i]=0;
		}
		for(i=0;i<n;i++)for(j=0;j<n;j++)G[i][j]*=D[i];
		for(i=0;i<n;i++)q[i]=1;
		while(1){
			for(i=0;i<n;i++)r[i]=0;
			for(i=0;i<n;i++)for(j=0;j<n;j++)r[i]+=G[i][j]*q[j];
			double mx=fabs(q[0]-r[0]);
			for(i=1;i<n;i++){
				double tp=fabs(q[i]-r[i]);
				cmax(mx,tp);
			}
			for(i=0;i<n;i++)q[i]=r[i];
			if(mx<1e-7)break;
		}
		if(n)printf("%.2f",q[0]);
		for(i=1;i<n;i++)printf(" %.2f",q[i]);
		printf("\n");
	}
	return 0;
}
