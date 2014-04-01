#include <iostream>
#include <vector>
using namespace std;
bool solve(int n){
	int i,tp=n;
	vector<int>L;
	for(i=2;i*i<=tp;i++){
		while(n%i==0){L.push_back(i);n/=i;}
	}
	if(n>1)L.push_back(n);
//	cout<<L.size()<<endl;;
	if(L.size()!=2)return 0;
	return 1;
}
int main() {
#ifndef ONLINE_JUDGE
#endif
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		string s=solve(n) ?"Yes":"No";
		cout<< s <<endl;
	}
return 0;}
