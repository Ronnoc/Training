//shllhs
#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int n,m,q,ans;
char mp[105][105];
int vis[105][105];
pair<int,int>s[10];
int dis[10][10];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
void bfs (int id) {
	queue<pair<pair<int,int>,int> >qu;
	memset (vis,0,sizeof (vis));
	dis[id][id] = 0;
	qu.push (make_pair (s[id],0));
	vis[s[id].first][s[id].second] = 1;
	while (!qu.empty()) {
		int x = qu.front().first.first;
		int y = qu.front().first.second;
		int d = qu.front().second;
		qu.pop();
		for (int i = 0; i<4; i++) {
			int nx = x+dx[i];
			int ny = y+dy[i];
			if (nx<0||nx>=n||ny<0||ny>=m) continue;
			if (mp[nx][ny] == '#') continue;
			if (!vis[nx][ny]) {
				vis[nx][ny] = 1;
				qu.push (make_pair (make_pair (nx,ny),d+1));
				for (int j = 0; j<=q; j++) {
					if (s[j].first == nx&&s[j].second == ny) {
						dis[id][j] = d+1;
					}
				}
			}
		}
	}
}
void dfs (int id,int mk,int c) {
	mk = mk| (1<<id);
	if (mk == (1<< (q+1))-1) ans = min (ans,c);
	for (int i = 0; i<=q; i++) {
		if (mk& (1<<i) ||dis[id][i] == 0x7f7f7f7f) continue;
		dfs (i,mk,c+dis[id][i]);
	}
}
int main() {
	int i,j;
	while (scanf ("%d%d",&n,&m) && (n+m)) {
		for (i = 0; i<n; i++) {
			scanf ("%s",mp[i]);
			for (j = 0; j<m; j++) {
				if (mp[i][j] == '@') {
					s[0] = make_pair (i,j);
				}
			}
		}
		scanf ("%d",&q);
		for (i = 1; i<=q; i++) {
			scanf ("%d%d",&s[i].first,&s[i].second);
			s[i].first--;
			s[i].second--;
		}
		memset (dis,0x7f,sizeof (dis));
		for (i = 0; i<=q; i++) bfs (i);
		ans = 0x7f7f7f7f;
		dfs (0,0,0);
		if (ans == 0x7f7f7f7f) printf ("-1\n");
		else printf ("%d\n",ans);
	}
	return 0;
}
