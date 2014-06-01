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
const double INF=1e20;
const double PI=acos( -1. );
const int MXN = 50;
const LL MOD = 1000000007;
char s[1111][11];
int nid;
struct node{
	int next[33];
	node() {memset(next,-1,sizeof next);}
}O,Trie[8000];

int main(){
	freopen("D-small-attempt1.in","r",stdin);
	freopen("D-small-attempt1.out","w",stdout);
	int i,j;
	int T;
	scanf("%d",&T);
	for(int CASE=1;CASE<=T;++CASE){
		int n,m;
		scanf("%d%d",&m,&n);
		for(i=0;i<m;i++)scanf("%s",s[i]);
		LL tot=1;
		for(i=1;i<=m;i++)tot*=n;
		int ans=0;
		map<int,int>M;
		for(int ii=0;ii<tot;ii++){
			int a[11];
			int now=ii;
			set<int>SS;
			for(i=0;i<m;i++){
				a[i]=now%n;
				now/=n;
				SS.insert(a[i]);
			}
			if(SS.SZ!=n)continue;
			for(i=0;i<=nid;i++)Trie[i]=O;
			nid=n;
			for(i=0;i<m;i++){
				int now=a[i];
//				cout<<i<<": ";
				for(j=0;s[i][j];j++){
					int c=s[i][j]-'A';
//					cout<<now<<s[i][j];
					if(Trie[now].next[c]==-1){
						Trie[now].next[c]=nid;
						now=nid;
						nid++;
					}else now=Trie[now].next[c];
//					cout<<now<<" ";
				}
//				cout<<endl;
			}
//			cout<<ii<<" ";
//			for(i=0;i<m;i++)cout<<a[i]<<" ";
//			cout<<"->"<<nid-n<<endl;
			cmax(ans,nid-n);
			M[nid-n]++;
		}
		printf("Case #%d: %d %d\n",CASE,ans+n,M[ans]);
	}
	return 0;
}
