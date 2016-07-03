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
int w[33];
int main(){
	int i,j,k,_T;
	scanf("%d",&_T);
	while(_T--){
		for(i=0;i<26;i++)
			scanf("%d",&w[i]);
		int sum=0;
		for(i=0;i<26;i++)
			sum+=w[i];
		int me=55;
		for(i=0;i<26;i++)if(w[i])
			cmin(me,w[i]);
		if(sum==0)
			printf("0\n");
		else if(me==sum){
			int ans=0;
			for(i=2;i<=sum;i++)
				ans+=i-1;
			printf("%d\n",ans);
		}else {
			printf("%d\n",me-1);
		}
	}
	return 0;
}