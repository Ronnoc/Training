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
    string h,a;
    while(cin>>h>>a){        
        map<char,string>name;
        name['h']=h;
        name['a']=a;
        int n;
        scanf("%d",&n);
        vector<pair<int,pair<pair<char,int>,int> > >L;
        while(n--){
            int t;
            char s1[5],s2[5];
            int r;
            scanf("%d%s%d%s",&t,s1,&r,s2);
            char x=s1[0];
            int add=s2[0]=='y'?1:2;
            L.PB(MP( t,MP(MP(x,r),add) ));
        }
        sort(L.OP,L.ED);
        map<pair<char,int>,int>MA;
        set<pair<char,int> >given;
        for(i=0;i<L.SZ;i++){
            MA[L[i].BB.AA]+=L[i].BB.BB;
            if(MA[L[i].BB.AA]>=2&&given.count(L[i].BB.AA)==0){
                cout<<name[L[i].BB.AA.AA]<<" "<<L[i].BB.AA.BB<<" "<<L[i].AA<<"\n";
                given.insert(L[i].BB.AA);
            }
        }
    }
    return 0;
}

