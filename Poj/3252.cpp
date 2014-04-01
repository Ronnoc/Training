#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int C[40][40];
int CC (int x, int y) {
	if (y + y > x) return CC (x, x - y);
	if (y == 0) return 1;
	if (C[x][y] != -1) return C[x][y];
	return C[x][y] = CC (x - 1, y) + CC (x - 1, y - 1);
	}
int find (int x) {
	int bin[40], tb = 1;
	int y = x;
	while (y) {
		bin[tb++] = y % 2;
		y /= 2;
		}
	tb--;
	int tot, i, j;
//	for (i = tb; i >= 1; i--) cout << bin[i];
//	cout << endl;
	int res = 0;
	for (i = 1; i < tb; i++) {
		for (j = 0; j <= i - 1; j++) {
			int num0 = j;
			int num1 = i - j;
			if (num0 >= num1) res += CC (i - 1, j);
			}
		}
//	cout << res << endl;
	tot = 1;
	for (i = tb - 1; i >= 1; i--) {
		if (bin[i]) tot++;
		else continue;
		for (j = 0; j <= i - 1; j++) {
			int num1 = j + tot - 1;
			int num0 = tb - num1;
			if (num0 >= num1) {
				res += CC (i - 1, j);
//				cout << "+C" << i << "," << j << endl;
				}
			}
		}
//	if(tot==1&&tb>1)res++;
//	cout<<res<<endl;
	return res;
	}
int main() {
	memset (C, -1, sizeof (C));
	int i, j;
	for (i = 1; i <= 32; i++) for (j = 0; j <= i; j++) {
			CC (i, j);
//			if(CC(i,j)<0)cout<<"!";
			}
//	cout<<CC(12,3)<<endl;
	int n, m;
	while (scanf ("%d%d", &n, &m) != EOF)
		cout << find (m + 1) - find (n) << endl;
	return 0;
	}
