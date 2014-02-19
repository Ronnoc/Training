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

int fa[1111];
int getfa(int x){return fa[x]==x?x:fa[x]=getfa(fa[x]);}
class TimeTravellingSalesman {
public:
  long long determineCost (int N, vector <string> r) {
    string s;
    int i;
    for(i=0;i<r.SZ;i++)s+=r[i];
    for(i=0;i<s.SZ;i++)if(s[i]==',')s[i]=' ';
    istringstream sin(s);
    vector<pair<int,PII> >L;
    int u,v,w;
    while(sin>>u>>v>>w)
			L.PB(MP(w,MP(u,v)));
    for(i=0;i<N;i++)fa[i]=i;
    SORT(L);
    LL ret=0;
    for(i=0;i<L.SZ;i++){
			int fu=getfa(L[i].BB.AA);
			int fv=getfa(L[i].BB.BB);
			if(fu!=fv)fa[fu]=fv,ret+=L[i].AA;
    }
    int root=getfa(0);
    for(i=0;i<N;i++)if(getfa(i)!=root)return -1;
    return ret;
  }
};



// Powered by FileEdit
// Powered by moj 4.12 [modified TZTester]
// Powered by CodeProcessor
