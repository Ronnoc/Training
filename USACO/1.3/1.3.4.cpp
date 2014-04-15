/*
ID: kybconn1
PROG: calfflac
LANG: C++
*/
#include<stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
bool isaz (char x) {
	if (x >= 'a' && x <= 'z') return 1;
	if (x >= 'A' && x <= 'Z') return 1;
	return 0;
}
char f (char x) {
	if (x >= 'a' && x <= 'z') return x;
	if (x >= 'A' && x <= 'Z') return x - 'A' + 'a';
}
int dp[44444];
string  sum, del, s;
char c, cc;
int where[44444];
int main() {
	freopen ("calfflac.in", "r", stdin);
	freopen ("calfflac.out", "w", stdout);
	int i = 0;
	while (scanf("%c",&c)!=EOF)sum+=c;
	
	for (i = 0; i < sum.size(); i++)
		if (isaz (sum[i])) {
			where[del.size()] = -1;
			del += "#";
			where[del.size()] = i;
			del += f (sum[i]);
		}
	for (i = 0; i < del.size(); i++) {
		int &d = dp[i];
		d = 0;
		while (i - d >= 0 && i + d < del.size() && del[i - d] == del[i + d]) d++;
	}
	int mx = 0;
	for (i = 0; i < del.size(); i++) if (dp[i] > mx) mx = dp[i];
	int pi = -1;
	for (i = del.size() - 1; i >= 0; i--) if (dp[i] == mx) pi = i;
	int l, r, d = 0;
	while (pi - d >= 0 && pi + d < del.size() && del[pi - d] == del[pi + d]) {
		if (where[pi - d] != -1) l = where[pi - d];
		if (where[pi + d] != -1) r = where[pi + d];
		d++;
	}
	int tot = 0;
	for (i = l; i <= r; i++) if (isaz (sum[i])) tot++;
	printf ("%d\n", tot);
	for (i = l; i <= r; i++) 
		printf ("%c", sum[i]);
	printf ("\n");
	return 0;
}
