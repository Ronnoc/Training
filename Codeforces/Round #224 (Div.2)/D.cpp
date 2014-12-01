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
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <numeric>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <functional>

using namespace std;

const double eps = 1e-8;
const int MOD = 1000000007;
#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define SORT(X) sort(X.OP,X.ED)
#define SQ(x) ((x)*(x))
typedef long long LL;
typedef pair<int, int> PII;
char s[2002][2002];
int dp[2002][2002];
int n,m;
PII play (PII z) {
  int x=z.AA;
  int y=z.BB;
  if (s[x][y]=='<') y--;
  else if (s[x][y]=='>') y++;
  else if (s[x][y]=='^') x--;
  else if (s[x][y]=='v') x++;
  return MP(x,y);
}
void solve() {
  int i,j,k;
  while (scanf ("%d%d",&n,&m) !=EOF) {
    for (i=0; i<n; i++) scanf ("%s",s[i]);
    memset (dp,-1,sizeof dp);
    int flag=0;
    for (j=0; j<m; j++) for (i=0; i<n; i++) {
        if (s[i][j]=='#') dp[i][j]=0;
        else {
          set<PII>S;
          vector<PII>L;
          int x=i,y=j;
          int dual=0;
          while (1) {
            if (S.find (MP (x,y)) ==S.ED) S.insert (MP (x,y));
            else {dual=1; break;}
            if (dp[x][y]!=-1) {dp[i][j]=dp[x][y]+L.SZ; break;}
            L.PB (MP (x,y));
            if (s[x][y]=='#') break;
            else if (s[x][y]=='<') y--;
            else if (s[x][y]=='>') y++;
            else if (s[x][y]=='^') x--;
            else if (s[x][y]=='v') x++;
          }
          if (dual) flag=1;
          if (dp[i][j]==-1) for (k=0; k<L.SZ; k++) dp[L[k].AA][L[k].BB]=L.SZ-1-k;
        }
      }
//		cout<<"flag"<<" "<<flag<<endl;
    if (flag) {cout<<-1<<endl; continue;}
    int mx=0;
//		cout<<flag<<endl;
    for (i=0; i<n; i++) {
      for (j=0; j<m; j++) mx=max (mx,dp[i][j]); //cout<<dp[i][j]<<" ";
//			cout<<endl;
    }
    if (mx==0) {cout<<0<<endl; continue;}
    set<PII>L[2];
    for (i=0; i<n; i++) {
      for (j=0; j<m; j++) if (mx==dp[i][j]) L[0].insert (MP (i,j)); //cout<<dp[i][j]<<" ";
//			cout<<endl;
    }
//		cout<<"cntmx="<<L[0].SZ<<endl;
    if (L[0].SZ==1) {cout<<2*mx-1<<endl; continue;}
    for (i=0; i<mx-1; i++) {
      int x=i%2;
      int y= (i+1) %2;
      L[y].clear();
      set<PII>::iterator it;
      for (it=L[x].OP; it!=L[x].ED; ++it) {
        L[y].insert (play (*it));
      }
    }
    if(L[(mx-1)%2].SZ>1)cout<<mx*2<<endl;
    else cout<<mx*2-1<<endl;
  }
}
int main() {
//	while(1)
  solve();
  return 0;
}
