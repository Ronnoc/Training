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
const int MXN = 210000 + 10;//SGT
PII P[MXN];
PII S[MXN];
int K[MXN];
vector<int>Z;
int n,m;
int gao(int x){
    int id=lower_bound(Z.OP,Z.ED,x)-Z.OP;
    return id+1;
}
int Ans[MXN];
int main(){
    int i,j,k,_T;
    while(~scanf("%d",&n)){
        for(i=0;i<n;i++)scanf("%d%d",&P[i].AA,&P[i].BB);
        scanf("%d",&m);
        for(i=0;i<m;i++)scanf("%d%d%d",&S[i].AA,&S[i].BB,&K[i]);
        Z.clear();
        for(i=0;i<n;i++)Z.PB(P[i].AA),Z.PB(P[i].BB);
        for(i=0;i<m;i++)Z.PB(S[i].AA),Z.PB(S[i].BB);
        sort(Z.OP,Z.ED);
        Z.erase(unique(Z.OP,Z.ED),Z.ED);
        for(i=0;i<n;i++){
            P[i].AA=gao(P[i].AA);
            P[i].BB=gao(P[i].BB);
        }
        for(i=0;i<m;i++){
            S[i].AA=gao(S[i].AA);
            S[i].BB=gao(S[i].BB);
        }
        vector<PII>TL;
        for(i=0;i<n;i++)TL.PB( MP(P[i].AA,i+1) );
        for(i=0;i<m;i++)TL.PB( MP(S[i].AA,-i-1) );
        sort(TL.OP,TL.ED);
        bool fail=0;
        set<pair<PII,int> >z;
        set<pair<PII,int> >::iterator it;
        for(int t=0;t<TL.SZ;t++){
            int q=TL[t].BB;
            if(q>0){
                it=z.lower_bound(MP( MP(P[q-1].BB,-1),-1 ));
                if(it==z.ED){fail=1;break;}
                else {
                    int a=(*it).AA.AA,b=(*it).AA.BB,c=(*it).BB;
                    z.erase(it);
                    Ans[q]=c;
                    if(b>1)z.insert(MP(MP(a,b-1),c));
                }
            }else {
                q=-q;
                z.insert(MP(MP(S[q-1].BB,K[q-1]),q));
            }
        }
        if(fail)puts("NO");
        else {
            puts("YES");
            for(i=1;i<=n;i++)printf("%d ",Ans[i]);
            printf("\n");
        }
    }
    return 0;
}
