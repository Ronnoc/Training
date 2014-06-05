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
int a[5][5];
int to[16]={1,2,3,4,8,7,6,5,9,10,11,12,0,15,14,13};
int main(){
	int tmd=0;
	int i,j;
	for(i=0;i<16;i++)for(j=i+1;j<16;j++)if(to[i]>to[j])tmd++;
//	cout<<tmd<<endl;
	for(i=0;i<4;i++)for(j=0;j<4;j++)
		scanf("%d",&a[i][j]);
	int cnt=0,inv=0;
	for(i=0;i<4;i++)for(j=0;j<4;j++)if(a[i][j]==0)cnt=i+j;
	vector<int>L;
	for(i=0;i<4;i++)L.PB(a[0][i]);
	for(i=3;i>=0;i--)L.PB(a[1][i]);
	for(i=0;i<4;i++)L.PB(a[2][i]);
	for(i=3;i>=0;i--)L.PB(a[3][i]);
	for(i=0;i<L.SZ;i++)for(j=i+1;j<L.SZ;j++)if(L[i]>L[j])cnt++;
	if(cnt&1)printf("YES\n");
	else printf("NO\n");
	return 0;
}
/*
1  2  3  4 
5  6  7  8 
9 10 11 12 
13 14 0 15
*/
