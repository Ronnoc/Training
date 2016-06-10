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
	int w[5];
	for(i=0;i<5;i++)scanf("%d",&w[i]);
	int sum=0;
	for(i=0;i<5;i++)sum+=w[i];
		int ans=sum;
	for(i=0;i<5;i++)
		for(j=i+1;j<5;j++)if(w[i]==w[j]){
			cmin(ans,sum-w[i]*2);
			for(k=j+1;k<5;k++)if(w[j]==w[k]){
				cmin(ans,sum-w[i]*3);
			}
			
		}
		cout<<ans<<"\n";
	return 0;
}