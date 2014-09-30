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
#include <cassert>
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
const double PI=acos( -1. );
const LL MOD = 1000000007;
int a[100005];
int st[100005][20];
int call(int l,int r){
	int tot=r-l+1;
	int id=31-__builtin_clz(tot);
	int len=1<<id;
	int ir=r-len+1;
	return __gcd(st[l][id],st[ir][id]);
}
vector<pair<PII,int> >F[100005];
vector<LL>S[100005];
LL tot[100005];
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,T;
	scanf("%d",&T);
	for(int CA=1;CA<=T;CA++){
		printf("Case #%d:\n",CA);
		for(i=1;i<=100000;i++)F[i].clear(),S[i].clear();
		int n,m;
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)scanf("%d",&a[i]);
		for(i=1;i<=n;i++)for(j=0;j<=20;j++)st[i][j]=0;
		for(i=1;i<=n;i++)st[i][0]=a[i];
		for(j=1;j<=20;j++){
			int mx=n-(1<<j)+1;
			for(i=1;i<=mx;i++)
				st[i][j]=__gcd(st[i][j-1],st[i+(1<<(j-1))][j-1]);
		}
		for(i=1;i<=n;i++){
			int j=i;
			while(j<=n){
				int g=call(i,j);
				int l=j,r=n,b=-1;
				while(r>=l){
					if(r-l<=1){
						if(call(i,r)==g){
							b=r;break;
						}
						if(call(i,l)==g)b=l;
						break;
					}
					int mid=(r+l)>>1;
					if(call(i,mid)<g)r=mid;
					else l=mid;
				}
				F[g].PB(MP(MP(i,b-j+1),j));
//				cout<<g<<" "<<i<<" :"<<(b-j+1)<<" @"<<j<<endl;
				j=b+1;
			}
		}
		for(tot[0]=0,i=1;i<=100000;i++){
			SORT(F[i]);
			LL sum=0;
			for(j=0;j<F[i].SZ;j++){
				sum+=F[i][j].AA.BB;
				S[i].PB(sum);
			}
			tot[i]=tot[i-1]+((sum>0)?1:0);
		}
		char s[22];
		LL p,q;
		while(m--){
			scanf("%s%I64d%I64d",s,&p,&q);
			if(s[0]=='S'){
				int g=lower_bound(tot,tot+100001,p)-tot;
				int ih=lower_bound(S[g].OP,S[g].ED,q)-S[g].OP;
				if(g<=100000&&ih<S[g].SZ){
					int a=F[g][ih].AA.AA;
					int b=F[g][ih].AA.BB;
					int c=F[g][ih].BB;
					printf("%d %d\n",a,c+b-1-(S[g][ih]-q));
				}else printf("-1\n");
			} else {
				int g=call(p,q);
				int ih=lower_bound(F[g].OP,F[g].ED,MP(MP((int)p,-1),-1))-F[g].OP;
				printf("%I64d %I64d\n",tot[g],S[g][ih]-(F[g][ih].BB+F[g][ih].AA.BB-1-q));
			}
		}
	}
	return 0;
}
