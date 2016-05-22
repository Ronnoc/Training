#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#include<iostream>
#include<set>
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
const LL MOD = 1000000007;
const double PI = acos(-1.);
const double eps = 1e-9;
int mod[20005];
int vis[20005];
int main(){
	int i,j,k,_T;
	cin>>_T;
	for(int CA=1;CA<=_T;CA++){
		LL x,m,k,c;
		cin>>x>>m>>k>>c;
		mod[0]=1%k;
		memset(vis,-1,sizeof vis);
		vis[mod[0]]=0;
		LL ans=0;
		for(i=1;;i++){
			mod[i]=mod[i-1]*10%k;
			if(~vis[mod[i]]){
				int le=vis[mod[i]],re=i;
				for(i=0;m&&i<le;i++){
					ans+=x*mod[i]%k;
					m--;
				}
				for(i=le;i<re;i++)
					ans+=x*mod[i]%k*(m/(re-le));
				m%=re-le;
				for(i=le;m&&i<re;i++){
					ans+=x*mod[i]%k;
					m--;
				}
				ans%=k;
				break;	
			}
			else vis[mod[i]]=i;
		}
		cout<<"Case #"<<CA<<":\n"<<(ans==c?"Yes":"No")<<"\n";
	}
	return 0;
}