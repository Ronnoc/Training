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
#define NAME ""
#define UsingFile 0

vector<int>solve(vector<int>A,int &flag){
    vector<int>ret;
    if(A.SZ<=1){
        flag=1;
        return A;
    }
    int mid=A.SZ/2;
    int le,re;
    vector<int>P,Q;
    int i;
    for(i=0;i<A.SZ;i++)if(i<mid)P.PB(A[i]);else Q.PB(A[i]);
    vector<int>L=solve(P,le);
    vector<int>R=solve(Q,re);
    if(!le||!re){
        flag=0;
        return ret;
    }
    int ir=R.SZ-1,il=L.SZ-1;
    int earn=0;
    while(il>=0&&ir>=0){
        int need=ir+1;
        if(L[il]-need>=R[ir]+earn+1){
            earn++;
            ret.PB(L[il--]-need);
        }else ret.PB(R[ir--]+earn);
    }
    while(il>=0)ret.PB(L[il--]);
    while(ir>=0)ret.PB(R[ir--]+earn);
    reverse(ret.OP,ret.ED);
    flag=1;
    for(i=1;i<ret.SZ;i++)if(ret[i]<ret[i-1])flag=0;
    return ret;
}
int main(){
    if(UsingFile)freopen(NAME".in","r",stdin);
    if(UsingFile)freopen(NAME".out","w",stdout);
    int i,j,k,_T;
    int n;
    while(~scanf("%d",&n)){
        vector<int>L,V;
        for(i=0;i<n;i++){
            int w;
            scanf("%d",&w);
            L.PB(w);
        }
        int flag;
        V=solve(L,flag);
        if(flag){
            for(i=0;i<V.SZ;i++){
                if(i)printf(" ");
                printf("%d",V[i]);
            }
            printf("\n");
        }else puts(":(");
    }
    return 0;
}

