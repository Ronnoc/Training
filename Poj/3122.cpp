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
double S[10111];
int main(){
	int i,j;
	int T;
	scanf("%d",&T);
	for(int CASE=1;CASE<=T;++CASE){
		int n,f;
		scanf("%d%d",&n,&f);
		f++;
		for(i=1;i<=n;i++)scanf("%lf",&S[i]);
		for(i=1;i<=n;i++)S[i]=SQ(S[i])*PI;
		double l=0,r=0;
		for(i=1;i<=n;i++)cmax(r,S[i]);
		for(int t=0;t<=100;t++){
			double mid=(l+r)/2;
			int tot=0;
			for(i=1;i<=n;i++)tot+=(S[i]+eps)/mid;
			if(tot>=f)l=mid;
			else r=mid;
		}
		printf("%.4f\n",(l+r)/2);
	}
	return 0;
}
