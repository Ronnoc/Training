#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <map>
#include <stdio.h>
#include <set>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define MP make_pair
#define PB push_back
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
const LL MOD = 1000000007;
const double PI = acos(-1.);
const double eps = 1e-9;

int count(const vector<int> &L){
    int res = 0;
    for(int i=0;i<L.size();++i){
        for(int j=i+1;j<L.size();++j){
            if(L[i]>L[j])
                res++;
        }
    }
    return res;
}

void solve()
{
    int R,S;
    scanf("%d%d",&R,&S);
    vector<PII> L;
    for (int j = 0; j < S; ++j)
        for (int i = 0; i < R; ++i)
            L.emplace_back(i,1);
    vector<PII>res;
    while(cl>0){
        int bc = cl;
        PII next=MP(-1,-1);
        vector<int>nr;
        for(int p=1;p<L.SZ;++p)
            for(int q=1;p+q<L.SZ;++q){
                vector<int>R;
                for(int i=0;i<q;++i)R.PB(L[p+i]);
                for(int i=0;i<p;++i)R.PB(L[i]);
                for(int i=p+q;i<L.SZ;++i)R.PB(L[i]);
                int newc=count(R);
                if(newc<bc or (newc==bc && p+q >next.AA+next.BB)){
                    bc = newc;
                    next=MP(p,q);
                    nr=R;
                }
            }
        L=nr;
        res.PB(next);
        cl=bc;
        // cout<<next.AA<<"~"<<next.BB<<"\n";
        // for(int i=0;i<L.SZ;++i)cout<<L[i]<<" ";cout<<"\n";
    }
    printf("%d\n",res.SZ);
    for(auto pr:res)
        printf("%d %d\n",pr.AA,pr.BB);
}

int main()
{
    int i, j, k, _T;
    scanf("%d", &_T);
    for (int CA = 1; CA <= _T; CA++)
    {
        printf("Case #%d: ", CA);
        solve();
    }
    return 0;
}

// 0 2 4 1 3 5
// 1 3 0 2 4 5 (3,2)
// 0 1 3 2 4 5 (2,1)