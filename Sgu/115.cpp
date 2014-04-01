#include <iostream>
using namespace std;
int yue[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main() {
#ifndef ONLINE_JUDGE
#endif
	int n,m;
	while(cin>>n>>m){
		int i,tot=0;
		for(i=1;i<m;i++)tot+=yue[i];
		if(m>12||n>yue[m]){
			cout<<"Impossible"<<endl;
			continue;
		}
		tot+=n;
		tot%=7;
		if(!tot)tot+=7;
		cout<<tot<<endl;
	}
return 0;}
