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

int main(){
    int i,j,k,_T;
    int n,m;
    while(~scanf("%d",&n)){
        vector<int>L,R;
        vector<int>V;
        while(n--){
            scanf("%d",&j);
            L.PB(j);
            V.PB(j);
            if(j>=1)V.PB(j-1);
            V.PB(j+1);
        }
        scanf("%d",&m);
        while(m--){
            scanf("%d",&j);
            R.PB(j);
            V.PB(j);
            if(j>=1)V.PB(j-1);
            V.PB(j+1);
        }
        sort(L.OP,L.ED);
        sort(R.OP,R.ED);
        sort(V.OP,V.ED);
        V.erase(unique(V.OP,V.ED),V.ED);
        int a,b,v=0;
        for(i=0;i<V.SZ;i++){
            int d=V[i];
            int il=upper_bound(L.OP,L.ED,d)-L.OP;
            int ir=upper_bound(R.OP,R.ED,d)-R.OP;
            int sl=L.SZ*3-il,sr=R.SZ*3-ir;
            if(v){
                if(sl-sr>a-b)a=sl,b=sr;
                else if(sl-sr==a-b){
                    if(sl>a)a=sl,b=sr;
                }
            }else a=sl,b=sr,v=1;
        }
        printf("%d:%d\n",a,b);
    }
    return 0;
}

