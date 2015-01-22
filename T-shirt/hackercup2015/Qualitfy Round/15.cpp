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
#define NAME "15"

int main(){
    freopen(NAME".txt","r",stdin);
    freopen(NAME".out","w",stdout);
    int i,j,k,_T;
    cin>>_T;
    for(int CA=1;CA<=_T;CA++){
        string s;
        cin>>s;
        string p=s,q=s;
        for(i=0;i<s.SZ;i++)
            for(j=i+1;j<s.SZ;j++){
                string r=s;
                if(s[j]!='0'||i!=0){
                    swap(r[i],r[j]);
                    cmin(p,r);
                    cmax(q,r);
                }
            }
        cout<<"Case #"<<CA<<": "<<p<<" "<<q<<"\n";
    }
    return 0;
}

