#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
#endif
	int i,n,m,x;
	cin>>n>>m;
	vector<int>L;
	for(i=1;i<=m;i++){
		cin>>x;
		if(x>999&&x<8000||x>8999)L.push_back(x);
	}
	sort(L.begin(),L.end());
	int tot[10];
	for(i=1;i<=7;i++)tot[i]=0;
	for(i=0;i<L.size();i++){
		tot[L[i]/1000]++;
	}
	int res=2;
	for(i=1;i<=9;i++)res+=(n-1+tot[i])/n;
	cout<<res<<endl;
return 0;}
