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

int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,T;
	int a0,a1,a2;
	while(cin>>a0>>a1>>a2){
		int b1=a1-a0;
		int b2=a2-a1;
		int c2=b2-b1;
		int c3=c2;
		int b3=c3+b2;
		int c4=c3;
		int b4=b3+c4;
		int c5=c4;
		int b5=b4+c5;
		int a3=a2+b3;
		int a4=a3+b4;
		int a5=a4+b5;
		cout<<a3<<" "<<a4<<" "<<a5<<endl;
	}
	return 0;
}
