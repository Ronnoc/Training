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

char s[1005][1005];
bool ok[1005];
int main(){
    int i,j,k,_T;
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        for(i=0;i<n;i++)
            scanf("%s",s[i]);
        memset(ok,0,sizeof ok);
        int ans=0;
        for(j=0;j<m;j++){
            bool flag=0;
            for(i=1;i<n;i++)if(!ok[i])
                if(s[i][j]<s[i-1][j])flag=1;
            if(flag)
                ans++;
            else 
                for(i=1;i<n;i++)if(!ok[i])
                    if(s[i][j]>s[i-1][j])ok[i]=1;
        }
        printf("%d\n",ans);
    }
    return 0;
}

