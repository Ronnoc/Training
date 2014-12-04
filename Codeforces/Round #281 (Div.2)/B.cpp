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
void F(){puts("first");}
void S(){puts("second");}
LL a[200005];
vector<LL>f,s;
int main(){
    int i,j,k,_T;
    int n;
    while(cin>>n){
        f.clear(),s.clear();
        LL sf=0,ss=0;
        for(i=1;i<=n;i++){
            cin>>a[i];
            if(a[i]>0)sf+=a[i],f.PB(a[i]);
            else ss-=a[i],s.PB(-a[i]);
        }
        if(sf>ss){F();continue;}
        if(sf<ss){S();continue;}
        int last=a[n]>0?1:0;    //true with first
        bool ae=1;
        if(ae)for(i=0;i<f.SZ&&i<s.SZ;i++)
            if(f[i]!=s[i]){ae=0;break;}
        if(ae){
            if(f.SZ<s.SZ)S();
            else if(f.SZ>s.SZ)F();
            else if(last)F();
            else S();
            continue;
        }
        for(i=0;i<f.SZ&&i<s.SZ;i++){
            if(f[i]<s[i]){S();break;}
            if(s[i]<f[i]){F();break;}
        }
    }
    return 0;
}

