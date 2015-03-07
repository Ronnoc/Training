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
#define VER 1
const int MXN = 1005;
LL f[105][105];
LL p[105],q[105];
LL solve(int id,LL n,int m){
    if(id==0)return f[id][m];
    if(n>(1LL<<(id-1))){
        return f[id-1][m]+solve(id-1,n-(1LL<<(id-1)),m-1);
    }else {
        return solve(id-1,n,m);
    }
}
int main(){
    if(!VER)freopen(NAME".in","r",stdin);
    if(!VER)freopen(NAME".out","w",stdout);
    int i,j,k,_T;
    memset(f,0,sizeof f);
    for(i=0;i<60;i++){
        p[i]=(1LL<<i)-1;
        q[i]=p[i]+(1LL<<i)-1;
    }
    f[0][0]=1;
    for(i=0;i<60;i++)
        for(j=0;j<=i;j++)
            f[i+1][j]+=f[i][j],f[i+1][j+1]+=f[i][j];
    LL n,t;
    while(cin>>n>>t){
        int ppt=0,m=-1;
        while(t>0){
            if(t&1)ppt++;
            t>>=1;
            m++;
        }
        if(ppt!=1){
            printf("0\n");
            continue;
        }
        LL ans=0;
        for(i=0;i<60;i++){
            if(n>q[i])ans+=f[i][m];
            else break;
        }
        n=n-p[i]+1;
        ans+=solve(i,n,m);
        if(m==0)ans--;
        cout<<ans<<"\n";
    }
    return 0;
}

