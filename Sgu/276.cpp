#include <iostream>
using namespace std;
int main(){
	int s,p;
	while(cin>>s>>p){
		int t=p-s;
		if(t<=0)cout<<"0\n";
		else if(t<300)cout<<"1\n";
		else if(t<900)cout<<"2\n";
		else if(t<1800)cout<<"3\n";
		else cout<<"4\n";
	}
	return 0;
}
