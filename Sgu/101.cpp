#include <vector>
#include <iostream>
#include <cstdio>
#include <stack>
#include <algorithm>
#include <cmath>
using namespace std;
#define _MP(a,b) make_pair(a,b)
#define _PB(a) push_back(a)
int x[110], y[110], n;
int all_done = 0;
vector<pair<int, int> >G[10];
stack<int>S;
int did[110];
void dfs (int u, int tot) {
//	cout<<"dfs:from "<<u<<" @"<<tot<<endl;
	if (tot > n) {
		all_done = 1;
		return;
		}
	int i;
	int cant[10];
	for(i=0;i<7;i++)cant[i]=0;
	for (i = 0; i < G[u].size(); i++) {
		int v = G[u][i].first;
		int id = G[u][i].second>0?G[u][i].second:-G[u][i].second;
		if (did[id]||cant[v]) continue;
		else if(all_done)return;
		else {
			did[id] = 1;
			S.push (G[u][i].second);
			dfs (v, tot + 1);
			if (!all_done) {
				S.pop();
				did[id] = 0;
				cant[v]=1;
				}
			else return;
			}
		}
	}
void solve() {
	int i;
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf ("%d%d", &x[i], &y[i]);
	int tot[10];
	for (i = 0; i < 7; i++)
		tot[i] = 0;
	for (i = 1; i <= n; i++)
		tot[x[i]]++, tot[y[i]]++;
	int and1 = 0;
	for (i = 0; i < 7; i++)
		if (tot[i] & 1)
			and1++;
	if (and1 > 2) {
		printf ("No solution\n");
		return;
		}
	int start = 0;
	for (i = 0; i < 7; i++)
		if (tot[i] > 0)
			start = i;
	for (i = 0; i < 7; i++)
		if (tot[i] & 1)
			start = i;
	for (i = 0; i < 7; i++)
		G[i].clear();
	for (i = 1; i <= n; i++)
		did[i] = 0;
	for (i = 1; i <= n; i++) {
		G[x[i]]._PB (_MP (y[i], i));
		G[y[i]]._PB (_MP (x[i], -i));
		}
	while (!S.empty()) S.pop();
	all_done = 0;
	dfs (start, 1);
	if (!all_done) {
		printf ("No solution\n");
		return;
		}
	while (!S.empty()) {
		int x = S.top();
		S.pop();
		printf ("%d %c\n", x>0?x:-x, x > 0 ? '-' : '+');
		}
	return;
	}
int main() {
	//while (1)
	solve();
	return 0;
	}
