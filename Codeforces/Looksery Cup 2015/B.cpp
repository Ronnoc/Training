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

int main(){
    if(UsingFile)freopen(NAME".in","r",stdin);
    if(UsingFile)freopen(NAME".out","w",stdout);
    int i,j,k,_T;
    int n;
    while(~scanf("%d",&n)){
        int cnt[105];
        char s[105][105];
        memset(cnt,0,sizeof cnt);
        for(i=0;i<n;i++)scanf("%s",s[i]);
        int a[105];
        for(i=0;i<n;i++)scanf("%d",&a[i]);
        vector<int>L;
        while(1){
            int neq=-1;
            for(i=0;i<n;i++)if(a[i]==cnt[i]){
                neq=i;break;
            }
            if(neq==-1)break;
            int u=neq;
            L.PB(u);
            for(j=0;j<n;j++)if(s[u][j]=='1')cnt[j]++;
        }
        printf("%d\n",L.SZ);
        sort(L.OP,L.ED);
        for(i=0;i<L.SZ;i++){
            if(i)printf(" ");
            printf("%d",L[i]+1);
        }
        printf("\n");
    }
    return 0;
}

