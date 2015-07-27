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
#define NAME ""
typedef long long LL;
typedef pair<int, int> PII;
const double eps=1e-8;
const double PI=acos(-1.);
const LL MOD = 1000000007;

char e[505][7];
int len[505];
int vis[55];
int inq[55];
char D[55][3005];
vector<pair<int,int> >G[55];
char tmp[3005];
int main() {
	//freopen(NAME".in","r",stdin);
	//freopen(NAME".out","w",stdout);
    int i,j,k,_T;
    scanf("%d",&_T);
    for(int CA=1;CA<=_T;CA++){
        printf("Case #%d:\n",CA);
        int N,M,A,B;
        scanf("%d%d%d%d",&N,&M,&A,&B);
        for(i=0;i<N;i++)G[i].clear();
        for(i=0;i<M;i++){
            int u,v;
            scanf("%d%d%s",&u,&v,e[i]);
            len[i]=strlen(e[i]);
            G[v].PB(MP(u,i));
        }
        queue<int>Q;
        memset(vis,0,sizeof vis);
        memset(D,0,sizeof D);
        vis[B]=1;
        inq[B]=1;
        Q.push(B);
        while(!Q.empty()){
            int u=Q.front();
            Q.pop();
            inq[u]=0;
            for(i=0;i<G[u].SZ;i++){
                int v=G[u][i].AA;
                int ie=G[u][i].BB;
                strcpy(tmp,e[ie]);
                strcpy(tmp+len[ie],D[u]);
                if(!vis[v]||strcmp(tmp,D[v])<0){
                    vis[v]=1;
                    strcpy(D[v],tmp);
                    if(!inq[v]&&strlen(D[v])<700){
                        Q.push(v);
                        inq[v]=1;
                    }
                }
            }
        }
        if(!vis[A]||strlen(D[A])>400)cout<<"Tough way!\n";
        else cout<<D[A]<<"\n";
    }
	return 0;
}
/*
2
4 4 0 3
1 2 a
2 1 a
0 1 a
1 3 b

3 3 0 2
0 1 a
0 1 ab
1 2 c

*/

