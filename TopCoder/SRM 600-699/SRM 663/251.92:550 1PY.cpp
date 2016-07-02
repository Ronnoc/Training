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

vector<int>G[55][55][2]; 
int fa[5555]; 
int getfa(int u){return fa[u]==u?u:fa[u]=getfa(fa[u]);} 
class ABBADiv1 { 
public: 
  string canObtain (string pe, string qe) { 
    string ret; 
    string yes="Possible"; 
    string no="Impossible"; 
    int i,j; 
    int n=qe.SZ; 
    vector<string>L; 
    for(i=0;i<n;i++) 
        for(j=1;i+j<=n;j++){ 
            string s=qe.substr(i,j); 
            L.PB(s); 
            reverse(s.OP,s.ED); 
            L.PB(s); 
        } 
    sort(L.OP,L.ED); 
    L.erase(unique(L.OP,L.ED),L.ED); 
    for(i=0;i<L.SZ;i++)fa[i]=i; 
    for(i=0;i<L.SZ;i++){ 
        string s=L[i]; 
        string c=s+"A"; 
        int is,ic; 
        is=i,ic=lower_bound(L.OP,L.ED,c)-L.OP; 
        if(L[ic]==c){ 
            int fs=getfa(is); 
            int fc=getfa(ic); 
            fa[fs]=fc; 
        } 
        c=s+"B"; 
        reverse(c.OP,c.ED); 
        is=i,ic=lower_bound(L.OP,L.ED,c)-L.OP; 
        if(L[ic]==c){ 
            int fs=getfa(is); 
            int fc=getfa(ic); 
            fa[fs]=fc; 
        } 
    } 
    int ip=lower_bound(L.OP,L.ED,pe)-L.OP; 
    int iq=lower_bound(L.OP,L.ED,qe)-L.OP; 
    if(L[ip]==pe&&L[iq]==qe&&getfa(ip)==getfa(iq))ret=yes; 
    else ret=no; 
    cerr<<ret<<"\n"; 
    return ret; 
  } 
}; 