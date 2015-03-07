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

set<PII>F;
int r[105],c[105];
int w[105][105];
int n,m;
int pr[105],pc[105];
int main(){
    if(!VER)freopen(NAME".in","r",stdin);
    if(!VER)freopen(NAME".out","w",stdout);
    int i,j,k,_T;
    while(~scanf("%d%d",&n,&m)){
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)scanf("%d",&w[i][j]);
        for(i=1;i<=n;i++){
            pr[i]=r[i]=0;
            for(j=1;j<=m;j++)r[i]+=w[i][j];
        }
        for(j=1;j<=m;j++){
            pc[j]=c[j]=0;
            for(i=1;i<=n;i++)c[j]+=w[i][j];
        }
        F.clear();
        for(i=1;i<=n;i++)F.insert(MP(r[i],i));
        for(j=1;j<=m;j++)F.insert(MP(c[j],-j));
        while(!F.empty()){
            PII tp=*F.OP;
            F.erase(F.OP);
            if(tp.AA>=0)break;
            if(tp.BB>0){
                i=tp.BB;
                for(j=1;j<=m;j++)F.erase(F.find(MP(c[j],-j)));
                pr[i]^=1;
                for(j=1;j<=m;j++){
                    c[j]-=w[i][j];
                    w[i][j]*=-1;
                    c[j]+=w[i][j];
                }
                r[i]*=-1;
                F.insert(MP(r[i],i));
                for(j=1;j<=m;j++)
                    F.insert(MP(c[j],-j));
            }else {
                j=-tp.BB;
                for(i=1;i<=n;i++)F.erase(F.find(MP(r[i],i)));
                pc[j]^=1;
                for(i=1;i<=n;i++){
                    r[i]-=w[i][j];
                    w[i][j]*=-1;
                    r[i]+=w[i][j];
                }
                c[j]*=-1;
                F.insert(MP(c[j],-j));
                for(i=1;i<=n;i++)
                    F.insert(MP(r[i],i));
            }
        }
        int C=0,R=0;
        for(i=1;i<=n;i++)if(pr[i])R++;
        for(j=1;j<=m;j++)if(pc[j])C++;
        printf("%d",R);for(i=1;i<=n;i++)if(pr[i])printf(" %d",i);printf("\n");
        printf("%d",C);for(j=1;j<=m;j++)if(pc[j])printf(" %d",j);printf("\n");
    }
    return 0;
}

