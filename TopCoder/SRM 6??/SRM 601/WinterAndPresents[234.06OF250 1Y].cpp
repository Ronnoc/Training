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


class WinterAndPresents {
public:
  long long getNumber (vector <int> p, vector <int> q) {
    long long ret=0;
    int mn=2222222;
    int i,w;
    for(i=0;i<p.SZ;i++)mn=min(mn,p[i]+q[i]);
    for(w=1;w<=mn;w++){
			int j;
			LL l=0,r=0;
			for(j=0;j<p.SZ;j++){
				int duo=min(p[j],w);
				int shao=max(0,w-q[j]);
				l+=shao;
				r+=duo;
			}
			ret+=r-l+1;
    }
    return ret;
  }
};



// Powered by FileEdit
// Powered by moj 4.12 [modified TZTester]
// Powered by CodeProcessor
