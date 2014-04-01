#include <iostream>
using namespace std;
int main(){
	int T;
	cin>>T;
		while(T--){
			int r,e,c;
			cin>>r>>e>>c;
			if(e-r>c)cout<<"advertise\n";
			else if(e-r==c)cout<<"does not matter\n";
			else cout<<"do not advertise\n";
		}
	return 0;
}
