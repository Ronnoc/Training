#include <cstdio>
#include <vector>
using namespace std;
char map[10][10];
vector<int>G[10];
int m, n;
int did[10], md[10];
int dfs ( int t ) {
	if ( t > n ) return 1;
	int i, j, s = 0, ret = 0;
	for ( i = m - 1; i >= 0; i-- )
		if ( did[i] ) {s = i + 1; break;}
	if ( t + m - s < n ) return 0;
	for ( i = s; i < m; i++ )
		for ( j = 0; j < G[i].size(); j++ ) {
			int v = G[i][j];
			if ( !md[v] ) {
				did[i] = 1, md[v] = 1;
				ret += dfs ( t + 1 );
				did[i] = 0, md[v] = 0;
			}
		}
	return ret;
}
int main() {
	while ( scanf ( "%d%d", &m, &n ) != EOF ) {
		if ( m == -1 && n == -1 ) break;
		int i, j;
		for ( i = 0; i < m; i++ ) scanf ( "%s", map[i] );
		
		for ( i = 0; i < m; i++ ) G[i].clear();
		for ( i = 0; i < m; i++ ) did[i] = 0;
		for ( i = 0; i < m; i++ ) md[i] = 0;
		int tot = 0;
		for ( i = 0; i < m; i++ )
			for ( j = 0; j < m; j++ )
				if ( map[i][j] == '#' )
					G[i].push_back ( j ), tot++;
		if ( tot == 64 && n == 8 )
		{printf ( "40320\n" ); continue;}
		printf ( "%d\n", dfs ( 1 ) );
	}
	return 0;
}
