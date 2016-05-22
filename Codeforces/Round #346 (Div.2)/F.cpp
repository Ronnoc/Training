#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
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
LL a[1111][1111];
int v[1111][1111];
int dx[] = { -1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
pair<int, PII> Z[1111111];
int tid[1111][1111];
int vis[1111111];
void solve(int n, int m, LL s) {
	memset(vis, 0, sizeof vis);
	memset(v, -1, sizeof v);
	int i, j, k;
	int nz = 0;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++) {
			cin >> a[i][j];
			Z[nz++] = MP(a[i][j], MP(i, j));
		}
	sort(Z, Z + nz);
	for (i = 0; i < nz; i++)
		tid[Z[i].BB.AA][Z[i].BB.BB] = i;
	int nextid = 0;
	for (i = 0; i < nz; i++) {
		if (i && Z[i].AA == Z[i - 1].AA)continue;
		if (s % Z[i].AA)continue;
		int nbig = nz - i;
		if (nbig < s / Z[i].AA)continue;
		for (j = i; j < nz; j++) {
			if (Z[j].AA != Z[i].AA)break;
			if (vis[tid[Z[j].BB.AA][Z[j].BB.BB]])continue;
			int cnt = 0;
			queue<PII>Q;
			Q.push(Z[j].BB);
			while (!Q.empty()) {
				PII tp = Q.front();
				Q.pop();
				int x = tp.AA, y = tp.BB;
				if (v[x][y] == nextid)continue;
				v[x][y] = nextid;
				cnt++;
				if (a[x][y] == Z[i].AA)
					vis[tid[x][y]] = 1;
				for (k = 0; k < 4; k++) {
					int xx = x + dx[k];
					int yy = y + dy[k];
					if (xx < 1 || xx > n)continue;
					if (yy < 1 || yy > m)continue;
					if (a[xx][yy] < Z[i].AA)continue;
					Q.push(MP(xx, yy));
				}
			}
			//cout<<Z[j].BB.AA<<" "<<Z[j].BB.BB<<" "<<Z[j].AA<<" "<<cnt<<"\n";
			nextid++;
			if (cnt >= s / Z[i].AA) {
				printf("YES\n");
				Q.push(Z[j].BB);
				cnt=0;
				while (!Q.empty()&&cnt<s/Z[i].AA) {
					PII tp = Q.front();
					Q.pop();
					int x = tp.AA, y = tp.BB;
					if (v[x][y] == nextid)continue;
					v[x][y] = nextid;
					cnt++;
					for (k = 0; k < 4; k++) {
						int xx = x + dx[k];
						int yy = y + dy[k];
						if (xx < 1 || xx > n)continue;
						if (yy < 1 || yy > m)continue;
						if (a[xx][yy] < Z[i].AA)continue;
						Q.push(MP(xx, yy));
					}
				}
				int out=Z[i].AA;
				for(int i=1;i<=n;i++){
					for(int j=1;j<=m;j++){
						printf("%d ",v[i][j]==nextid?out:0);
					}
					printf("\n");
				}
				return;
			}
		}
	}
	printf("NO\n");
}
int main() {
	int i, j, k, _T;
	int n, m;
	LL s;
	while (cin >> n >> m >> s)
		solve(n, m, s);
	return 0;
}