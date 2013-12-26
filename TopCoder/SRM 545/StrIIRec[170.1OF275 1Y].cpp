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
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <numeric>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <functional>
#include <assert.h>

using namespace std;

#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size() 
#define SORT(p) sort(p.OP,p.ED)
typedef long long LL;
typedef pair<int, int> PII;


class StrIIRec {
public:
  string recovstr (int N, int cnt, string s) {
  	int vis[33];
  	memset(vis,0,sizeof vis);
  	for(int i=0;i<s.SZ;i++)vis[s[i]-'a']++;
  	for(int i=0;i<N;i++)if(!vis[i])s+='a'+i;
  	cout<<s<<" ,aim: "<<cnt<<endl;
    string ret="";
    int i,j,n=s.SZ,id,k;
//    assert(n==N);
    int inv[33];
    memset(inv,0,sizeof inv);
    for(i=0;i<n;i++)for(j=i+1;j<n;j++)if(s[j]<s[i])inv[i]++;
    for(i=0;i<n;i++)cout<<" "<<inv[i];cout<<endl;
    for(id=1;id<n;id++){
			int mx=0;
			for(j=0;j<id;j++)mx+=inv[j];
			mx+=(N-id)*(N-id-1)/2;
			cout<<" "<<mx;
			if(mx<cnt)break;
    }
    cout<<endl;
    id--;
    cout<<"id="<<id<<endl;
    for(i=0;i<id;i++)ret+=s[i];
    while(ret.SZ<n){
			cout<<ret<<" ";
			memset(vis,0,sizeof vis);
			for(i=0;i<ret.SZ;i++)vis[ret[i]-'a']++;
			for(i=0;i<N;i++){
				if(vis[i])continue;
				string tp=ret;
				tp+='a'+i;
				for(j=N-1;j>=0;j--)if(!vis[j]&&i!=j)tp+='a'+j;
				int mx=0;
				for(j=0;j<tp.SZ;j++)for(k=j+1;k<tp.SZ;k++)if(tp[j]>tp[k])mx++;
				if(mx>=cnt)break;
			}
			ret+='a'+i;
			cout<<"-->"<<ret<<endl;
    }
    if(ret.SZ==n)return ret;
    else return "";
  }
};



// Powered by FileEdit
// Powered by moj 4.12 [modified TZTester]
// Powered by CodeProcessor
