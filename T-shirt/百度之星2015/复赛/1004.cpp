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

int H[200005];
int q[200005];
int N,R;
void update(pair<LL,PII>&ans,int i,int j){
    LL len=H[i]+H[j];
    len+=1LL*(i-j)*R;
    if(i>=N)i-=N;
    if(j>=N)j-=N;
    if(i>j)swap(i,j);
    if(ans.AA==-1LL||len>ans.AA){
        ans.AA=len;
        ans.BB.AA=i;
        ans.BB.BB=j;
    }else if(ans.AA==len){
        cmin(ans.BB,MP(i,j));
    }
}
int main() {
	//freopen(NAME".in","r",stdin);
	//freopen(NAME".out","w",stdout);
    int i,j,k,_T;
    scanf("%d",&_T);
    for(int CA=1;CA<=_T;CA++){
        printf("Case #%d:\n",CA);
        scanf("%d%d",&N,&R);
        for(i=0;i<N;i++)scanf("%d",&H[i]);
        for(i=N;i<2*N;i++)H[i]=H[i-N];
        int op=0,ed=0;
        int half=N/2;
        pair<LL,PII>ans=MP(0,MP(1,1));
        q[ed++]=0;
        for(i=1;i<2*N;i++){
            while(op<ed&&i-q[op]>half)op++;
            if(op<ed)
                update(ans,i,q[op]);
            while(op<ed&&H[i]-1LL*i*R>H[q[ed-1]]-1LL*q[ed-1]*R)ed--;
            q[ed++]=i;
        }
        printf("%d %d\n",ans.BB.AA+1,ans.BB.BB+1);
    }
	return 0;
}
