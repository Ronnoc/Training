import java.io.BufferedInputStream;
import java.math.BigInteger;
import java.util.Scanner;

public class Main{
	public static void main(String[] arg) {
		Scanner cin = new Scanner(new BufferedInputStream(System.in));
		BigInteger six=BigInteger.valueOf(6);
		BigInteger five=BigInteger.valueOf(5);
		BigInteger [] ten = new BigInteger [2022];
		int i;
		ten[0]=BigInteger.valueOf(1);
		for(i=1;i<=2001;i++)
			ten[i]=ten[i-1].multiply(BigInteger.valueOf(10));
		for(i=2;i<=2001;i++){
			int k;
			BigInteger tptp=BigInteger.valueOf(0);
			for(k=0;k<10;k++){
				BigInteger temp=ten[i-1].multiply(BigInteger.valueOf(k)).add(six);
				if(temp.multiply(temp).mod(ten[i]).equals(temp)){
					tptp=BigInteger.valueOf(k);
					break;
				}
			}
			six=six.add(tptp.multiply(ten[i-1]));
		}
		for(i=2;i<=2001;i++){
			int k;
			BigInteger tptp=BigInteger.valueOf(0);
			for(k=0;k<10;k++){
				BigInteger temp=ten[i-1].multiply(BigInteger.valueOf(k)).add(five);
				if(temp.multiply(temp).mod(ten[i]).equals(temp)){
					tptp=BigInteger.valueOf(k);
					break;
				}
			}
			five=five.add(tptp.multiply(ten[i-1]));
		}
		System.out.println(six);
		System.out.println(five);
		cin.close();
	}
}
