#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int ext_gcd (int a, int b, int &x, int &y) {
	int t, ret;
	if (!b) {
		x = 1;
		y = 0;
		return a;
		}
	ret = ext_gcd (b, a % b, x, y);
	t = x;
	x = y;
	y = t - a / b * y;
	return ret;
	}
int Inverse (int a, int mod) {
	int d, x, y;
	d = ext_gcd (a, mod, x, y);
	return d == 1 ? (x + mod) % mod : -1;
	}
int a[60];
int Q,N, inv[110];
int xs[60][60],bs[60];
int gauss(int n,int a[][60],int b[]){
	int i,j,k,row;
	int maxp,t;
	for (k=0;k<n;k++){
		for (maxp=-1,i=k;i<n;i++)
			if(a[i][k]>maxp)
				maxp=a[row=i][k];
		if(maxp==0)
			return 0;
		if(inv[maxp]==-1)
			return 0;
		if (row!=k){
			for (j=k;j<n;j++)
				swap(a[k][j],a[row][j]);
			swap(b[k],b[row]);
			}
		for (j=k+1;j<n;j++){
			a[k][j]*=inv[maxp];
			a[k][j]%=Q;
			for (i=k+1;i<n;i++){
				a[i][j]+=Q-a[i][k]*a[k][j];
				a[i][j]%=Q;
				}
			}
			b[k]*=inv[maxp];
			b[k]%=Q;
			for(i=k+1;i<n;i++){
				b[i]+=Q-b[k]*a[i][k];
				b[i]%=Q;
				}
		}
	for(i=n-1;i>=0;i--)
		for (j=i+1;j<n;j++){
			b[i]+=Q-a[i][j]*b[j];
			b[i]%=Q;
			}
	for(i=0;i<n;i++)
		if(b[i]>2)
			return 0;
//	for(i=0;i<n;i++)cout<<b[i]<<" ";cout<<endl;
	return 1;
	}
void solve() {
	cin>>Q>>N;
	int i,j,k;
	for(i=0;i<Q;i++)inv[i]=Inverse(i,Q);
	for(i=0;i<N;i++)cin>>a[i];
	bs[0]=1;
	for(i=1;i<N;i++)bs[i]=0;
	for(k=0;k<N;k++){
		for(i=0;i<=k;i++)xs[k][i]=a[k-i];
		for(i=k+1;i<N;i++)xs[k][i]=a[N+k-i];
	}
	int flag=gauss(N,xs,bs);
	if(flag)cout<<"A solution can be found\n";
	else cout<<"No solution\n";
	}
int main() {
#ifndef ONLINE_JUDGE
#endif
	int T;
	cin >> T;
	while (T--) solve();
	return 0;
	}
