#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;
vector<int>L;
vector<int>::iterator iter;
int main() {
	int n, i, x;
	cin >> n;
	for (i = 1; i <= n; i++) {
		cin >> x;
		iter = lower_bound (L.begin(), L.end() , x);
		if(iter!=L.end())*iter = x;
		else L.push_back(x);
	}
	cout << L.size() << endl;
	return 0;
}
