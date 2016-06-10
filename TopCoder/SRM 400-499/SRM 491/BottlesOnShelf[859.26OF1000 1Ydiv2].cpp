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

LL gd[1<<19];
int gl[1<<19];
int gr[1<<19];
class BottlesOnShelf {
public:
  int getNumBroken (int N, vector <int> l, vector <int> r, vector <int> d) {
    int ret=0,m=l.SZ,i;
    for(i=0;i<m;i++)gd[1<<i]=d[i];
    for(i=0;i<m;i++)gl[1<<i]=l[i];
    for(i=0;i<m;i++)gr[1<<i]=r[i];
    for(i=1;i<1<<m;i++){
			int cnt=__builtin_popcount(i);
			if(cnt!=1){
				int sub=i&(-i);
				gl[i]=max(gl[sub],gl[i-sub]);
				gr[i]=min(gr[sub],gr[i-sub]);
				gd[i]=1LL*gd[sub]*gd[i-sub]/__gcd(gd[sub],gd[i-sub]);
				if(gd[i]>N)gd[i]=N+1;
			}
			if(gr[i]>=gl[i]){
				int dlt=gr[i]/gd[i]-(gl[i]-1)/gd[i];
				if(cnt&1)ret+=dlt;
				else ret-=dlt;
			}
    }
    return ret;
  }
};



// Powered by FileEdit
// Powered by moj 4.12 [modified TZTester]
// Powered by CodeProcessor
