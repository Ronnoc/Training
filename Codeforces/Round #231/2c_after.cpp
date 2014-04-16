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

#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define SORT(x) sort(x.OP,x.ED)
#define SQ(x) ((x)*(x))
#define SSP system("pause")
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
typedef long long LL;
typedef pair<int, int> PII;
int x[1111][1111];
int main(){
	int i,j;
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		int a=0,b=0,c=0,d=0;
		for(i=0;i<n*m;i++){
			int z;
			scanf("%2d",&z);
			if(z==0)a++;
			else if(z==1)b++;
			else if(z==10)c++;
			else d++;
		}
		b+=c;
		c=b;
		memset(x,-1,sizeof x);
		for(i=1;i<=n;i++)for(j=1;j<=m;j++){
			int &tp=x[i][j];
			if(tp!=-1)continue;
			if(d){tp=11;d--;}
			else if(b){
				tp=1;b--;c--;
				if(i<n&&c){
					x[i+1][j]=10;
					c--;b--;
				}
			}else if(c){
				tp=10;c--;b--;
				if(i<n&&b){
					x[i+1][j]=1;
					b--;c--;
				}
			}else tp=0,a--;
		}
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++)printf("%02d ",x[i][j]);
			printf("\n");
		}
	}
	return 0;
}
