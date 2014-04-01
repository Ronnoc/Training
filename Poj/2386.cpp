#include <cstdio>
#include <queue>
using namespace std;
int dx[] = {0, 0, 0, 1, 1, 1, -1, -1, -1};
int dy[] = {0, 1, -1, 0, 1, -1, 0, 1, -1};
queue<pair<int, int> >Q;
char map[111][111];
int clr[111][111];
int main() {
	int OFFL = 0;
#ifndef ONLINE_JUDGE
	OFFL = 1;
#endif
	int n, m;
	while ( scanf ( "%d%d", &n, &m ) != EOF ) {
		int i, j;
		for ( i = 0; i < n; i++ )
			scanf ( "%s", map[i] );
		for ( i = 0; i < n; i++ )
			for ( j = 0; j < m; j++ )
				clr[i][j] = 0;
		int time = 0;
		for ( i = 0; i < n; i++ ) for ( j = 0; j < m; j++ ) {
				if ( clr[i][j] ) continue;
				if ( map[i][j] == '.' ) continue;
				++time;
				Q.push ( make_pair ( i, j ) );
				while ( !Q.empty() ) {
					int k;
					int x = Q.front().first;
					int y = Q.front().second;
					Q.pop();
					if(clr[x][y])continue;
					clr[x][y] = time;
					for ( k = 1; k <= 8; k++ ) {
						int xx = x + dx[k];
						int yy = y + dy[k];
						if ( xx < 0 || xx >= n ) continue;
						if ( yy < 0 || yy >= m ) continue;
						if ( map[xx][yy] == '.' ) continue;
						if ( clr[xx][yy] ) continue;
						Q.push ( make_pair ( xx, yy ) );
					}
				}
			}
		printf ( "%d\n", time );
	}
	return 0;
}
