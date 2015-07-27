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

void update(LL &le,LL &re,LL pe,LL qe,vector<pair<LL,LL> >&V){
    if(le>re)return;
    if(pe>re)return;
    if(qe<le)return;
    if(le<pe){
        V.PB(MP(le,pe-1));
    }
    cmax(le,qe+1);
}
int main(){
    if(UsingFile)freopen(NAME".in","r",stdin);
    if(UsingFile)freopen(NAME".out","w",stdout);
    int i,j,k,_T;
    int h,q;
    while(~scanf("%d%d",&h,&q)){
        vector<pair<LL,LL> >Q[55][2];
        vector<pair<LL,LL> >V[55];
        while(q--){
            int x,y;
            LL L,R;
            scanf("%d%I64d%I64d%d",&x,&L,&R,&y);
            Q[x][y].PB(MP(L,R));
        }
        for(i=1;i<=h;i++){
            sort(Q[i][0].OP,Q[i][0].ED);
            sort(Q[i][1].OP,Q[i][1].ED);
            V[i].clear();
            LL le=1LL<<(i-1);
            LL re=(1LL<<i)-1;
            for(j=0;j<Q[i][1].SZ;j++){
                LL p=Q[i][1][j].AA;
                LL q=Q[i][1][j].BB;
                cmax(le,p);
                cmin(re,q);
            }
            vector<pair<LL,LL> >B;
            for(j=0;j<Q[i][0].SZ;j++)B.PB(Q[i][0][j]);
            int has=0;
            LL pe,qe;
            for(j=0;j<B.SZ;j++){
                if(!has)pe=B[j].AA,qe=B[j].BB,has=1;
                else {
                    if(B[j].AA<=qe){
                        cmax(qe,B[j].BB);
                    }else {
                        update(le,re,pe,qe,V[i]);
                        pe=B[j].AA;
                        qe=B[j].BB;
                    }
                }
            }
            if(has)update(le,re,pe,qe,V[i]);
            if(le<=re)V[i].PB(MP(le,re));
        }
        vector<pair<LL,LL> >A=V[1];
        for(i=2;i<=h;i++){
            vector<pair<LL,LL> >B,C;
            for(j=0;j<A.SZ;j++)B.PB(MP(A[j].AA<<1,A[j].BB<<1|1));
            int id=0;
            for(j=0;j<V[i].SZ;j++){
                LL pe=V[i][j].AA,qe=V[i][j].BB;
                while(id<B.SZ&&B[id].BB<pe)id++;
                if(id<B.SZ)
                    if(B[id].AA<=qe)C.PB(MP(max(B[id].AA,pe),min(B[id].BB,qe)));
            }
            //C = V[i] & B
            A=C;
        }
        if(A.empty())puts("Game cheated!\n");
        else if(A.SZ>1||A[0].BB!=A[0].AA)puts("Data not sufficient!");
        else cout<<A[0].AA<<"\n";
    }
    return 0;
}

