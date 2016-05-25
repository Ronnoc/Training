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

const double eps = 1e-8;
class TimeTravellingGardener {
public:
  int determineUsage (vector <int> d, vector <int> h) {
    int ret=h.SZ-1;
    double x[55];
    int i,j,k,n=h.SZ;
    x[0]=0;
    for(i=0;i<d.SZ;i++)x[i+1]=x[i]+d[i];
    for(i=0;i<h.SZ;i++)for(j=i+1;j<h.SZ;j++){
			int valid=1;
			int now=0;
			for(k=0;k<h.SZ;k++){
				if(k==i)continue;
				if(k==j)continue;
				//(h[k]-h[i])/(x[k]-x[i])==()
				double th=h[i]+1.0*(x[k]-x[i])*(h[j]-h[i])/(x[j]-x[i]);
				if(th>h[k]+eps){valid=0;break;}
				else if(th<-eps){valid=0;break;}
				else if(th<h[k]-eps)now++;
			}
			if(valid)ret=min(ret,now);
    }
    return ret;
  }
};



// Powered by FileEdit
// Powered by moj 4.12 [modified TZTester]
// Powered by CodeProcessor
