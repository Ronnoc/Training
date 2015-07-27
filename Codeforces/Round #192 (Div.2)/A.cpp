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

char s[15][15];
int r[15],c[15];
int main(){
    if(UsingFile)freopen(NAME".in","r",stdin);
    if(UsingFile)freopen(NAME".out","w",stdout);
    int i,j,k,_T;
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        for(i=0;i<n;i++)
            scanf("%s",s[i]);
        memset(r,0,sizeof r);
        memset(c,0,sizeof c);
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)if(s[i][j]=='S')
                r[i]=1,c[j]=1;
        int R=0,C=0;
        for(i=0;i<n;i++)R+=r[i];
        for(i=0;i<m;i++)C+=c[i];
        cout<<n*m-R*C<<"\n";
    }
    return 0;
}

