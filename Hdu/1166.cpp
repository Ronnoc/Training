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
int BIT[50550];
int MXN=50110;
int LB(int x){return x&(-x);}
int bitadd(int w,int x){
	for(w+=5;w<=MXN;w+=LB(w))BIT[w]+=x;
}
int bitsum(int w){
	int ret=0;
	for(w+=5;w>0;w-=LB(w))ret+=BIT[w];
	return ret;
}
int main(){
	int i,j,n;
	int T;
	scanf("%d",&T);
	int CASE=0;
	while(T--){
		printf("Case %d:\n",++CASE);
		scanf("%d",&n);
		memset(BIT,0,sizeof BIT);
		for(i=1;i<=n;i++){
			int x;
			scanf("%d",&x);
			bitadd(i,x);
		}
		char s[11];
		while(~scanf("%s",s)){
			if(strcmp(s,"End")==0)break;
			if(strcmp(s,"Query")==0){
				int l,r;
				scanf("%d%d",&l,&r);
				printf("%d\n",bitsum(r)-bitsum(l-1));
			}else {
				int w,x;
				scanf("%d%d",&w,&x);
				if(strcmp(s,"Add")!=0)x*=-1;
				bitadd(w,x);
			}
		}
	}
	return 0;
}
