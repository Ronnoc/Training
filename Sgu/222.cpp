#include <iostream>
using namespace std;
long long A[22][22];
int main(){
	int i,j,t;
	for(i=0;i<=10;i++){
		A[i][0]=1;
		for(j=1,t=i;j<=i;j++,t--)
			A[i][j]=A[i][j-1]*t;
	}
	int n,k;
	while(cin>>n>>k){
		if(k<=n)cout<<(A[n][k]*A[n][k]/A[k][k])<<endl;
		else cout<<0<<endl;
	}
	return 0;
}
