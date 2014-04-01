#include <iostream>
using namespace std;
int count(int x){
	int res=0;
	while(x){
		res+=x/5;
		x/=5;
	}
	return res;
}
int Bfind(int l,int r,int aim){
//	cout<<l<<" "<<r<<" "<<endl;
	if(r-l<=1){
		if(count(l)==aim)return l;
		else if(count(r)==aim)return r;
		else return -1;
	}
	int mid=(l+r)/2;
	int fmid=count(mid);
	if(fmid>=aim)return Bfind(l,mid,aim);
	else return Bfind(mid+1,r,aim);
}
int main() {
	int n;
	cin>>n;
	int ans=Bfind(1,500000000,n);
	if(ans!=-1)cout<<Bfind(1,500000000,n)<<endl;
	else cout<<"No solution\n";
#ifndef ONLINE_JUDGE
return main();
#endif
return 0;}
