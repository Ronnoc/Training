#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define SORT(x) sort(x.OP,x.ED)
#define SQ(x) ((x)*(x))
#define SSP system("pause")
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
#define NAME ""
typedef long long LL;
typedef pair<int, int> PII;
const double eps=1e-8;
const double PI=acos(-1.);
const LL MOD = 1000000007;

int cost[7][4][7][4];
PII rehash(int w){
    return MP(w/4,w%4);
}
int hash(int x,int y){
    return x*4+y;
}
int mabs(int x){return x<0?-x:x;}
int calcost(int x,int y){
    PII X=rehash(x),Y=rehash(y);
    return cost[X.AA][X.BB][Y.AA][Y.BB];
}
int ok(int q,int w){return (q&3)<=(w&3);}
pair<PII,PII>piiii(int a,int s,int d,int f){
    return MP(MP(a,s),MP(d,f));
}
int main() {
    //freopen(NAME".in","r",stdin);
    //freopen(NAME".out","w",stdout);
    int i,j,k,l,_T;
    for(i=0;i<7;i++)for(j=0;j<4;j++)
        for(k=0;k<7;k++)for(l=0;l<4;l++){
            int &tp=cost[i][j][k][l];
            tp=0;
            tp+=mabs(i-k);
            tp+=mabs(j-l);
        }
    scanf("%d",&_T);
    for(int CA=1;CA<=_T;CA++){
        printf("Case #%d:\n",CA);
        int n;
        scanf("%d",&n);
        int x=0,y=1;
        map<pair<PII,PII>,int>Q[2];
        Q[x][piiii(0,1,2,3)]=0;
        while(n--){
            vector<int>L;
            int A,B;
            for(i=0;i<4;i++){
                scanf("%d%d",&A,&B);
                int st=A*4+B-1;
                L.PB(st);
            }
            sort(L.OP,L.ED);
            do{
                int gao=1;
                for(i=1;i<L.SZ;i++)if(!ok(L[i-1],L[i]))gao=0;
                if(gao){
                    int tmp=-1;
                    for(map<pair<PII,PII>,int>::iterator it=Q[x].OP;it!=Q[x].ED;++it){
                        pair<PII,PII>tp=(*it).AA;
                        int z=(*it).BB;
                        vector<int>F;
                        F.PB(tp.AA.AA);
                        F.PB(tp.AA.BB);
                        F.PB(tp.BB.AA);
                        F.PB(tp.BB.BB);
                        for(i=0;i<F.SZ;i++)z+=calcost(F[i],L[i]);
                        if(tmp==-1)tmp=z;
                        else cmin(tmp,z);
                    }
                    Q[y][piiii(L[0],L[1],L[2],L[3])]=tmp;
                    //cout<<L[0]<<" "<<L[1]<<" "<<L[2]<<" "<<L[3]<<"=>"<<tmp<<"\n";
                }
            }while(next_permutation(L.OP,L.ED));
            swap(x,y);
            Q[y].clear();
        }
        int ans=-1;
        for(map<pair<PII,PII>,int>::iterator it=Q[x].OP;it!=Q[x].ED;++it){
            int z=(*it).BB;
            if(ans==-1)ans=z;
            else cmin(ans,z);
        }
        printf("%d\n",ans);
    }
    return 0;
}
