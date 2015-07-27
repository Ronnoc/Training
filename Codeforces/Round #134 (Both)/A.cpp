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
    while(~scanf("%d",&n)){
        int a[1111];
        for(i=1;i<=n;i++)a[i]=i;
        for(i=n-1;i>=1;i--)swap(a[i],a[i+1]);
        for(i=1;i<=n;i++)printf("%d ",a[i]);
        printf("\n");
    }
    return 0;
}

