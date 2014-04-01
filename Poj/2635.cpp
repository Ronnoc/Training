#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
#define PSIZE 800000
#define MAXP 1100000
#define _LL long long
_LL ss[1000];
char s[610];
_LL plist[PSIZE], pcount = 0;
int prime (_LL n) {
	int i;
	if ( (n != 2 && ! (n % 2)) || (n != 3 && ! (n % 3)) || (n != 5 && ! (n % 5)) || (n != 7 && ! (n % 7)))
		return 0;
	for (i = 0; plist[i]*plist[i] <= n; ++i)
		if (! (n % plist[i]))
			return 0;
	return n > 1;
	}
void initprime() {
	int i;
	for (plist[pcount++] = 2, i = 3; i < MAXP; ++i)
		if (prime (i))
			plist[pcount++] = i;
	}
int main() {
	initprime();
//	cout<<plist[pcount-1]<<endl;;
//	cout<<pcount;
	int L;
	while (scanf ("%s%d", s, &L) != EOF) {
		if (strlen (s) == 1 && s[0] == '0' && !L)
			break;
		_LL ppro = 1000000000000LL;
		int flag = 1, i, j, ns = 0;
		for (i = strlen (s) - 1; i >= 0; i -= 12) {
//				cout<<i<<endl;
			ss[ns] = 0LL;
			for (j = max (0, i - 11); j <= i; j++) {
				ss[ns] *= 10;
				ss[ns] += s[j] - '0';
				}
			ns++;
			}
//		for(i=ns-1;i>=0;i--)printf("%lld ",ss[i]);cout<<endl;
		for (i = 0; plist[i] < L; i++) {
			_LL pro = 1LL;
			_LL hash = 0LL;
			for (j = 0; j<ns; j++) {
				hash += ss[j]%plist[i] * pro;
				pro *= ppro;
				pro %= plist[i];
				}
			hash %= plist[i];
			if (!hash) {
				printf("BAD %lld\n",plist[i]);
				flag = 0;
				break;
				}
			}
		if (flag) printf("GOOD\n");
		}
	return 0;
	}
/*
9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999536689 999984
ans::
BAD 999983
*/
