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
#define SORT(p) sort(p.OP,p.ED)
typedef long long LL;
typedef pair<int, int> PII;


class TaroFriends {
public:
  int getNumber (vector <int> w, int X) {
    int ret;
    SORT(w);
    ret=w[w.SZ-1]-w[0];
    int i,j;
    #define cmin(x,y) x=min(x,y)
    for(i=0;i<w.SZ;i++){
			vector<int>z;
			for(j=0;j<=i;j++)z.PB(w[j]+X);
			for(j=i+1;j<w.SZ;j++)z.PB(w[j]-X);
			SORT(z);
			cmin(ret,z[w.SZ-1]-z[0]);
    }
    return ret;
  }
};



// Powered by FileEdit
// Powered by moj 4.12 [modified TZTester]
// Powered by CodeProcessor
