#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int OFFL=0;
#ifndef ONLINE_JUDGE
	OFFL=1;
#endif
	int tt,dd,hh;
	double t,d,h;
	char c;
	while ( cin>>c )
	{
		tt=0,dd=0,hh=0;
		if ( c=='E' )
			break;
		if ( c=='T' )
			tt=1,cin>>t;
		if ( c=='D' )
			dd=1,cin>>d;
		if ( c=='H' )
			hh=1,cin>>h;
		cin>>c;
		if ( c=='T' )
			tt=1,cin>>t;
		if ( c=='D' )
			dd=1,cin>>d;
		if ( c=='H' )
			hh=1,cin>>h;
		if ( tt&&dd )
		{
			double e=6.11*exp( 5417.7530*( 1/273.16-1/( d+273.16 ) ) );
			double _h=0.5555*( e-10 );
			h=t+_h;
		}
		if ( hh&tt )
		{
			double _h=h-t;
			double e=_h/0.555+10;
			d=1/( 1/273.16-log( e/6.11 )/5417.7530 )-273.16;
		}
		if ( hh&&dd )
		{
			double e=6.11*exp( 5417.7530*( 1/273.16-1/( d+273.16 ) ) );
			double _h=0.5555*( e-10 );
			t=h-_h;
		}
		printf( "T %.1f D %.1f H %.1f\n",t,d,h );
	}
	return 0;
}
