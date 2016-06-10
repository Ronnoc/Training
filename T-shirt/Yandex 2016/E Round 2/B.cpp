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
const LL MOD = 1000000007;
const double PI = acos(-1.);
const double eps = 1e-9;

int f(int z,int t){
	if(z<0)return 0;
	if(z==0)return -1;
	int id=0;
	while(z>>id)id++;
	id--;
	int ret;
	if(z>>t){
		if(t==id){
			ret= (z+1)-(1<<(t+1));
		}else 
			ret= f(z-(1<<id),t);
	}else ret=-(z+1);
	//cout<<z<<">>"<<id<<"?"<<t<<" "<<ret<<"\n";;
	return ret;
}
int main(){
	int i,j,k,_T;
	int l,r;
	while(~scanf("%d%d",&l,&r)){
		int ans=0;
		for(i=0;r>>i;i++){
			int c1=f(r,i)-f(l-1,i);//c1-c0
			if(c1>0)ans|=1<<i;
			//cout<<i<<"~"<<c1<<"\n";
		}
		cout<<ans<<"\n";
	}
	return 0;
}