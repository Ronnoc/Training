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
LL w[13][13];
int main(){
	int i,j,k,_T;
	int n,t;
	while(~scanf("%d%d",&n,&t)){
		memset(w,0,sizeof w);
		w[0][0]=t;
		int ans=0;
		for(i=0;i<n;i++){
			for(j=0;j<=i;j++){
				if(w[i][j]>=(1<<i)){
					ans++;
					w[i][j]-=1<<i;
					w[i+1][j]+=w[i][j];
					w[i+1][j+1]+=w[i][j];
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}