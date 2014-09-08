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
#include <cassert>
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
const double PI=acos(-1.);
const LL MOD = 1000000007;

int n, match = 0;
int matchx[8], matchy[8];
int vis[8];
int G[8][8];
bool dfs(int u) {
	int v;
	for(int j = 0; j<8; j++)if(G[u][j]) {
			v = j;
			if(vis[v]) continue;
			vis[v] = true;
			if(-1 == matchy[v] || dfs(matchy[v])) {
				matchy[v] = u;
				matchx[u] = v;
				return true;
			}
		}
	return false;
}
int t[8][3];
int main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j,k,l,T;
	for(i=0; i<8; i++)cin>>t[i][0]>>t[i][1]>>t[i][2];
	for(i=0; i<8; i++)for(j=0; j<3; j++)t[i][j]*=2;
	for(i=0; i<8; i++)sort(t[i],t[i]+3);
	int a,b,c;
	do {
		for(a=1; a<8; a++)for(b=a+1; b<8; b++)for(c=b+1; c<8; c++) {
					sort(t[a],t[a]+3);
					sort(t[b],t[b]+3);
					sort(t[c],t[c]+3);
					do {
						do {
							do {
								LL d[3][3];
								for(i=0; i<3; i++)d[0][i]=t[a][i]-t[0][i];
								for(i=0; i<3; i++)d[1][i]=t[b][i]-t[0][i];
								for(i=0; i<3; i++)d[2][i]=t[c][i]-t[0][i];
								int fail=0;
								for(i=0; i<3; i++)
									for(j=i+1; j<3; j++) {
										LL tp=0;
										for(k=0; k<3; k++)tp+=1LL*d[i][k]*d[j][k];
										if(tp)fail=1;
									}
								set<LL>len;
								for(i=0; i<3; i++) {
									LL dis=0;
									for(j=0; j<3; j++)dis+=SQ(1LL*d[i][j]);
									len.insert(dis);
								}
								if(len.SZ==1&&len.count(0)==0&&!fail) {
									int aim[8][3];
									for(i=0; i<8; i++) {
										for(j=0; j<3; j++)aim[i][j]=t[0][j];
										for(j=0; j<3; j++)if(i>>j&1)for(k=0; k<3; k++)aim[i][k]+=d[j][k];
									}
									memset(G,0,sizeof G);
									for(k=0; k<8; k++) {
										int q[3];
										for(l=0; l<3; l++)q[l]=t[k][l];
										sort(q,q+3);
										do {
											for(l=0; l<8; l++)
												if(MP(MP(q[0],q[1]),q[2])==MP(MP(aim[l][0],aim[l][1]),aim[l][2]))
													G[k][l]=1;
										}
										while(next_permutation(q,q+3));
									}
									memset(matchx,-1,sizeof matchx);
									memset(matchy,-1,sizeof matchy);
									int tt=0;
									for(k=0; k<8; k++)if(matchx[k]==-1) {
											memset(vis,0,sizeof vis);
											if(dfs(k))tt++;
										}
									if(tt==8) {
										puts("YES");
										for(k=0; k<8; k++,cout<<endl)
											for(l=0; l<3; l++)cout<<aim[matchx[k]][l]/2<<" ";
										cout<<endl;
										return 0;
									}
								}
							}
							while(next_permutation(t[c],t[c]+3));
						}
						while(next_permutation(t[b],t[b]+3));
					}
					while(next_permutation(t[a],t[a]+3));
				}
	}
	while(next_permutation(t[0],t[0]+3));
	puts("NO");
	return 0;
}
/*
-96608 -96608 100000
100000 100000 -96608
100000 -96608 -96608
-96608 -96608 -96608
-96608 100000 100000
100000 100000 100000
100000 100000 -96608
-96608 -96608 100000

YES
*/
