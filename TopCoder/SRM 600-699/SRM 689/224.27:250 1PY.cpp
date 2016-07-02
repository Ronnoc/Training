 
#include <bits/stdc++.h>
using namespace std;
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define MP make_pair
#define PB push_back
#define cmax(x,y) x=max((x),(y))
#define cmin(x,y) x=min((x),(y))
 
typedef long long LL;
typedef pair<int,int> PII;
 
class ColorfulGarden {
public:
  vector <string> rearrange( vector <string> G ) {
    int i,j,k;
    vector <string> ret;
    vector<PII>id;
    int n=G[0].SZ;
    for(i=0;i<n;i++)id.PB(MP(i&1,i));
    for(i=0;i<n;i++)id.PB(MP((i^1)&1,i));
    map<char,int>S;
    map<char,int>::iterator it;
    for(i=0;i<2;i++)
      for(j=0;j<G[i].SZ;j++)
        S[G[i][j]]++;
    vector <pair<int,char> >L;
    for(it=S.OP;it!=S.ED;++it){
      L.PB(MP(-(*it).BB,(*it).AA));
    }
    sort(L.OP,L.ED);
    for(i=0;i<L.SZ;i++)
      L[i].AA*=-1;
    if(L[0].AA>G[0].SZ)return ret;
    ret.PB(G[0]);
    ret.PB(G[1]);
    vector<char>Q;
    for(i=0;i<L.SZ;i++)
      for(j=0;j<L[i].AA;j++)
        Q.PB(L[i].BB);
    for(i=0;i<id.SZ;i++)
      ret[id[i].AA][id[i].BB]=Q[i];
    return ret;
  }
};
 