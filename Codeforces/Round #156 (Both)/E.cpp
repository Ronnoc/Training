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
LL MAXA=777777777777LL;
int lim=sqrt(MAXA)+5;
vector<pair<LL,int> >U,V,L;
vector<pair<LL,int> >SG;
int getSG(LL x){
    int id=lower_bound(SG.OP,SG.ED,MP(x,-1))-SG.OP;
    return SG[id].BB;
}
int v[1005],now=0;
int main(){
    /*
    if(!VER)freopen(NAME".in","r",stdin);
    if(!VER)freopen(NAME".out","w",stdout);
    for(LL i=2;i<=lim;i++){
        LL tmp=i*i;
        U.PB(MP(tmp-1,i));
        tmp*=i;
        if(tmp<=lim){
            tmp*=i;
            V.PB(MP(tmp,-i));
        }
    }
    int iu=0,iv=0;
    while(iu<U.SZ&&iv<V.SZ){
        if(U[iu].AA<V[iv].AA)L.PB(U[iu++]);
        else L.PB(V[iv++]);
    }
    while(iu<U.SZ)L.PB(U[iu++]);
    while(iv<V.SZ)L.PB(V[iv++]);
    SG.PB(MP(3LL,0));
    v[0]++;
    now=1;
    for(int i=1;i<L.SZ;i++){
        LL x=L[i].AA;
        SG.PB(MP(x,now));
        int f=L[i].BB;
        int t=getSG(f>0?f:-f);
        if(f>0){
            v[t]++;
            while(v[now])now++;
        }else {
            v[t]--;
            if(v[t]==0)cmin(now,t);
        }
    }
    int i;
    for(i=1;i<SG.SZ;i++){
        if(SG[i].BB!=SG[i-1].BB)cout<<SG[i-1].AA<<" "<<SG[i-1].BB<<"\n";
    }
    cout<<SG[SG.SZ-1].AA<<" "<<SG[SG.SZ-1].BB<<"\n";*/
    int n;
    while(cin>>n){
        int w=0;
        while(n--){
            LL x;
            cin>>x;
                 if(x<=3LL)w^=0;
            else if(x<=15LL)w^=1;
            else if(x<=81LL)w^=2;
            else if(x<=6723LL)w^=0;
            else if(x<=50625LL)w^=3;
            else if(x<=2562991875LL)w^=1;
                 else w^=2;
        }
        if(w)puts("Furlo");
        else puts("Rublo");
    }
    return 0;
}
/*
3 0
15 1
81 2
6723 0
50625 3
2562991875 1
777777594888 4
*/
