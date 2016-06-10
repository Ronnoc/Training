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

int G[55][55];
int T[55][55];
int sum[55][55][55];
class Painting {
public:
  int largestBrush (vector <string> p) {
    int ret=min(p.SZ,p[0].SZ);
    int n=p.SZ,m=p[0].SZ,i,j,ii,jj,l,r;
    memset(T,0,sizeof T);
    for(i=0;i<n;i++)for(j=0;j<m;j++)
			T[i][j]=p[i][j]=='B'?1:0;
//		for(i=0;i<n;i++){
//			for(j=0;j<m;j++)cout<<T[i][j];
//			cout<<endl;
//		}
		for(i=0;i<n;i++){
			for(j=0;j<m;j++)sum[i][j][j]=T[i][j];
			for(l=0;l<m;l++)for(r=l+1;r<m;r++)sum[i][l][r]=sum[i][l][r-1]+T[i][r];
		}
    for(;ret>1;ret--){
    	memset(G,0,sizeof G);
    	int bug=0;
			for(i=0;!bug&&i+ret-1<n;i++)for(j=0;!bug&&j+ret-1<m;j++){
				int allb=1;
				for(ii=0;allb&&ii<ret;ii++)if(sum[i+ii][j][j+ret-1]!=ret)allb=0;
//				if(T[i][j]&&!G[i][j]&&i==0&&!allb)bug=1;
//				if(T[i][j]&&!G[i][j]&&j==0&&!allb)bug=1;
				if(!allb)continue;
				for(ii=0;ii<ret;ii++)for(jj=0;jj<ret;jj++)
					G[i+ii][j+jj]=1;
			}
			for(i=0;i<n;i++)for(j=0;j<m;j++)if(T[i][j]!=G[i][j])bug=1;
			if(!bug)return ret;
    }
    return ret;
  }
};



// Powered by FileEdit
// Powered by moj 4.12 [modified TZTester]
// Powered by CodeProcessor
