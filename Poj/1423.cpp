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
int bn[10000005];

int main() {
	double x = 0;
	for (int i = 1; i <= 10000000; i++) {
		x+=log10(i);
		bn[i] = x+1;
	}
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		cout << bn[n] << endl;
	}
	return 0;
}
