#include <cstdio>
#include <iostream>
using namespace std;
int main() {
	int T;
	scanf("%d",&T);
	while(T--){
		long long ans=0,mod;
		int n;
		cin>>mod>>n;
		int i;
		for(i=1;i<=n;++i){
			long long a,b;
			cin>>a>>b;
			long long add=1;
			while(b){
				if(b&1){add*=a;add%=mod;}
				a*=a;a%=mod;
				b/=2;
			}
			ans+=add;
		}
		ans%=mod;
		cout<<ans<<endl;
	}
	return 0;
}
