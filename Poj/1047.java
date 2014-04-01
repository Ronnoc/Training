import java.io.*  ; 
import java.util.*; 
import java.math.*;
/*
Solution  for sgu
Main      for hdu,poj
*/
public class Main { 
    public static void main(String args[]){ 
        Scanner cin = new Scanner(new BufferedInputStream(System.in));
       	while(cin.hasNext()){
       		String s=cin.next();
       		char[] ss=s.toCharArray();
       		int len=ss.length;
       		BigInteger nine,ten;
       		ten=BigInteger.valueOf(10);
       		nine=BigInteger.valueOf(9);
       		BigInteger x,y;
       		x=BigInteger.valueOf(0);
       		y=BigInteger.valueOf(0);
       		for(int i=0;i<len;++i){
       			x=x.multiply(ten);
       			x=x.add(BigInteger.valueOf(ss[i]-'0'));
       			y=y.multiply(ten);
       			y=y.add(nine);
       			}
       		boolean flag=false;
       		if(x.multiply(BigInteger.valueOf(len+1)).compareTo(y)==0)flag=true;
       		if(flag)System.out.println(s+" is cyclic");
       		else System.out.println(s+" is not cyclic");
       		} 
        }
    }