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
bool check( string s ) {
	istringstream sin( s );
	int x;
	sin>>x;
	char c[5];
	sprintf( c,"%d",x );
	return x>=1&&x<=26&&strlen( c )==s.size();
}
unsigned long long dp[511111];
string s;
int main() {
	while ( cin>>s ) {
		if ( s=="0" )break;
		dp[0]=1;
		for ( int i=1; i<=s.size(); i++ ) {
			dp[i]=0;
			if ( check( s.substr( i-1,1 ) ) )dp[i]+=dp[i-1];
			if ( i>=2&&check( s.substr( i-2,2 ) ) )dp[i]+=dp[i-2];
		}
		cout<<dp[s.size()]<<endl;
	}
	return 0;
}
