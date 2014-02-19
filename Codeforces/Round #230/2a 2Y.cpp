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
#define SZ size()
#define SORT(x) sort(x.OP,x.ED)
#define SQ(x) ((x)*(x))
#define SSP system("pause")
typedef long long LL;
typedef pair<int, int> PII;

int main() {
	int i,j;
	string s;
	cin>>s;
	int t=0,n=0,e=0;
	j=0;
	for ( i=0; i<s.SZ; i++ )if ( s[i]=='t' )t++;//	+
	for ( i=0; i<s.SZ; i++ )if ( s[i]=='n' )n++;//	++
	for ( i=0; i<s.SZ; i++ )if ( s[i]=='e' )e++;//	+++
	for ( i=0; i<s.SZ; i++ )if ( s[i]=='i' )j++;//	+
	int tot=0;
	if(n>=3&&t&&j&&e>=3)tot++,n-=3,t--,j--,e-=3;
	while ( tot ) {
		if(n>=2&&t&&j&&e>=3)tot++,n-=2,t--,j--,e-=3;
		else break;
	}
	cout<<tot<<endl;
	return 0;
}
