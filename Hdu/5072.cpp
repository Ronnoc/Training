#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>
using namespace std;
typedef long long LL;
typedef pair<int,int>PII;
#define MP make_pair
#define PB push_back
#define SZ size()
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define BG begin()
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
#define SQ(x) ((x)*(x))

const int MXN = 100000;
int tot[100005];
int f[100005];
vector<int>G[100005];
int mu[MXN+5],p[MXN+5],pn;
bool flag[MXN+5];	//true ==> not a prime
void init(int n){
	pn=0,mu[1]=1;
	for(int i=2;i<=n;i++){
		if(!flag[i])
			p[pn++]=i,mu[i]=-1;
		for(int j=0;j<pn&&i*p[j]<=n;j++){
			flag[i*p[j]]=1;
			if(i%p[j]==0){
				mu[i*p[j]]=0;
				break;
			}else mu[i*p[j]]=-mu[i];
		}
	}
}
LL pro[1<<10];
int main() {
	int i,j;
	init(MXN);
	for(i=0;i<pn;i++)
		for(j=p[i];j<=MXN;j+=p[i])
			G[j].PB(p[i]);
	int T;
	scanf("%d",&T);
	while(T--){
		memset(tot,0,sizeof tot);
		memset(f,0,sizeof f);
		int n;
		scanf("%d",&n);
		int mx=-1;
		for(i=0;i<n;i++){
			scanf("%d",&j);
			tot[j]++;
			cmax(mx,j);
		}
		for(i=1;i<=mx;i++)
			for(j=i;j<=mx;j+=i)
				f[i]+=tot[j];
		LL all=1LL*n*(n-1)*(n-2)/6;
		LL sum=0;
		for(i=1;i<=mx;i++)if(tot[i]){
			LL add=f[1];
			pro[0]=1;
			for(j=1;j<1<<G[i].SZ;j++){
				int id=__builtin_ctz(j);
				pro[j]=pro[j^(1<<id)]*G[i][id];
				add+=mu[pro[j]]*f[pro[j]];
			}
			if(i==1)add--;
			sum+=add*(f[1]-1-add);
		}
		sum/=2;
		all-=sum;
		printf("%I64d\n",all);
	}
	return 0;
}
/*
3
5
1 3 9 10 2
6
1 3 7 2 4 6
5
1 2 3 6 12
*/
