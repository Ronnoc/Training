//kybconnor 2Y
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
using namespace std;
#define AA first
#define BB second
#define MP make_pair
map<int,int>dp[13][105][105];
map<int,pair<pair<int,int>,int > >pre[13][105][105];
map<int,int>::iterator it,tt;
vector<pair<int,int> >Q[111];
int sswr (int p,int q) {
	double d=p*100.0/q;
	int ret=int (d+0.500000);
	int l=d,r=d+1;
	double dl=d-l;
	double dr=r-d;
	if (dl>dr-1e-8&&dl<dr+1e-8) {
		if (l&1) return r;
		if (r&1) return l;
	}
	if (dl>dr) return r;
	if (dr>dl) return l;
	return ret;
}
int t,n,m;
int w[13];
int main() {
	freopen("javacert.in","r",stdin);
	freopen("javacert.out","w",stdout);
	int i,j;
	for (i=1; i<=100; i++) {
		for (j=0; j<=i; j++) {
			int s=sswr (j,i);
			pair<int,int> tmp;
			tmp.AA=j;
			tmp.BB=i;
			Q[s].push_back (tmp);
		}
	}
//	cout<<sswr(2,7);
//	for(i=0;i<=8;i++)cout<<sswr(i,8)<<" ";
//	cout<<endl;
	while (scanf ("%d%d%d",&t,&n,&m) !=EOF) {
		int i,j,k,l,r,q,s;
		for (i=1; i<=m; i++) scanf ("%d",&w[i]);
		for (i=0; i<=m; i++) for (j=0; j<=t; j++) for (k=j; k<=n; k++) dp[i][j][k].clear();
		for (i=0; i<=m; i++) for (j=0; j<=t; j++) for (k=j; k<=n; k++) pre[i][j][k].clear();
		dp[0][0][0][n]=0;
		for (i=1; i<=m; i++) {
			for (j=0; j<=t; j++) for (k=j; k<=n; k++) {
					for (it=dp[i-1][j][k].begin(); it!=dp[i-1][j][k].end(); ++it) {
						l= (*it).AA;
						r= (*it).BB;
						for (q=0; q<Q[w[i]].size(); q++) {
							int a=Q[w[i]][q].AA;
							int b=Q[w[i]][q].BB;
							int nl=min (l,b);
							int nr=max (r,b);
							int &tp=dp[i][j+a][k+b][nl];
							if (k+b>n) break;
							if (j+a>t) break;
//							printf ("(%d,%d,%d)=<%d,%d> --> ",i-1,j,k,l,r);
//							printf (" [%d,%d] --> ",a,b);
//							printf ("(%d,%d,%d)=<%d,%d> \n",i,j+a,k+b,nl,nr);
							//dp[i+1][j+a][k+b][nl]=nr;
							if (tp==0) {
								tp=nr;
								pre[i][j+a][k+b][nl]=MP (MP (a,b),l);
							} else if (nr<tp) {
								tp=nr;
								pre[i][j+a][k+b][nl]=MP (MP (a,b),l);
							}
						}
					}
				}
				
		}
		int ans=-1;
		int pl,pr;
		for (it=dp[m][t][n].begin(); it!=dp[m][t][n].end(); ++it) {
			l= (*it).AA;
			r= (*it).BB;
			if (ans==-1) ans=r-l,pl=l,pr=r;
			else if (r-l<ans) ans=r-l,pl=l,pr=r;
		}
//		printf ("%d %d %d\n",ans,pl,pr);
		i=m,j=t,k=n,l=pl;
		vector<pair<int,int> >L;
		while (i) {
//			cout<<i<<" "<<j<<" "<<k<<" "<<l<<endl;
			L.push_back (pre[i][j][k][l].AA);
			int ii=i-1;
			int jj=j-pre[i][j][k][l].AA.AA;
			int kk=k-pre[i][j][k][l].AA.BB;
			int ll=pre[i][j][k][l].BB;
			i=ii;
			j=jj;
			k=kk;
			l=ll;
//			cout<<i<<" "<<j<<" "<<k<<" "<<l<<endl;
//			cout<<endl;
		}
		for (i=L.size()-1; i>=0; i--) printf ("%d %d\n",L[i].BB-L[i].AA,L[i].BB);
	}
	return 0;
}
/*
1 100 2
0
50
100 100 10
100
100
100
100
100
100
100
100
100
100
0 100 10
0 0 0 0 0
0 0 0 0 0

*/
