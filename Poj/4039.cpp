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
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long LL;
const LL MOD = 1000000007;
const double eps = 1e-6;

char str[1001000];
int n;
int a[10], g[10];
int b;
int len;
char w[300];
void out(int l, int r) {
	printf("calc ");
	for(int i = l; i < r; i++) printf("%c", str[i]);
	printf("\n");
}
int calc(int l, int r) {
//    out(l, r);
	if(r - l == 1) {
		return a[w[str[l]]];
	}
	int i, cnt = 0, j ;
	for(i = l, j = -1, cnt = 0; i < r; i++) {
		if(str[i] == '(') cnt++;
		else if(str[i] == ')') cnt--;
		else if(str[i] == '+' || str[i] == '-') {
			if(cnt == 0) {
				j = i;
			}
		}
	}
	if(j != -1) {
		int vl = calc(l, j);
		int vr = calc(j + 1, r);
		if(str[j] == '+') return vl + vr;
		else return vl - vr;
	}
	for(i = l, j = -1, cnt = 0; i < r; i++) {
		if(str[i] == '(') cnt++;
		else if(str[i] == ')') cnt--;
		else if(str[i] == '*') {
			if(cnt == 0) {
				j = i;
			}
		}
	}
	if(j != -1) {
		int vl = calc(l, j);
		int vr = calc(j + 1, r);
		return vl * vr;
	}

	return calc(l + 1, r - 1);
}
int main() {
	int i, j;
	while(scanf("%d", &n) != EOF) {
		for(i = 0; i < n; i++) scanf("%d", &a[i]);
		scanf("%d", &b);
		if(n == 0 && b == 0) break;
		gets(str);
		gets(str);
//        printf("%s\n", str);
		len = strlen(str);
		for(i = 0, j = 0; i < len; i++) {
			if(str[i] >= 'a' && str[i] <= 'z') {
				w[str[i]] = j++;
			}
		}
		for(i = 0; i < n; i++) g[i] = i;
		sort(a, a + n);
		bool flag = false;
		do {
			int result = calc(0, len);
			if(result == b) {
				flag = true;
				break;
			}
		} while(next_permutation(a, a + n));
		if(flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
