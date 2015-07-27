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

int mabs(int x){return x<0?-x:x;}
int main(){
    if(UsingFile)freopen(NAME".in","r",stdin);
    if(UsingFile)freopen(NAME".out","w",stdout);
    int i,j,k,_T;
    int n;
    while(~scanf("%d",&n)){
        vector<int>L,R;
        for(i=0;i<n;i++){
            scanf("%d",&j);
            L.PB(j);
        }
        sort(L.OP,L.ED);
        for(i=0;i<L.SZ;i++){
            R.PB(32-__builtin_clz(L[i]));
        }
        int ans=-1;
        for(i=0;i<=R[0];i++)if(L[0]>>i&1){
            int x=L[0]>>i;
            int lx=32-__builtin_clz(x);
            map<int,int>C;
            int fail=0;
            int now=0;
            for(j=0;j<L.SZ;j++){
                int z=L[j];
                int t=R[j]-lx;
                int y=L[j]>>t;
                if(x==y){
                    while(z!=x<<t){
                        z>>=1;
                        now++;
                        t--;
                    }
                    C[t]++;
                }else fail=1;
            }
            if(fail)continue;
            vector<PII>P(C.OP,C.ED);
            int best=-1;
            for(j=0;j<P.SZ;j++){
                int temp=0;
                for(k=0;k<P.SZ;k++)
                    temp+=mabs(P[k].AA-P[j].AA)*P[k].BB;
                if(best==-1)best=temp;
                else cmin(best,temp);
            }
            now+=best;
            if(ans==-1)ans=now;
            else cmin(ans,now);
        }
        printf("%d\n",ans);
    }
    return 0;
}

