import java.io.*;
import java.util.*;
import java.math.*;

public class Solution {
	public static void main(String args[]) {
		Scanner cin = new Scanner(new BufferedInputStream(System.in));
		while(cin.hasNext()){
			BigInteger l,r,mid,aim,ans;
			BigInteger z,x,c;
			aim=cin.nextBigInteger();
			r=aim;
			l=BigInteger.valueOf(0);
			ans=r;
			while(r.compareTo(l)>0){
				z=r.subtract(l);
				if(z.compareTo(BigInteger.ONE)<=0){
					x=r.multiply(r);
					if(x.compareTo(aim)<=0)
						ans=r;
					else ans=l;
					break;
				}
				mid=(l.add(r)).shiftRight(1);
				x=mid.multiply(mid);
				if(x.compareTo(aim)<=0)l=mid;
				else r=mid;
			}
			System.out.println(ans);
		}
	}
}