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

int p[105],q[105];
char s[105][105];
int main(){
    if(UsingFile)freopen(NAME".in","r",stdin);
    if(UsingFile)freopen(NAME".out","w",stdout);
    int i,j,k,_T;
    int n;
    while(~scanf("%d",&n)){
        for(i=0;i<n;i++){
            p[i]=q[i]=0;
            scanf("%s",s[i]);
        }
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                if(s[i][j]!='E')
                    p[i]++,q[j]++;
        int fp=1,fq=1;
        for(i=0;i<n;i++)if(p[i]==0)fp=0;
        for(i=0;i<n;i++)if(q[i]==0)fq=0;
        if(fp){
            for(i=0;i<n;i++)
                for(j=0;j<n;j++)if(s[i][j]!='E'){
                    printf("%d %d\n",i+1,j+1);
                    break;
                }
        }else if(fq){
            for(i=0;i<n;i++)
                for(j=0;j<n;j++)if(s[j][i]!='E'){
                    printf("%d %d\n",j+1,i+1);
                    break;
                }
        }else puts("-1");
    }
    return 0;
}

