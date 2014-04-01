#include <queue>
#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
int main() {
	int OFFL = 0;
#ifndef ONLINE_JUDGE
	OFFL = 1;
#endif
	int n, l, p;
	scanf ("%d", &n);
	int i, x, y;
	vector<pair<int, int> >L;
	priority_queue<int>Q;
	
	for (i = 1; i <= n; i++) {
		scanf ("%d%d", &x, &y);
		L.push_back (make_pair (x, y));
	}
	scanf ("%d%d", &l, &p);
	
	for (i = 0; i < L.size(); i++) L[i].first = l - L[i].first;
	L.push_back (make_pair (l, 0));
	sort (L.begin(), L.end());
	
	int ans = 0;
	for (i = 0; i < L.size(); i++) {
//		printf (">>%d %d\n", L[i].first, L[i].second);
		if(L[i].first<0)continue;
		if(p>=L[i].first)Q.push(L[i].second);
		else {
			while(p<L[i].first&&!Q.empty()){
				int u=Q.top();Q.pop();
				p+=u;ans++;
			}
			if(p<L[i].first&&Q.empty())
				{ans=-1;break;}
			Q.push(L[i].second);
		}
//		cout<<Q.size()<<"~\n";
	}
	printf ("%d\n", ans);
	return 0;
}
