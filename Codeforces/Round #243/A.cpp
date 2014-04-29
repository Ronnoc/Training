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
int a[222],n,k;
int main(){
	int i,j;
	while(cin>>n>>k){
		for(i=1;i<=n;i++)cin>>a[i];
		int l,r;
		int ans=-MOD;
		for(l=1;l<=n;l++)for(r=l;r<=n;r++){
			vector<int>inn;
			vector<int>out;
			for(i=1;i<l;i++)out.PB(a[i]);
			for(i=l;i<=r;i++)inn.PB(a[i]);
			for(i=r+1;i<=n;i++)out.PB(a[i]);
			SORT(inn);
			SORT(out);
			reverse(out.OP,out.ED);
			vector<int>sp;
			int tot=0;
			for(i=0;i<inn.SZ&&i<k;i++)sp.PB(inn[i]),tot++;
			for(i=0;i<out.SZ&&i<k;i++)sp.PB(out[i]);
			int all=0;
			for(i=tot;i<inn.SZ;i++)all+=inn[i];
			SORT(sp);
			reverse(sp.OP,sp.ED);
			for(i=0;i<tot;i++)all+=sp[i];
			cmax(ans,all);
//			cout<<l<<" "<<r<<" "<<all<<endl;
		}
		printf("%d\n",ans);
	}
	return 0;
}
