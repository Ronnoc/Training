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
int a[222];
char s[222];
int main(){
	int i,j;
	int n,m;
	while(~scanf("%d",&n)&&n){
		for(i=1;i<=n;i++)scanf("%d",&a[i]);
		for(i=1;i<=n;i++)a[i-1]=a[i]-1;
		int b[222],c[222];
//		for(i=0;i<n;i++)b[a[i]]=i;
//		for(i=0;i<n;i++)a[i]=b[i];
		while(~scanf("%d",&m)&&m){
			scanf("%*c");
			for(i=0;i<n;i++)s[i]=' ';
			gets(s);s[strlen(s)]=' ';
			s[n]='\0';
			for(i=0;i<n;i++)b[i]=a[i];
			while(m){
				if(m&1){
					char q[222];
					for(i=0;i<n;i++)q[b[i]]=s[i];
					for(i=0;i<n;i++)s[i]=q[i];
				}
				for(i=0;i<n;i++)c[i]=b[b[i]];
				for(i=0;i<n;i++)b[i]=c[i];
				m/=2;
			}
			printf("%s\n",s);
		}
		printf("\n");
	}
	return 0;
}
/*
10
2 3 4 5 6 7 8 9 10 1

1 qwertyuiop
2 qwertyuiop
3 qwertyuiop
4 qwertyuiop
5 qwertyuiop
6 qwertyuiop
7 qwertyuiop
8 qwertyuiop
9 qwertyuiop
0

0
*/
