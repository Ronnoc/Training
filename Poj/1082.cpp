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
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <numeric>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <functional>

using namespace std;

#define PB push_back
#define MP make_pair
#define AA first
#define BB second

typedef long long LL;
typedef pair<int, int> PII;

int sg[111][22][33];
int day[111][22];
int getSG (int p, int q, int r) {
//	printf("%d %d %d:: ",p+1900,q,r);
	int &tp = sg[p][q][r];
	if (tp != -1) {/*printf("return %d\n",tp);*/return tp;}
	int flag = 0;
	int pp = p, qq = q, rr = r + 1;
	if (rr > day[pp][qq]) rr = 1, qq++;
	if (qq > 12) qq = 1, pp++;
	int ppp = p, qqq = q + 1, rrr = r;
	if (qq > 12) qqq = 1, ppp++;
//	printf("(%d,%d,%d) (%d,%d,%d)\n",pp,qq,rr,ppp,qqq,rrr);
//	system("pause");
	int i = pp, j = qq, k = rr;
	if (i < 101 || (i == 101 && j < 11) || (i == 101 && j == 11 && k <= 4))
		if (!getSG (pp, qq, rr)) return tp = 1;
	i = ppp, j = qqq, k = rrr;
	if (rrr <= day[ppp][qqq])
		if (i < 101 || (i == 101 && j < 11) || (i == 101 && j == 11 && k <= 4))
			if (!getSG (ppp, qqq, rrr)) return tp = 1;
	return tp = 0;
}
int main() {
	int i, j, k;
	for (i = 0; i <= 102; i++)
		for (j = 1; j <= 12; j++) day[i][j] = 31;
	for (i = 0; i <= 102; i++)
		day[i][4] = day[i][6] = day[i][9] = day[i][11] = 30;
	for (i = 0; i <= 102; i++)
		if (i && i % 4 == 0) day[i][2] = 29;
		else day[i][2] = 28;
	memset (sg, -1, sizeof sg);
	for(i=4;i<=day[101][11];i++)sg[101][11][i]=0;
	for(i=1;i<=day[101][12];i++)sg[101][12][i]=0;
	for (i = 101; i >= 0; i--)
		for (j = 1; j <= 12; j++)
			for (k = 1; k <= day[i][j]; k++)
				if (i < 101 || (i == 101 && j < 11) || (i == 101 && j == 11 && k <= 4))
					getSG (i, j, k);
	int T;
	cin >> T;
	while (T--) {
		cin >> i >> j >> k;
		if (getSG (i - 1900, j, k)) printf ("YES\n");
		else printf ("NO\n");
	}
	return 0;
}
