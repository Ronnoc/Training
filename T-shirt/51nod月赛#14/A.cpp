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
	int n,m;
	scanf("%d",&_T);
	while(_T--){
		scanf("%d%d",&n,&m);
		int cnt=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++){
				scanf("%d",&k);
				cnt+=k;
			}
		if(cnt&1)puts("yadang");
		else puts("xiawa");
	}
	return 0;
}