#include<stdio.h>
#include<algorithm>
using namespace std;
#define N 50010
int a[N],sum[N],n;
int lmax[N],wl[N];	//表示以i未结束的最大值 
int rmax[N],wr[N];
int ldp[N],rdp[N];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		int i;
		for(i=1;i<=n;i++)scanf("%d",&a[i]);
		
		sum[0]=0;
		for(i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
		
		lmax[1]=a[1],wl[1]=1;
		for(i=2;i<=n;i++){
			if(lmax[i-1]>0){lmax[i]=lmax[i-1]+a[i];wl[i]=wl[i-1];}
			else {lmax[i]=a[i];wl[i]=i;}
			}
		rmax[n]=a[n],wr[n]=n;
		for(i=n-1;i>=1;i--){
			if(rmax[i+1]>0){rmax[i]=rmax[i+1]+a[i];wr[i]=wr[i+1];}
			else {rmax[i]=a[i];wr[i]=i;}
			}
		
		ldp[1]=lmax[1];
		for(i=2;i<=n;i++)ldp[i]=max(lmax[i],ldp[i-1]);
		rdp[n]=rmax[n];
		for(i=n-1;i>=1;i--)rdp[i]=max(rmax[i],rdp[i+1]);
		
		int res=ldp[1]+rdp[2];
		for(i=2;i<n;i++)res=max(res,ldp[i]+rdp[i+1]);
		
		printf("%d\n",res);
		}
	return 0;
	} 
