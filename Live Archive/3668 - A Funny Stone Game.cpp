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
#define OP begin()
#define ED end()

typedef long long LL;
typedef pair<int, int> PII;


int sg[99];
int a[33], n;
int b[33];
int getSG (int *a) {
	int i;
	for (i = 1; i <= n; i++) b[i] = a[i] % 2;
	int SG = 0;
	for (i = 1; i <= n; i++) if (b[i]) SG = SG xor sg[n - i];
	return SG;
}
int main() {
	int i, j, k;
	sg[0] = 0;
	for (i = 1; i <= 23; i++) {
		vector<int>S;
		for (j = 0; j < i; j++) for (k = j; k < i; k++) S.PB (sg[j] xor sg[k]);
		sort (S.OP, S.ED);
		S.erase (unique (S.OP, S.ED), S.ED);
		S.PB (S.size() + 2);
		for (j = 0; j < S.size(); j++) if (S[j] != j) {
				sg[i] = j;
				break;
			}
	}
//	for(i=0;i<=23;i++)cout<<sg[i]<<" ";cout<<endl;
	int CASE = 0;
	while (~scanf ("%d", &n)) {
		if (!n) break;
		for (i = 1; i <= n; i++) scanf ("%d", &a[i]);
		int SG = getSG (a);
		if (!SG)
			printf ("Game %d: -1 -1 -1\n", ++CASE);
		else {
			int flag = 0;
			int Pi, Pj, Pk;
			for (i = 1; !flag && i <= n; i++) 
				if (a[i])
					for (j = n - i - 1; !flag && j >= 0; j--) 
						for (k = j; !flag && k >= 0; k--) {
							a[i]--, a[n - j]++, a[n - k]++;
							int SSGG = getSG (a);
							if (!SSGG) flag = 1, Pi = i, Pj = n - j, Pk = n - k;
							a[i]++, a[n - j]--, a[n - k]--;
						}
			if (!flag) printf ("Game %d: -1 -1 -1\n", ++CASE);
			else printf ("Game %d: %d %d %d\n", ++CASE, Pi - 1, Pj - 1, Pk - 1);
		}
	}
	return 0;
}
