#include <iostream>
using namespace std;
#define _LL long long 
_LL phi( _LL n )
{
	_LL i,tp=n;
	_LL res=n;
	for ( i=2; i<=n&&i*i<=tp; i++ )
		while ( n%i==0 )
		{
			res*=( i-1 );
			res/=i;
			while ( n%i==0 )
				n/=i;
		}
	if ( n>1 )
	{
		res/=n;
		res*=n-1;
	}
	return res;
}
_LL gcd(_LL a,_LL b){return b?gcd(b,a%b):a;}
_LL find(_LL n,_LL k){
	int i;
	int tot=-1;
	for(i=1;i<=n;i++){
		if(gcd(i,n)==1){tot++;if(tot==k)return i;}
	}
}
int main() {
int OFFL=0;
#ifndef ONLINE_JUDGE
OFFL=1;
#endif
	_LL n,k;
	while(cin>>n>>k){
		_LL p=phi(n);
//		cout<<"p: "<<p<<endl;
		_LL t=(k-1)/p;
//		cout<<"t: "<<t<<endl;
		cout<<t*n+find(n,k-1-p*t)<<endl;
	}
return 0;}
