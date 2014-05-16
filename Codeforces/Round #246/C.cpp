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
#include <iomanip>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define SORT(x) sort(x.OP,x.ED)
#define SQ(x) ((x)*(x))
#define SSP system("pause")
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
typedef long long LL;
typedef pair<int, int> PII;
const double eps=1e-8;
const double INF=1e20;
const double PI=acos( -1. );
const int MXN = 50;
const LL MOD = 1000000007;
int a[111111];
int b[111111];
vector<PII>ans;
int pre[111111];
int isp[111111];
int prime[111111],np;
void play(int p,int q){
	//cout<<p<<" "<<q<<endl;
	ans.PB(MP(p,q));
	int vp=a[p],vq=a[q];
	a[p]=vq,a[q]=vp;
	b[vq]=p,b[vp]=q;
}
int main(){
	memset(pre,-1,sizeof pre);
	int i,j;
	int n;
	for(i=3;i<=100000;i++)isp[i]=i&1;
	for(isp[2]=1,i=3;i<=100000;i+=2)if(isp[i])
		for(LL j=1LL*i*i;j<=100000;j+=2*i)
			isp[j]=0;
	np=0;
	for(i=2;i<=100000;i++)if(isp[i])prime[++np]=i;
	pre[1]=0;
	for(i=1;i<=100000;i++)if(pre[i]==-1){
		int id=lower_bound(prime+1,prime+np+1,i+5)-prime;
		for(j=id;j>=1;j--){
			if(i<prime[j]-1)continue;
			if(~pre[i-prime[j]+1]){
				pre[i]=prime[j];
				break;
			}
		}
	}
	while(~scanf("%d",&n)){
		ans.clear();
		for(i=1;i<=n;i++)scanf("%d",&a[i]);
		for(i=1;i<=n;i++)b[a[i]]=i;
		for(i=1;i<=n;i++){
			if(i==b[i])continue;
			int dis=b[i]-i+1;
			while(dis>1){
				play(b[i]-pre[dis]+1,b[i]);
				dis=b[i]-i+1;
			}
		}
		printf("%d\n",ans.SZ);
		for(i=0;i<ans.SZ;i++)printf("%d %d\n",ans[i].AA,ans[i].BB);
	}
	return 0;
}
/*
4
1 2 4 3
*/
