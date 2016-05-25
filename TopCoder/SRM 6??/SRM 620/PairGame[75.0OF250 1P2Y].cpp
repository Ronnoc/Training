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
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <numeric>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size() 
#define SORT(p) sort(p.OP,p.ED)
#define SQ(x) ((x)*(x))
#define SSP system("pause")
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
typedef long long LL;
typedef pair<int, int> PII;
const double eps = 1e-8;
const double INF = 1e20;
const double PI = acos(-1);
const LL MOD = 1000000007;

class PairGame {
public:
  int maxSum (int a, int b, int c, int d) {
    int ret=-1;
    int i,j;
    int gl=__gcd(a,b);
    int gr=__gcd(c,d);
    if(gl!=gr)return -1;
    if(a==c&&b==d)return a+b;
    set<PII>CD;
    vector<PII>AB;
    while(1){
			CD.insert(MP(c,d));
			if(c>d)c-=d;
			else if(d>c)d-=c;
			else break;
    }
    while(1){
			AB.PB(MP(a,b));
			if(a>b)a-=b;
			else if(b>a)b-=a;
			else break;
    }
    reverse(AB.OP,AB.ED);
    for(i=0;i<AB.SZ;i++){
			if(CD.count(AB[i]))cmax(ret,AB[i].AA+AB[i].BB);
    }
    return ret;
  }
};



// Powered by FileEdit
// Powered by moj 4.12 [modified TZTester]
// Powered by CodeProcessor
