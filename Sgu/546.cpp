#include <iostream>
using namespace std;
char s[222];
int main() {
  int n,i,j,k,q[3];
  while ( cin>>n>>q[0]>>q[1]>>s ) {
    q[2]=n-q[0]-q[1];
    if(q[2]<0){
			cout<<-1<<endl<<endl;
			continue;
    }
    int p[3];
    for(i=0;i<3;i++)p[i]=0;
    for ( int i=0; i<n; i++ ) p[ s[i]-'0' ]++;
    int mtx[3][3];
    for ( i=0; i<3; i++ ) for ( j=0; j<3; j++ ) mtx[i][j]=0;
    for ( i=0; i<3; i++ ) {
      for ( j=0; j<3; j++ ) {
        if ( j==i ) continue;
        if ( p[i]>q[i]&&p[j]<q[j] ) {
          mtx[i][j]=min ( p[i]-q[i],q[j]-p[j] );
          p[i]-=mtx[i][j]; p[j]+=mtx[i][j];
        }
      }
    }
    int tot=0;
    for(i=0;i<3;i++)for(j=0;j<3;j++)tot+=mtx[i][j];
    for(i=0;i<3;i++)for(j=0;j<3;j++)
			for(k=0;k<n&&mtx[i][j];k++)
				if(s[k]==('0'+i))mtx[i][j]--,s[k]=('0'+j);
		cout<<tot<<endl;
		cout<<s<<endl;
  }
  return 0;
}
