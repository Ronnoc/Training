#include<bits/stdc++.h>
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

vector<int>L;
int main(){
    int i,j,k,_T;
    int n,l;
    while(~scanf("%d%d",&n,&l)){
        double le=0,re=l;
        L.clear();
        for(i=0;i<n;i++){
            scanf("%d",&j);
            L.PB(j);
        }
        sort(L.OP,L.ED);
        L.erase(unique(L.OP,L.ED),L.ED);
        double Min=*min_element(L.OP,L.ED);
        double Max=*max_element(L.OP,L.ED);
        double ans=Min;
        cmax(ans,l-Max);
        for(i=1;i<L.SZ;i++)
            cmax(ans,(L[i]-L[i-1])*.5);
        printf("%.16f\n",ans);
    }
    return 0;
}

