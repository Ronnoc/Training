#include <cstdio>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <list>
using namespace std;
#define MP 65536
bool isp[66666];
bool tmd[1000010];
int L,U;
vector<int>prime,Z;
vector<int>::iterator il,ir;
int prime_shai(){
	prime.clear();
	int i,j;
	for(i=2;i<=MP;i++)isp[i]=1;
	for(i=2;i<=MP;i++){
		if(!isp[i])continue;
		prime.push_back(i);
		for(j=2*i;j<=MP;j+=i)isp[j]=0;
	}
}
int main(){
	prime_shai();
	while(cin>>L>>U){		//L=200000000,U=201000000	//L=2146483648,U=2147483647
		Z.clear();			//200000000 201000000	//2146483648 2147483647
		long long i,j;
		for(i=0;i<=U-L;i++)tmd[i]=1;
		if(L==1)tmd[0]=0;
		for(i=0;i<prime.size();i++){
			int pp=prime[i];
			int tp=L%pp;
			for(j=(pp-tp)%pp;j<=U-L;j+=pp)tmd[j]=0;
//			if(pp-tp<=U-L)cout<<pp-tp<<" + "<<pp<<" --> "<<j<<endl;
			if(pp>=L)tmd[pp-L]=1;
		}
		for(i=0;i<=U-L;++i)if(tmd[i])Z.push_back(i+L);
		if(Z.size()<2)printf("There are no adjacent primes.\n");
		else {
			int p=1000001,pl,pr,q=0,ql,qr;
			for(il=Z.begin(),ir=++Z.begin();ir!=Z.end();++ir){
				int l=*il,r=*ir;
				if(r-l<p)p=r-l,pl=l,pr=r;
				if(r-l>q)q=r-l,ql=l,qr=r;
				il=ir;
			}
			printf("%d,%d are closest, %d,%d are most distant.\n",pl,pr,ql,qr);
		}
	}
	return 0;
}
