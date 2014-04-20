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


class MinimumSquare {
public:
  long long minArea (vector <int> x, vector <int> y, int K) {
    long long ret=2100000000;
    vector<PII>L;
    int i,j,k;
    for(i=0;i<x.SZ;i++)L.PB(MP(x[i],y[i]));
    SORT(L);
    for(i=0;i<L.SZ;i++)for(j=i+K-1;j<L.SZ;++j){
			vector<int>Z;
			for(k=i;k<=j;k++)Z.PB(L[k].BB);
			SORT(Z);
			int l=L[i].AA-1;
			int r=L[j].AA+1;
			int dx=r-l;
			int dy=2100000000;
			for(k=0;k+K-1<Z.SZ;k++){
				int yl=Z[k]-1;
				int yr=Z[k+K-1]+1;
				if(yr-yl<dy)dy=yr-yl;
			}
			ret=min((int)ret,max(dx,dy));
    }
    return ret*ret;
  }
};



// Powered by FileEdit
// Powered by moj 4.12 [modified TZTester]
// Powered by CodeProcessor
