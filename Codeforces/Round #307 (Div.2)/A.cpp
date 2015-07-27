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
    while(cin>>n){
        vector<PII>L;
        for(i=1;i<=n;i++){
            int w;
            scanf("%d",&w);
            L.PB(MP(-w,i));
        }
        sort(L.OP,L.ED);
        vector<PII>R;
        int lv=-100000000;
        int last=0,cnt=0;;
        for(i=0;i<L.SZ;i++){
            if(L[i].AA>lv)
                last=i+1,lv=L[i].AA;
            R.PB(MP(L[i].BB,last));
        }
        sort(R.OP,R.ED);
        for(i=0;i<R.SZ;i++)cout<<R[i].BB<<" ";
        cout<<"\n";
    }
    return 0;
}

