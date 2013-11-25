//kybconnor
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
#define UNIQUE(x) x.erase(unique(x.OP,x.ED),x.ED)
typedef long long LL;
typedef pair<int, int> PII;
int f[6][24]= {
	{ 0, 1,11, 5, 4,16,12, 6, 2, 9,10,17,13, 7, 3,15,14, 8,18,19,20,21,22,23},
	{ 0, 1, 8,14, 4, 3, 7,13,17, 9,10, 2, 6,12,16,15, 5,11,18,19,20,21,22,23},
	
	{ 0, 7, 2,13, 4, 5, 6,17,14, 8,10,11,12,19,15, 9,16,21,18,23,20, 1,22, 3},
	{ 0,21, 2,23, 4, 5, 6, 1, 9,15,10,11,12, 3, 8,14,16, 7,18,13,20,17,22,19},
	
	{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,21,20,10,11,12,13,18,16,19,17,15,14,22,23},
	{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,12,13,14,15,21,20,17,19,16,18,11,10,22,23},
};
int inv[6]= {1,0,3,2,5,4};
int ch[11];
int save[24];
int ans;
int same[6][4]= {
	{ 0, 1, 2, 3},
	{ 4, 5,10,11},
	{ 6, 7,12,13},
	{ 8, 9,14,15},
	{16,17,18,19},
	{20,21,22,23},
};
int temp[24];
int check (int *a) {
	int ret=0;
	int i,j;
	for (i=0; i<6; i++) {
		int flag=1;
		for (j=1; j<4; j++) if (a[same[i][0]]!=a[same[i][j]]) flag=0;
		ret+=flag;
	}
	return ret;
}
void play (int *a,int *f) {
	int i;
	for (i=0; i<24; i++) temp[i]=a[i];
	for (i=0; i<24; i++) a[f[i]]=temp[i];
//	for(i=0;i<24;i++)cout<<temp[i]<<" ";cout<<endl;
//	for(i=0;i<24;i++)cout<<f[i]<<" ";cout<<endl;
//	for(i=0;i<24;i++)cout<<a[i]<<" ";cout<<endl;
//	cout<<endl;
}
void dfs (int h,int H) {
	ans=max (ans,check (save));
	if (h>H) return;
	int i;
	for (i=0; i<6; i++) {
		if (h>=2) if (i==inv[ch[h-1]]) continue;
		ch[h]=i;
		play (save,f[i]);
		dfs (h+1,H);
		play (save,f[inv[i]]);
	}
}
void solve() {
	int n;
	while (~scanf ("%d",&n)) {
		int i;
		for (i=0; i<24; i++) scanf ("%d",&save[i]);
		ans=check (save);
		dfs (1,n);
		printf ("%d\n",ans);
	}
}
int main() {
//	int i,ocur[24],j;
//	for(i=0;i<6;i++){
//		memset(ocur,0,sizeof ocur);
//		for(j=0;j<24;j++)ocur[f[i][j]]++;
//		for(j=0;j<24;j++)if(ocur[j]>1)cout<<i<<j<<endl;
//	}
//	while(1)
	solve();
	return 0;
}
