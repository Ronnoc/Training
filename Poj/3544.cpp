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
LL w[1111],p[1111],d[1111];
int n;
LL t;
int main(){
//	freopen("journey.in","r",stdin);
//	freopen("journey.out","w",stdout);
	int i,j;
	while(cin>>n>>t){
		for(i=1;i<=n;i++)cin>>w[i];
		for(i=1;i<=n;i++)cin>>d[i];
		for(i=1;i<=n;i++)cin>>p[i];
		vector<pair<LL,int> >city;
		vector<pair<LL,int> >pig;
		for(i=1;i<=n;i++)city.PB(MP(p[i]-d[i]*t,i));
		for(i=1;i<=n;i++)pig.PB(MP(w[i],i));
		SORT(city);
		SORT(pig);
		vector<PII>L;
		for(i=0;i<pig.SZ;i++)L.PB(MP(city[i].BB,pig[i].BB));
		SORT(L);
		for(i=0;i<L.SZ;i++)printf("%d ",L[i].BB);
		printf("\n");
	}
	return 0;
}
