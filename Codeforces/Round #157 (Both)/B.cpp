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

int a[5][5];
int main(){
    if(!VER)freopen(NAME".in","r",stdin);
    if(!VER)freopen(NAME".out","w",stdout);
    int i,j,k,_T;
    for(i=1;i<=3;i++)
        for(j=1;j<=3;j++)
            scanf("%d",&a[i][j]);
    int yz=a[1][2]+a[1][3];
    int xz=a[2][1]+a[2][3];
    int xy=a[3][1]+a[3][2];
    int xyz=(xy+xz+yz)/2;
    a[1][1]=xyz-yz;
    a[2][2]=xyz-xz;
    a[3][3]=xyz-xy;
    for(i=1;i<=3;i++,cout<<"\n")
        for(j=1;j<=3;j++)cout<<a[i][j]<<" ";
    return 0;
}

