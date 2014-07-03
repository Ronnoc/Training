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
bool dp[17][17][35][17][35];
class Rumor {
public:
  int getMinimum (string w, vector <string> g) {
    int ret=MOD;
    int i,j,k;
    int n=w.SZ;
    for(i=0;i<1<<n;i++){
			int t=0;
			int a=0,b=0,did=0;
			for(j=0;j<n;j++)if(w[j]=='Y')a|=1<<j,b|=1<<j;
			while(1){
				if(a==b&&b==(1<<n)-1)break;
				int A=0,B=0;
				for(j=0;j<n;j++)
					if(i>>j&1){
						if((did>>j&1)&&(b>>j&1))B|=1<<j;
						if((~did>>j&1)&&(a>>j&1))A|=1<<j,did|=1<<j;
					}else {
						if((did>>j&1)&&(a>>j&1))A|=1<<j;
						if((~did>>j&1)&&(b>>j&1))B|=1<<j,did|=1<<j;
					}
				t++;
				int la=a,lb=b;
				for(j=0;j<n;j++)if(A>>j&1)for(k=0;k<n;k++)if(g[j][k]=='Y')
					a|=1<<k;
				for(j=0;j<n;j++)if(B>>j&1)for(k=0;k<n;k++)if(g[j][k]=='Y')
					b|=1<<k;
//				cout<<i<<": "<<la<<"~"<<lb<<" _"<<A<<"~"<<B<<" =>"<<a<<"~"<<b<<endl;
				if(a==la&&b==lb)break;
			}
			if(a==b&&b==(1<<n)-1)
				cmin(ret,t);
    }
    return ret==MOD?-1:ret;
  }
};



// Powered by FileEdit
// Powered by moj 4.12 [modified TZTester]
// Powered by CodeProcessor

