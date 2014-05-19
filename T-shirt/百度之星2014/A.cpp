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
#include <iomanip>
#include <sstream>
#include <iostream>
#include <algorithm>

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
const double eps=1e-8;
const double INF=1e20;
const double PI=acos( -1. );
const int MXN = 50;
const LL MOD = 1000000007;
int main(){
	int i,j;
	int T;
	scanf("%d",&T);
	for(int CASE=1;CASE<=T;++CASE){
		LL n,m,v,k;
		cin>>n>>m>>v>>k;
		int flag=1,cnt=0;
		while(1){
			if(m>=n)break;
			if(m<v){flag=0;break;}
			if((m-v)*k<=m){flag=0;break;}
			m=(m-v)*k;
			cnt++;
		}
		if(flag)printf("%d\n",cnt);
		else printf("-1\n");
	}
	return 0;
}
