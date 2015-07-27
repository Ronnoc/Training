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

char s[105][105];
LL f[105][105];
int main(){
    if(UsingFile)freopen(NAME".in","r",stdin);
    if(UsingFile)freopen(NAME".out","w",stdout);
    int i,j,k,_T;
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        for(i=0;i<n;i++)scanf("%s",s[i]);
        for(i=0;i<n;i++)for(j=0;j<m;j++)f[i][j]=s[i][j]=='B'?1:-1;
        int ans=0;
        int p,q;
        for(i=n-1;i>=0;i--)for(j=m-1;j>=0;j--)if(f[i][j]){
            ans++;
            int w=f[i][j];
            for(p=0;p<=i;p++)for(q=0;q<=j;q++)f[p][q]-=w;
        }
        cout<<ans<<"\n";
    }
    return 0;
}

