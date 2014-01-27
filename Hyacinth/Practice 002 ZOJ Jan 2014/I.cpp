#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
int n,m;
int w[22][22];
int e[22];
int z[22];
int q[22][22];
int ff[22][22]= {{0},{1,1},{1,1},{1,2},{2,1,4},{2,2,5},{2,2,5},{3,1,4,7},{3,2,5,8},{3,2,5,8},{4,1,4,7,10}};
int main() {
  int i,j;
  while ( ~scanf( "%d%d",&n,&m ) ) {
    for ( i=1; i<=n; i++ )for ( j=1; j<=m; j++ )scanf( "%d",&w[i][j] );
    int mask;
    int ans=( n+1 )*( m+1 );
    memset( q,0,sizeof q );
    for ( mask=0; mask<1<<n; mask++ ) {
      int now=0;
      memset( e,0,sizeof e );
      for ( i=1; i<=n; i++ )e[i]=( mask<<1 )>>i&1;
      for ( i=1; i<=n; i++ )now+=e[i];
      for ( i=1; i<=n; i++ )q[i][1]=w[i][1]-e[i-1]-e[i]-e[i+1];
      for ( i=1; i<=n; i++ )if ( q[i][1]<0 )continue;
      if ( q[1][1]>2 )continue;
      if ( q[n][1]>2 )continue;
      int flag=0;
      for ( i=2; i<n; i++ )if ( q[i][1]>3 )flag=1;
      int ac=0;
      memset( e,0,sizeof e );
      for ( i=0; !ac&&i<( 1<<n ); i++ ) {
        for ( j=1; j<=n; j++ )e[j]=( i<<1 )>>j&1;
        for ( j=1; j<=n; j++ )z[j]=e[j-1]+e[j]+e[j+1];
        for ( j=1; j<=n; j++ )if ( z[j]!= q[j][1] )break;
        if ( j==n+1 )ac=1;
      }
//          if ( mask==1<<7 )cout<<"~"<<ac<<endl;
//          if(!ac){for ( j=1; j<=n; j++ )cout<<z[j]<<" ";cout<<endl;}
      if ( !ac )flag=1;
      for ( int r=2; !flag&&r<=m; r++ ) {
        if ( w[1][r]<q[1][r-1]||w[1][r]>q[1][r-1]+2 )flag=1;
        if ( w[n][r]<q[n][r-1]||w[n][r]>q[n][r-1]+2 )flag=1;
        for ( i=2; i<n; i++ )
          if ( w[i][r]<q[i][r-1]||w[i][r]>q[i][r-1]+3 )flag=1;
        if ( flag )break;
        for ( i=1; i<=n; i++ )q[i][r]=w[i][r]-q[i][r-1];
        if ( q[1][r]>2 )flag=1;
        if ( q[n][r]>2 )flag=1;
        for ( i=2; i<n; i++ )if ( q[i][r]>3 )flag=1;
        if ( !flag ) {
          int ac=0;
          memset( e,0,sizeof e );
          for ( i=0; !ac&&i<( 1<<n ); i++ ) {
            for ( j=1; j<=n; j++ )e[j]=( i<<1 )>>j&1;
            for ( j=1; j<=n; j++ )z[j]=e[j-1]+e[j]+e[j+1];
            for ( j=1; j<=n; j++ )if ( z[j]!= q[j][r] )break;
            if ( j==n+1 )ac=1;
          }
//          if ( mask==1<<7 )cout<<"~"<<ac<<endl;
//          if(!ac){for ( j=1; j<=n; j++ )cout<<z[j]<<" ";cout<<endl;}
          if ( !ac )flag=1;
        }
      }
      if ( flag )continue;
      for ( j=1; j<=m; j++ ) {
        int tt=ff[n][0];
        for ( i=1; i<=tt; i++ )now+=q[ff[n][i]][j];
      }
//      if ( now==4 )cout<<mask<<endl;
      ans=min( ans,now );
    }
    printf( "%d\n",ans );
  }
  return 0;
}
/*
10 4
1 3 3 1
2 5 4 1
1 4 4 1
1 4 4 1
1 4 5 2
1 4 5 2
2 4 4 1
1 3 4 1
2 4 4 1
1 3 3 1
*/
