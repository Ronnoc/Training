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

char s[200005];
vector<int>L;
int main(){
    int i,j,k,_T;
    while(~scanf("%s",s)){
        int tot=0;
        L.clear();
        int la=-1;
        int le=0,re=0,ss=0;
        for(i=0;s[i];i++){
            if(s[i]=='(')tot++;
            else tot--;
            if(s[i]=='#')la=i,ss++;
            if(s[i]=='(')le++;
            if(s[i]==')')re++;
        }
        if(tot<0){
            printf("-1\n");
            continue;
        }
        int cnt=0;
        int fail=0;
        for(i=0;s[i];i++){
            if(s[i]!='#'){
                if(s[i]=='(')cnt++;
                else cnt--;
            }else {
                if(i==la)cnt-=1+le-re-ss;
                else cnt--;
            }
            if(cnt<0)fail=1;
        }
        if(fail)puts("-1");
        else {
            for(i=1;i<ss;i++)cout<<1<<" ";
            cout<<1+le-re-ss<<"\n";
        }
    }
    return 0;
}

