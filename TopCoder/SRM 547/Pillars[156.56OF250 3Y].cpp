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


class Pillars {
public:
  double getExpectedLength (int w, int x, int y) {
    double ret=0;
    int i;
    ret+=w*min(x,y);
    for(i=1;i<=max(x,y);i++){
			int ld,rd;
			ld=max(1,i+1);
			rd=min(x,y+i);
			if(rd>=ld)ret+=sqrt(w*w+1.0*i*i)*(rd-ld+1);
			ld=max(1,i+1);
			rd=min(y,x+i);
			if(rd>=ld)ret+=sqrt(w*w+1.0*i*i)*(rd-ld+1);
    }
    ret/=1LL*x*y;
    return ret;
  }
};



// Powered by FileEdit
// Powered by moj 4.12 [modified TZTester]
// Powered by CodeProcessor
