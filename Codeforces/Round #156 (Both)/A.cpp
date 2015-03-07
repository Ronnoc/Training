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
    int n;
    while(~scanf("%d",&n)){
        vector<int>L;
        while(n--){
            int x;
            scanf("%d",&x);
            L.PB(x);
        }
        int s[4];
        s[0]=s[1]=s[2]=0;
        for(i=0;i<L.SZ;i++)
            s[i%3]+=L[i];
        if(s[0]>s[1]&&s[0]>s[2])puts("chest");
        if(s[1]>s[0]&&s[1]>s[2])puts("biceps");
        if(s[2]>s[0]&&s[2]>s[1])puts("back");

    }
    return 0;
}

