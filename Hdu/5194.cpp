#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<string>
#include<cstring>
#include<cmath>
#include<map>
#include<set>
#include<vector>
#include<queue>
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

LL f[33][33][3];
LL C[33][33];
LL dfs(int n,int m,int x){
    LL &tp=f[n][m][x];
    if(~tp)return tp;
    tp=0;
    if(n)tp+=dfs(n-1,m,0);
    if(m)tp+=dfs(n,m-1,1)+(x==0?C[n+m-1][n]:0);
    return tp;
}
int main(){
    if(UsingFile)freopen(NAME".in","r",stdin);
    if(UsingFile)freopen(NAME".out","w",stdout);
    int i,j,k,_T;
    int n,m;
    for(i=0;i<=30;i++){
        C[i][0]=C[i][i]=1;
        for(j=1;j<i;j++)
            C[i][j]=C[i-1][j]+C[i-1][j-1];
    }
    while(~scanf("%d%d",&n,&m)){
        memset(f,-1,sizeof f);
        LL U=dfs(n,m,2);
        LL D=C[n+m][m];
        LL g=__gcd(U,D);
        U/=g;
        D/=g;
        cout<<U<<"/"<<D<<"\n";
    }
    return 0;
}

