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

class AddMultiply {
public:
  vector <int> makeExpression (int y) {
    vector <int> ret;
    int i,j;
    for(i=-1000;i<=1000;i++)for(j=-1000;j<=1000;j++){
			int z=y-i*j;
			if(z<=1000&&z>=-1000&&!i&&!j&&!z){
				if(i==1||j==1||z==1)continue;
				ret.PB(i);
				ret.PB(j);
				ret.PB(z);
				printf("!");
				return ret;
			}
    }
    return ret;
  }
};



// Powered by FileEdit
// Powered by moj 4.12 [modified TZTester]
// Powered by CodeProcessor


// Powered by FileEdit
// Powered by moj 4.12 [modified TZTester]
// Powered by CodeProcessor


// Powered by FileEdit
// Powered by moj 4.12 [modified TZTester]
// Powered by CodeProcessor
