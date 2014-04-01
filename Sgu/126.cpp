#include<iostream>
using namespace std;
int find(int a,int b){
	if(!a||!b)return 0;
	if(a>b)return 1+find(a-b,b+b);
	else return 1+find(b-a,a+a);
}
int main(){
	int a,b;
	while(cin>>a>>b){
		int tot=a+b;
		int gcd=tot&(-tot);
		if(a%(tot/gcd)||b%(tot/gcd))cout<<-1<<endl;
		else cout<<find(a,b)<<endl;
	}
	return 0;
}
