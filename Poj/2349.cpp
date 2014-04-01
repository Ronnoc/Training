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
#include <fstream>
#include <iomanip>
#include <numeric>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <functional>

using namespace std;

#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define SQ(x) ((x)*(x))

typedef long long LL;
typedef pair<int, int> PII;

vector<pair<double,PII> >L;

double x[555],y[555];
int fa[555];
void iniALL(int n){
	L.clear();
	for(int i=1;i<=n;i++)fa[i]=i;
}
int getfa(int x){
	return x==fa[x]?x:fa[x]=getfa(fa[x]);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int m,n,i;
		scanf("%d%d",&m,&n);
		iniALL(n);
		for(int i=1;i<=n;i++)scanf("%lf%lf",&x[i],&y[i]);
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				L.PB(MP(SQ(x[i]-x[j])+SQ(y[i]-y[j]),MP(i,j)));
		sort(L.begin(),L.end());
		double ans=0.0;
		for(i=0;i<L.size();i++){
			if(n<=m)break;
			int l=L[i].BB.AA;
			int r=L[i].BB.BB;
			if(getfa(l)!=getfa(r)){
				n--;
				fa[getfa(l)]=getfa(r);
				ans=max(ans,L[i].AA);
			}
		}
		printf("%.2f\n",sqrt(ans));
	}
	return 0;
}
