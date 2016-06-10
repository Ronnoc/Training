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
	int a,n,t[111];
	while(~scanf("%d%d",&n,&a)){
		for(i=1;i<=n;i++)scanf("%d",&t[i]);
		int ans=0;
		for(i=0;i<n;i++){
			int sum=0;
			int what=0;
			if(a+i<=n)sum+=t[a+i],what++;
			if(i>0&&a-i>=1)sum+=t[a-i],what++;
			if(sum==what)ans+=sum;
		}
		cout<<ans<<"\n";
	}
	return 0;
}