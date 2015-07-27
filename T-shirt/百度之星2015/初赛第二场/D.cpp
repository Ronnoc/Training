#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
#define MP make_pair
#define PB push_back
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
#define NAME ""
#define UsingFile 0

LL ten[105];
int main(){
    if(UsingFile)freopen(NAME".in","r",stdin);
    if(UsingFile)freopen(NAME".out","w",stdout);
    int i,j,k,_T;
    ten[0]=1;
    for(i=1;i<=10;i++)ten[i]=ten[i-1]*10;
    scanf("%d",&_T);
    for(int CA=1;CA<=_T;CA++){
        printf("Case #%d:\n",CA);
        double c;
        scanf("%lf",&c);
        LL q=1000000;
        LL p=c*q+1e-5;
        LL g=__gcd(p,q);
        p/=g,q/=g;
        swap(p,q);
        vector<LL>L;
        int t,x,y;
        for(t=0;t<=8;t++)for(y=1;y<=9;y++)for(x=0;x<=9;x++){
            LL k=10*(p-q);
            LL b=ten[t+1]*(y*q-p*x)+x*q-y*p;
            if(k<0)k*=-1,b*=-1;
            if(b<0)continue;
            if(b%k)continue;
            LL a=b/k;
            if(a<ten[t])L.PB(y*ten[t+1]+10*a+x);
        }
        sort(L.OP,L.ED);
        printf("%d\n",L.SZ);
        if(L.SZ){
            for(i=0;i<L.SZ;i++){
                if(i)printf(" ");
                printf("%I64d",L[i]);
            }
            printf("\n");
        }
    }
    return 0;
}

