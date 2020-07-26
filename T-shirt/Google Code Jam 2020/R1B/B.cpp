#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <map>
#include <stdio.h>
#include <set>
#include <algorithm>
#include <random>
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

int xAA,xBB;

void solve1(){
    char s[100];
    for (int i = -5; i <= 5; ++i)
        for (int j = -5; j <= 5; ++j)
        {
            printf("%d %d\n", i, j);
            fflush(stdout);
            scanf("%s", s);
            if (string(s) == string("CENTER"))
                return;
        }
}

int check(PII cir, PII query){
    LL dx=cir.AA-query.AA;
    LL dy = cir.BB-query.BB;
    LL R=xAA;
    if(dx*dx+dy*dy<=R*R)return 1;
    return 0;
}

void solve2()
{
    string hit=string("HIT");
    string miss=string("MISS");
    string center=string("CENTER");
    int R=xAA;
    int d=1000000000-R;
    set<PII>KP;
    for(int i=-d;i<=d;++i)
        for(int j=-d;j<=d;++j)
            KP.insert(MP(i,j));
    char s[100];
    while(KP.SZ>1){
        vector<PII>VP(KP.OP,KP.ED);
        PII C;
        LL minx=VP[0].AA,miny=VP[0].BB,maxx=VP[0].AA,maxy=VP[0].BB;
        for(int i=1;i<VP.SZ;++i){
            minx = min(minx, 1LL * VP[i].AA);
            maxx = max(maxx, 1LL * VP[i].AA);
            miny = min(miny, 1LL * VP[i].BB);
            maxy = max(maxy, 1LL * VP[i].BB);
        }
        LL avgx=(minx+maxx)/2;
        LL avgy=(miny+maxy)/2;
        vector<pair<LL,LL> >Ccand;
        for(int i=-1;i<=1;++i)
            for(int j=-1;j<=1;++j){
                Ccand.push_back(MP(avgx - R + i, avgy + j));
                Ccand.push_back(MP(avgx + R + i, avgy + j));
                Ccand.push_back(MP(avgx + i, avgy - R + j));
                Ccand.push_back(MP(avgx + i, avgy + R + j));
            }
        int diff_abs=VP.SZ;
        for(auto oc:Ccand){
            int x=0;
            for (auto pr : VP)
                if (check(pr, oc) == 1)
                    x++;
            int newdiff = VP.SZ-x-x;
            if(newdiff<0)newdiff = -newdiff;
            if(newdiff<diff_abs){
                diff_abs=newdiff;
                C=oc;
            }
        }

        printf("%d %d\n",C.AA,C.BB);
        fflush(stdout);
        scanf("%s",s);
        string ss=string(s);
        if(ss==hit){
            KP.clear();
            for(auto pr:VP)
                if(check(pr,C)==1)
                    KP.insert(pr);
        }else if(ss==miss){
            KP.clear();
            for (auto pr : VP)
                if (check(pr, C) == 0)
                    KP.insert(pr);
        }else 
            return;
        // cerr<<KP.SZ<<"\n";
    }
    PII res=*KP.OP;
    printf("%d %d\n",res.AA,res.BB);
    fflush(stdout);
    scanf("%s", s);
}

int main()
{
    int i, j, k, _T;
    scanf("%d", &_T);
    scanf("%d%d", &xAA, &xBB);
    for (int CA = 1; CA <= _T; CA++)
    {
        solve2();
    }
    return 0;
}