#include <iostream>
using namespace std;
int main() {
int OFFL=0;
#ifndef ONLINE_JUDGE
OFFL=1;
#endif
	int n,t;
	cin>>t;
	while(t--){
		cin>>n;
		int ans=0,mx=0;
		while(n--){
			int x;
			cin>>x;
			ans =ans xor x;
			mx=max(mx,x);
		}
		if(ans&&mx>1)cout<<"John\n";
		else if(!ans&&mx<=1)cout<<"John\n";
		else cout<<"Brother\n";
	}
return 0;}
