#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define MP make_pair
#define PB push_back
#define AA first
#define BB second
#define SZ size()
#define OP begin()
#define ED end()
#define BG begin()
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
#define SQ(x) ((x)*(x))
#define PROM "elections"
LL dp[13][53][103];
LL pre[13][53][103];
vector<int>ma[13];
LL v[13],V;
int sum[13][105];
LL mabs(LL a){return a<0?-a:a;}
void update(int i,int j,int k,LL tp,int dlt){
	if(~dp[i][j][k]){
		if(dp[i][j][k]>tp)
			dp[i][j][k]=tp,pre[i][j][k]=dlt;
	}
	else dp[i][j][k]=tp,pre[i][j][k]=dlt;
}
int main() {
	freopen(PROM".in", "r", stdin);
	freopen(PROM".out", "w", stdout);
	int i,j,k,l;
	int n,s;
	while(~scanf("%d%d",&n,&s)) {
		for(V=0,i=1; i<=n; i++) {
			scanf("%I64d",&v[i]);
			V+=v[i];
			int m,t;
			scanf("%d",&m);
			ma[i].clear();
			while(m--) {
				scanf("%d",&t);
				if(t>100)continue;
				ma[i].PB(t);
			}
			for(j=0; j<=100; j++)sum[i][j]=0;
			for(j=0; j<ma[i].SZ; j++)sum[i][ma[i][j]]++;
			for(j=1; j<=100; j++)sum[i][j]+=sum[i][j-1];
		}
		int A;
		LL au,ad=-1;
		vector<int>al;
		for(A=s; A<=s+50; A++) {
			for(i=1; i<=n+1; i++)
				for(j=0; j<=s; j++)
					for(k=0; k<=A; k++)
						dp[i][j][k]=-1;
			dp[1][0][0]=0;
			for(i=1; i<=n; i++)
				for(j=0; j<=s; j++)
					for(k=0; k<=A; k++)if(~dp[i][j][k]) {
							for(l=0;;l++){
								int ds=l-sum[i][l];
								if(ds+j>s)break;
								if(k+l>A)break;
								update(i+1,j+ds,k+l,dp[i][j][k]+mabs(V*l-A*v[i]),l);
							}
						}
			if(-1==dp[n+1][s][A])continue;
			LL uu=dp[n+1][s][A];
			LL dd=A*V;
			LL gg=__gcd(uu,dd);
			uu/=gg,dd/=gg;
//			cerr<<A<<" "<<uu<<"/"<<dd<<"\n";
			if(ad==-1||1.*uu*ad<1.*au*dd){
				au=uu,ad=dd;
				int ii=n+1,jj=s,kk=A;
				al.clear();
//				for(i=1; i<=n+1; i++)
//					for(j=0; j<=s; j++)
//						for(k=0; k<=A; k++)
//							if(~dp[i][j][k])cerr<<i<<" "<<j<<" "<<k<<" "<<dp[i][j][k]<<" "<<pre[i][j][k]<<"\n";
				while(ii>1){
					l=pre[ii][jj][kk];
//					cerr<<ii<<" "<<jj<<" "<<kk<<"?"<<dp[ii][jj][kk]<<"?"<<l<<"@"<<(l-sum[ii][l])<<"\n";
					i=ii-1;
					j=jj-(l-sum[ii-1][l]);
					k=kk-l;
					ii=i,jj=j,kk=k;
					al.PB(l);
				}
			}
		}
		reverse(al.OP,al.ED);
		for(i=0;i<al.SZ;i++)cout<<al[i]<<"\n";
	}
	return 0;
}
/*
3 12
10
3 1 2 3
5
0
5
0
*/
/*
3 8
10
3 2 4 7
5
1 3
5
2 1 2
*/
