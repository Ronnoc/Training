#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int l, n;
	while ( cin >> l >> n ) {
		if ( l == -1 && n == -1 ) break;
		vector<pair<int, int> >L;
		int i, j, x;
		for ( i = 1; i <= n; i++ ) {
			cin >> x;
			L.push_back ( make_pair ( x + l, x - l ) );
		}
		sort ( L.begin(), L.end() );
		int last = L[0].second - 1, ans = 0;
		for ( i = 0; i < L.size(); i++ ) {
			if ( L[i].second > last ) {
				for ( j = i; j < L.size(); j++ )
					if ( L[j].first - l > L[i].first ) break;
				last = L[--j].first-l;
				ans++;
//				cout << last << " >> ";
			}
		}
//		cout << endl;
		cout << ans << endl;
	}
	return 0;
}
