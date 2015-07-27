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

char s[100005];
int len;
int next[100005][27];
int dp[100005];
LL f[100005];
PII A[55],B[55];
bool inner(int a,PII x){
    return a>=x.AA&&a<=x.BB;
}
bool cross(pair<int,PII>x,pair<int,PII>y){
    return inner(x.AA,y.BB)&&inner(y.AA,x.BB);
}
int main() {
	//freopen(NAME".in","r",stdin);
	//freopen(NAME".out","w",stdout);
    int i,j,k,_T;
    scanf("%d",&_T);
    for(int CA=1;CA<=_T;CA++){
        printf("Case #%d:\n",CA);
        int n;
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d%d%d%d",&A[i].AA,&A[i].BB,&B[i].AA,&B[i].BB);
        }
        vector<pair<int,PII> >X,Y;
        for(i=0;i<n;i++){
            if(A[i].AA==B[i].AA){
                int x=A[i].AA;
                int p=A[i].BB,q=B[i].BB;
                if(p>q)swap(p,q);
                X.PB(MP(x,MP(p,q)));
            }
            if(A[i].BB==B[i].BB){
                int y=A[i].BB;
                int p=A[i].AA,q=B[i].AA;
                if(p>q)swap(p,q);
                Y.PB(MP(y,MP(p,q)));
            }
        }
        int ans=0;
        for(i=0;i<X.SZ;i++)
            for(j=i+1;j<X.SZ;j++){
                for(int p=0;p<Y.SZ;p++)if(cross(X[i],Y[p])&&cross(X[j],Y[p])){
                        for(int q=p+1;q<Y.SZ;q++)if(cross(X[i],Y[q])&&cross(X[j],Y[q])){
                            ans++;
                        }
                    }
            }
        printf("%d\n",ans);
    }
	return 0;
}
