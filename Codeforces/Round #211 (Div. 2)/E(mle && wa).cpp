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
#include <fstream>
#include <iomanip>
#include <numeric>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <functional>

using namespace std;

#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define SQ(x) ((x)*(x))
#define SORT(x) sort(x.OP,x.ED)
#define UNIQUE(x) x.erase(unique(x.OP,X.ED),x.ED)
typedef long long LL;
typedef pair<int, int> PII;
int a[555][555],n,m,r;
int sum[501][501][501];
int cc[501][501];
int mx[501][501][501];
int tot[501][501][501];
void solve() {
//	cout<<sizeof tot<<endl;
	while (~scanf ("%d%d%d",&n,&m,&r)) {
		memset (sum,0,sizeof sum);
		memset (tot,0,sizeof tot);
		int i,j,k,l;
		for (i=1; i<=n; i++) for (j=1; j<=m; j++) scanf ("%d",&a[i][j]);
		for (i=1; i<=n; i++) for (j=1; j<=m; j++) {
				sum[i][j][0]=a[i][j];
				int x=1;
				while (j+x<=m&&j-x>=1) {
					sum[i][j][x]=sum[i][j][x-1]+a[i][j-x]+a[i][j+x];
					x++;
				}
			}
		memset (cc,-1,sizeof cc);
		for (i=1+r; i+r<=n; i++) for (j=1+r; j+r<=m; j++) {
				cc[i][j]=0;
				for (k=i-r; k<=i+r; k++) {
					int x=sqrt (SQ (r)-SQ (k-i) +1e-8);
					cc[i][j]+=sum[k][j][x];
//				cout<<" "<<x<<"+"<<sum[k][j][x];
				}
//			cout<<"~"<<i<<" "<<j<<" with "<<cc[i][j]<<endl;
			}
		for (i=1; i<=n; i++) {
			for (j=1; j<=m; j++) mx[i][j][j]=cc[i][j],tot[i][j][j]=1;
			for (l=1; l<m; l++) for (j=1; j+l<=m; j++) {
//				mx[i][j][j+l]=(cc[i][j]==-1)?mx[i][j][j+l-1]:max(mx[i][j+1][j+l],cc[i][j]);
					if (cc[i][j]==-1) mx[i][j][j+l]=mx[i][j+1][j+l],tot[i][j][j+l]=tot[i][j+1][j+l];
					else {
						if (cc[i][j]>mx[i][j+1][j+l]) {
							mx[i][j][j+l]=cc[i][j];
							tot[i][j][j+l]=1;
						} else if (cc[i][j]==mx[i][j+1][j+l]) {
							mx[i][j][j+l]=cc[i][j];
							tot[i][j][j+l]=1+tot[i][j+1][j+l];
						} else {
							mx[i][j][j+l]=mx[i][j+1][j+l];
							tot[i][j][j+l]=tot[i][j+1][j+l];
						}
					}
				}
		}
		int res=0,has=0;
		for (i=1+r; i+r<=n; i++) for (j=1+r; j+r<=m; j++) {
				int now=cc[i][j];
				int add=-1;
				for (k=1+r; k<=n-r; k++) {
					if (abs (k-i) >2*r) {
						add=max (add,(int)mx[k][1][m]);
					} else {
						int x=sqrt (SQ (2*r)-SQ (k-i) +1e-8);
						if (j-x-1>=1) add=max (add,(int)mx[i][1][j-x-1]);
						if (j+x+1<=m) add=max (add,(int)mx[i][j+x+1][m]);
					}
				}
				if (add!=-1) {
					has=1;
					res=max (res,now+add);
				}
			}
		if (!has) {
			printf ("0 0\n");
			continue;
		}
		int ismx=0;
		for (i=1+r; i+r<=n; i++) for (j=1+r; j+r<=m; j++) {
				int now=cc[i][j];
				int add=-1;
				int here=0;
				for (k=1+r; k<=n-r; k++) {
					if (abs (k-i) >2*r) {
						add=max (add,(int)mx[k][1][m]);
						if (mx[k][1][m]+now==res) here+=tot[k][1][m];
					} else {
						int x=sqrt (SQ (2*r)-SQ (k-i) +1e-8);
						if (j-x-1>=1) add=max (add,(int)mx[i][1][j-x-1]);
						if (mx[i][1][j-x-1]+now==res) here+=tot[i][1][j-x-1];
						if (j+x+1<=m) add=max (add,(int)mx[i][j+x+1][m]);
						if (mx[i][1][j-x-1]+now==res) here+=tot[i][1][j-x-1];
					}
				}
				if (now+add==res) ismx+=here;
			}
		printf("%d %d\n",res,ismx/2);
	}
}
int main() {
//	while (1)
		solve();
	return 0;
}
