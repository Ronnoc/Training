import java.io.*;
import java.util.*;
import java.math.*;
public class Solution {
	public static BigInteger f(BigInteger a){
		if(a.compareTo(BigInteger.valueOf(10))<0)return a;
		BigInteger tp=BigInteger.valueOf(0);
	//	System.out.println("f("+a+") ::");
		while(a.compareTo(BigInteger.valueOf(0))>0){
			tp=tp.add(a.mod(BigInteger.valueOf(10)));
	//		System.out.print(a.mod(BigInteger.valueOf(10)));
			a=a.divide(BigInteger.valueOf(10));
		}
	//	System.out.println("goto f("+a+")");
		return f(tp);
	}
	public static void main(String args[]){
	Scanner cin = new Scanner(new BufferedInputStream(System.in));
	int t=cin.nextInt();
	while(t>0){
		int n=cin.nextInt();
		int a[]=new int[1010];
		int i;
		for(i=0;i<n;i++)a[i]=cin.nextInt();
		BigInteger b,res;
		BigInteger one=BigInteger.valueOf(1),ten=BigInteger.valueOf(10),zero=BigInteger.valueOf(0);
		b=one;res=zero;
		for(i=0;i<n;++i){
			b=b.multiply(BigInteger.valueOf(a[i]));
			b=f(b);
			res=res.add(b);
		//	System.out.println(b+" "+f(b));
			}
		System.out.println(f(res));
		t--;
		}
	}
}