#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define SORT(x) sort(x.OP,x.ED)
#define SQ(x) ((x)*(x))
#define SSP system("pause")
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
typedef long long LL;
typedef pair<int, int> PII;
const double eps=1e-8;
const double PI=acos( -1. );
const LL MOD = 1000000007;
string s;
string a[11];
int main(){
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int i,j;
	while(cin>>s){
		for(i=0;i<8;i++){
			cin>>s;
			a[7-i].clear();
			for(j=2;j<s.SZ;j+=4)a[7-i]+=s[j];
			cin>>s;
		}
//		for(i=0;i<8;i++)cout<<a[i]<<endl;
		vector<string>W,B;
		for(i=0;i<8;i++)for(j=0;j<8;j++)
			if(a[i][j]=='K'){string add="K";add+=j+'a';add+=i+'1';W.PB(add);}
		for(i=0;i<8;i++)for(j=0;j<8;j++)
			if(a[i][j]=='Q'){string add="Q";add+=j+'a';add+=i+'1';W.PB(add);}
		for(i=0;i<8;i++)for(j=0;j<8;j++)
			if(a[i][j]=='R'){string add="R";add+=j+'a';add+=i+'1';W.PB(add);}
		for(i=0;i<8;i++)for(j=0;j<8;j++)
			if(a[i][j]=='B'){string add="B";add+=j+'a';add+=i+'1';W.PB(add);}
		for(i=0;i<8;i++)for(j=0;j<8;j++)
			if(a[i][j]=='N'){string add="N";add+=j+'a';add+=i+'1';W.PB(add);}
		for(i=0;i<8;i++)for(j=0;j<8;j++)
			if(a[i][j]=='P'){string add="";add+=j+'a';add+=i+'1';W.PB(add);}
			
		
		for(i=7;i>=0;i--)for(j=0;j<8;j++)
			if(a[i][j]=='k'){string add="K";add+=j+'a';add+=i+'1';B.PB(add);}
		for(i=7;i>=0;i--)for(j=0;j<8;j++)
			if(a[i][j]=='q'){string add="Q";add+=j+'a';add+=i+'1';B.PB(add);}
		for(i=7;i>=0;i--)for(j=0;j<8;j++)
			if(a[i][j]=='r'){string add="R";add+=j+'a';add+=i+'1';B.PB(add);}
		for(i=7;i>=0;i--)for(j=0;j<8;j++)
			if(a[i][j]=='b'){string add="B";add+=j+'a';add+=i+'1';B.PB(add);}
		for(i=7;i>=0;i--)for(j=0;j<8;j++)
			if(a[i][j]=='n'){string add="N";add+=j+'a';add+=i+'1';B.PB(add);}
		for(i=7;i>=0;i--)for(j=0;j<8;j++)
			if(a[i][j]=='p'){string add="";add+=j+'a';add+=i+'1';B.PB(add);}
		
		cout<<"White:";
		if(!W.empty())cout<<" "<<W[0];
		for(i=1;i<W.SZ;i++)cout<<","<<W[i];
		cout<<endl;
		cout<<"Black:";
		if(!B.empty())cout<<" "<<B[0];
		for(i=1;i<B.SZ;i++)cout<<","<<B[i];
		cout<<endl;
	}
	return 0;
}
