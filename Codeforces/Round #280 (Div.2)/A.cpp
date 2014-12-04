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
    int n;
    while(~scanf("%d",&n)){
        int id=1;
        while(n>=id*(1+id)/2){
            n-=id*(1+id)/2;
            id++;
        }
        id--;
        printf("%d\n",id);
    }
    return 0;
}

