#include<cstdio>
#include<vector>
#include<iostream>
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
const double eps = 1e-9;
int N,M,L,km;
int a[10005];
int S[10005];
int dp[10005][11];
int nextid;
struct node{
	int _[2];
	int f[11];
	node(){init();}
	void init(){_[0]=_[1]=-1,memset(f,-1,sizeof f);}
}T[666666];
bool check(int mid){
	int i,j,k;
	nextid=0;
	int root=nextid;
	T[nextid++].init();
	int now=root;
	T[now].f[0]=0;
	for(i=0;i<km;i++){
		if(-1==T[now]._[0]){
			T[now]._[0]=nextid;
			T[nextid++].init();
		}
		now=T[now]._[0];
		T[now].f[0]=0;
	}
	for(i=1;i<=N;i++)
		for(j=1;j<=M;j++){
			dp[i][j]=0;
			int now=root;
			for(k=km-1;k>=0;k--){
				int my=S[i]>>k&1;
				if(mid>>k&1){
					if(~T[now]._[my^1])
						now=T[now]._[my^1];
					else break;
				}else {
					int free=T[now]._[my^1];
					if(~free&&~T[free].f[j-1]&&i-T[free].f[j-1]<=L){
						dp[i][j]=1;
						break;
					}
					if(~T[now]._[my]){
						now=T[now]._[my];
					}else break;
				}
			}
			if(k==-1&&~T[now].f[j-1]&&i-T[now].f[j-1]<=L)
				dp[i][j]=1;
			if(dp[i][j]){
				int now=root;
				T[now].f[j]=i;
				for(k=km-1;k>=0;k--){
					int my=S[i]>>k&1;
					if(-1==T[now]._[my]){
						T[now]._[my]=nextid;
						T[nextid++].init();
					}
					now=T[now]._[my];
					T[now].f[j]=i;
				}
			}
		}
	return dp[N][M];
}
int main(){
	int i,j,k,_T;
	scanf("%d",&_T);
	for(int CA=1;CA<=_T;CA++){
		printf("Case #%d:\n",CA);
		scanf("%d%d%d",&N,&M,&L);
		for(i=1;i<=N;i++)
			scanf("%d",&a[i]);
		S[0]=0;
		for(i=1;i<=N;i++)
			S[i]=S[i-1]^a[i];
		int me=*max_element(a+1,a+N+1);
		km=0;
		while(me>>km)km++;
		int le=0,re=(1<<km)-1,ge=-1;
		while(re>=le){
			if(re-le<=1){
				if(check(re))ge=re;
				else ge=le;
				break;
			}
			int mid=(le+re)>>1;
			if(check(mid))le=mid;
			else re=mid;
		}
		printf("%d\n",ge);
	}
	return 0;
}