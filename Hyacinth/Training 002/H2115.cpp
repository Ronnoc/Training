#include <cstdio>
#include <iostream>
long long extgcd( long long a,long long b,long long &x,long long &y ) {
  long long ret=a;
  if ( b ) {
    ret=extgcd( b,a%b,y,x );
    y-=( a/b )*x;
  } else x=1LL,y=0LL;
  return ret;
}
int main() {
  long long a,b,c,k;
  while ( ~scanf( "%I64d%I64d%I64d%I64d",&a,&b,&c,&k ) ) {
    if ( !a&&!b&&!c&&!k )break;
    long long x,y;
    long long z=extgcd( c,1LL<<k,x,y );
    long long tp=( b-a )/z;
    if ( tp*z==( b-a ) ) {
      long long t=x;
      t*=tp;
      long long mod = ( 1LL<<k )/z;
      t%=mod;
      t+=mod;
      t%=mod;
      printf( "%I64d\n",t );
    } else printf( "FOREVER\n" );
  }
  return 0;
}
