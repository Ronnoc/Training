#include <iostream>
#include <algorithm>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
#endif
	long long i;
	for (i = 0; i <= 999999999LL; i++) {
		long long x = i * 10 + 1;
		if (x * x % 1000000000LL == 987654321LL) cout << x << endl;
		x += 8;
		if (x * x % 1000000000LL == 987654321LL) cout << x << endl;
		if(x*x<0)cout<<"!";
		}
	return 0;
	}
