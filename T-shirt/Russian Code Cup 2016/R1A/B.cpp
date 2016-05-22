#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
#define MP make_pair
#define PB emplace_back
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
int a[100005];
int b[100005];
int main(){
	int i,j,k,_T;
	scanf("%d",&_T);
	while(_T--){
		int n,h;
		scanf("%d%d",&n,&h);
		for(i=1;i<=n;i++)scanf("%d",&a[i]);
		for(i=1;i<=n;i++)scanf("%d",&b[i]);
		int ans=0;
		if(!b[1])
			ans+=b[1]=1;
		if(!b[n])
			ans+=b[n]=1;
		LL sum=0;
		LL mxr=-1;
		LL last=-1;
		for(i=1;i<=n;i++){
			LL le=(sum-h)*2+1;
			LL re=(sum+a[i])*2-1;
			if(le>last){
				last=mxr;
				ans++;
			}
			if(b[i])cmax(last,re);
			else cmax(mxr,re);
			sum+=a[i];
			//cout<<le<<"~"<<re<<" "<<last<<" "<<mxr<<"\n";
		}
		printf("%d\n",ans);
	}
	return 0;
}