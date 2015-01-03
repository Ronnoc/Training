#include<cstdio>
using namespace std;
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

int w[1005];
int main(){
    int i,j,k,_T;
    scanf("%d",&_T);
    while(_T--){
        int n;
        scanf("%d",&n);
        int s[3];
        s[0]=s[1]=0;
        for(i=0;i<n;i++){
            scanf("%d",&w[i]);
            s[i%2]+=w[i];
        }
        int flag=1;
        for(i=0;i<n;i++)
            if(w[i]!=w[n-1-i])flag=0;
        if(!flag&&s[0]==s[1])puts("Yes");
        else puts("No");
    }
    return 0;
}

