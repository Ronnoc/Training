//kybconnor
import java.io.BufferedInputStream;
import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main (String[] arg) {
		Scanner cin = new Scanner (new BufferedInputStream (System.in));
		BigInteger fz[]=new BigInteger [511];
		BigInteger fm[]=new BigInteger [511];
		fz[1]=BigInteger.valueOf (1);
		fm[1]=BigInteger.valueOf (2);
		int i;
		for (i=2; i<=500; i++) {
			fz[i]=fz[i-1].multiply (BigInteger.valueOf (2*i-1));
			fm[i]=fm[i-1].multiply (BigInteger.valueOf (2*i));
			BigInteger G=fz[i].gcd (fm[i]);
			fz[i]=fz[i].divide (G);
			fm[i]=fm[i].divide (G);
		}
		int T=cin.nextInt();
		for (int t=1; t<=T; t++) {
			int n=cin.nextInt();
			System.out.println (fz[n]+"/"+fm[n]);
		}
		cin.close();
	}
}
