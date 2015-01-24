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

int main(){
    int i,j,k,_T,h;
    LL n;
    while(cin>>h>>n){
        LL ret=0;
        int f=1;
        for(i=h-1;i>=0;i--){
            ret++;
            if(f==1){
                if(n>1LL<<i)
                    n-=1LL<<i,ret+=(2LL<<i)-1,f=1;
                else f=0;
            }else {
                if(n>1LL<<i)n-=1LL<<i,f=1;
                else ret+=(2LL<<i)-1,f=0;
            }
        }
        cout<<ret<<"\n";
    }
    
    return 0;
}

