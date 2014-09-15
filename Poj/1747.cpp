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
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
typedef long long LL;
typedef pair<int, int> PII;
const double eps=1e-8;
const double PI=acos( -1. );
const LL MOD = 1000000007;
string solve(int n){
	if(n==1)return string("((A0|B0)|(A0|B0))");
	char s[5];
	sprintf(s,"%d",n-1);
	string S=s;
	string A="A"+S,B="B"+S;
	string xy="("+A+"|"+B+")";
	string ret=xy;
	if(n>1){
		string _x="("+A+"|"+A+")";
		string _y="("+B+"|"+B+")";
		string __="(("+_x+"|"+_y+")|("+_x+"|"+_y+"))";
		ret="("+xy+"|("+solve(n-1)+"|"+"("+_x+"|"+_y+")"+"))";
	}
//	cout<<ret<<endl;
	return ret;
}
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,T;
	int n;
//	for(n=1;n<=100;n++)
//		cout<<(int)solve(n).SZ-50*n<<endl;
	while(cin>>n)cout<<solve(n)<<endl;
	return 0;
}
