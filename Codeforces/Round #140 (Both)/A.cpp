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

int main(){
    if(!VER)freopen(NAME".in","r",stdin);
    if(!VER)freopen(NAME".out","w",stdout);
    int i,j,k,_T;
    int x[3],y[3];
    for(i=0;i<3;i++)cin>>x[i]>>y[i];
    LL px=x[1]-x[0],py=y[1]-y[0];
    LL qx=x[2]-x[1],qy=y[2]-y[1];
    LL f=px*qy-py*qx;
    if(f==0)puts("TOWARDS");
    else if(f<0)puts("RIGHT");
    else puts("LEFT");
    return 0;
}

