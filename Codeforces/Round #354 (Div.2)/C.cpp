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
char c[100005];
int S[100005];
int fa(int le,int re){return S[re]-S[le-1];}
int fb(int le,int re){return re-le+1-fa(le,re);}
int main(){
	int i,j,k,_T;
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		scanf("%s",c+1);
		S[0]=0;
		for(i=1;i<=n;i++)
			S[i]=S[i-1]+(c[i]=='a');
		int ans=m;
		for(i=1;i<=n;i++){
			int le=i,re=n,ge=-1;
			while(re>=le){
				if(re-le<=1){
					if(fa(i,re)<=m)
						ge=re;
					else ge=le;
					break;
				}
				int mid=(re+le)>>1;
				if(fa(i,mid)<=m)le=mid;
				else re=mid;
			}
			cmax(ans,ge-i+1);
			le=i,re=n,ge=-1;
			while(re>=le){
				if(re-le<=1){
					if(fb(i,re)<=m)
						ge=re;
					else ge=le;
					break;
				}
				int mid=(re+le)>>1;
				if(fb(i,mid)<=m)le=mid;
				else re=mid;
			}
			cmax(ans,ge-i+1);
		}
		cout<<ans<<"\n";
	}
	return 0;
}