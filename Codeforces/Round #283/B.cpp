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

int w[100005];
int s[3][100005];
int next[3][100005][21];
int main(){
    int i,j,k,_T,x;
    int n;
    while(~scanf("%d",&n)){
        memset(s,0,sizeof s);
        for(x=1;x<=2;x++)
            for(i=0;i<=n;i++)
                for(j=0;j<20;j++)
                    next[x][i][j]=n;
        for(i=0;i<n;i++)scanf("%d",&w[i]);
        for(i=0;i<n;i++)
            s[1][i+1]=s[1][i]+(w[i]==1);
        for(i=0;i<n;i++)
            s[2][i+1]=s[2][i]+(w[i]==2);
        for(i=n-1;i>=0;i--){
            if(w[i]==1)next[1][i][0]=i+1,next[2][i][0]=next[2][i+1][0];
            else next[2][i][0]=i+1,next[1][i][0]=next[1][i+1][0];
        }
        for(j=1;j<20;j++){
            for(i=0;i<n;i++){
                next[1][i][j]=next[1][next[1][i][j-1]][j-1];
                next[2][i][j]=next[2][next[2][i][j-1]][j-1];
            }
        }
        int t;
        vector<PII>Ans;
        for(t=1;t<=n;t++){
            vector<int>L;
            for(j=0;j<20;j++)if(t>>j&1)L.PB(j);
            int cc[3];
            cc[1]=cc[2]=0;
            int id=0;
            bool fail=0;
            int last=-1;
            while(id<n){
                int le=id,re=id;
                for(k=0;k<L.SZ;k++){
                    j=L[k];
                    le=next[1][le][j];
                    re=next[2][re][j];
                }
                int sl=s[1][le]-s[1][id];
                int sr=s[2][re]-s[2][id];
                if(max(sl,sr)!=t){
                    fail=1;
                    break;
                }
                if(sl==sr){
                    if(le<re){
                        id=le;
                        cc[1]++;
                        last=1;
                    }else {
                        id=re;
                        cc[2]++;
                        last=2;
                    }
                }else {
                    if(sl==t)cc[1]++,id=le,last=1;
                    else cc[2]++,id=re,last=2;
                }
            }
            if(cc[1]>cc[2]&&last==2)fail=1;
            if(cc[2]>cc[1]&&last==1)fail=1;
            if(!fail&&cc[1]!=cc[2])
                Ans.PB(MP(max(cc[1],cc[2]),t));
        }
        sort(Ans.OP,Ans.ED);
        printf("%d\n",Ans.SZ);
        for(i=0;i<Ans.SZ;i++)
            printf("%d %d\n",Ans[i].AA,Ans[i].BB);
    }
    return 0;
}

