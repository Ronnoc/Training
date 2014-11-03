#include <bits/stdc++.h>
using namespace std;
#define MP make_pair
#define PB push_back
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define SQ(x) ((x)*(x))
typedef long long LL;
typedef pair<int,int> PII;
LL x[3005],y[3005];
int m;
LL a[3005],b[3005],c[3005];
int o[3005];
map<LL,vector<int> >ID;
map<pair<LL,LL>,vector<pair<LL,int> > >Q;
map<pair<LL,LL>,vector<pair<LL,int> > >::iterator it;
int main() {
  #define NAME "astronomy"
  freopen(NAME".in","r",stdin);
  freopen(NAME".out","w",stdout);
  int i,j,n;
  while(~scanf("%d",&n)&&n) {
    for(i=0; i<n; i++)scanf("%I64d%I64d",&x[i],&y[i]);
    scanf("%d",&m);
    for(i=0; i<m; i++)scanf("%I64d%I64d%I64d",&a[i],&b[i],&c[i]),o[i]=0;
    ID.clear(),Q.clear();
    for(i=0; i<n; i++)
      ID[x[i]*x[i]+y[i]*y[i]].PB(i);
    for(i=0; i<m; i++)
      Q[MP(a[i],b[i])].PB(MP(c[i],i));
    for(it=Q.OP; it!=Q.ED; ++it) {
      vector<pair<LL,int> >&L=(*it).BB;
      vector<int>&A=ID[(*it).AA.AA];
      vector<int>&B=ID[(*it).AA.BB];
      set<LL>has;
      for(i=0;i<L.SZ;i++)has.insert(L[i].AA);
      map<LL,int>MA;
      map<LL,int>::iterator qt;
      LL aa=(*it).AA.AA,bb=(*it).AA.BB;
      for(i=0; i<A.SZ; i++)
        for(j=0; j<B.SZ; j++) {
          int ia=A[i],ib=B[j];
          if(aa==bb&&ia<ib)continue;
          if(ia==ib)continue;
          LL d=SQ(x[ia]-x[ib])+SQ(y[ia]-y[ib]);
          if(has.find(d)==has.ED)continue;
          MA[d]++;
        }
      for(i=0;i<L.SZ;i++)
        o[L[i].BB]=MA[L[i].AA];
    }
    for(i=0;i<m;i++)printf("%d\n",o[i]);
  }
  return 0;
}
/*
6
0 2 1 1 2 0
5 0 -3 4 -4 3
4
25 25 2
4 2 2
4 25 9
25 25 100
*/

