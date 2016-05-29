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
int dp[1<<4][1<<4];
char s[33][33];
int w[33][33];
void solve(){
	int i,j,k;
	int N;
	scanf("%d",&N);
	for(i=0;i<N;i++)
		scanf("%s",s[i]);
	int tot=0;
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			w[i][j]=s[i][j]-'0';
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			tot+=1-w[i][j];
	int ans=tot;
	for(int msk=0;msk<1<<tot;msk++){
		int tid=0;
		int f[33];
		for(i=0;i<N;i++){
			f[i]=0;
			for(j=0;j<N;j++){
				if(w[i][j])f[i]|=1<<j;
				else {
					if(msk>>tid&1)
						f[i]|=1<<j;
					tid++;
				}
			}
		}
		for(i=0;i<1<<N;i++)
			for(j=0;j<1<<N;j++)
				dp[i][j]=0;
		dp[0][0]=1;
		int all=(1<<N)-1;
		int fail=0;
		for(i=0;i<1<<N;i++)
			for(j=0;j<1<<N;j++)if(dp[i][j]){
				int remain_worker=all^i;
				while(remain_worker){
					int worker=remain_worker&-remain_worker;
					worker=__builtin_ctz(worker);
					remain_worker^=1<<worker;
					int remain_machine=all^j;
					int can_machine=remain_machine&f[worker];
					if(!can_machine)
						fail=1;
					else {
						while(can_machine){
							int machine=can_machine&-can_machine;
							machine=__builtin_ctz(machine);
							can_machine^=1<<machine;
							dp[i^(1<<worker)][j^(1<<machine)]=1;
						}
					}
				}
			}
		if(!fail){
			int cost=__builtin_popcount(msk);
			cmin(ans,cost);
		}
	}
	printf("%d\n",ans);
}
int main(){
	int _T;
	scanf("%d",&_T);
	for(int CA=1;CA<=_T;CA++){
		printf("Case #%d: ",CA);
		solve();
	}
	return 0;
}