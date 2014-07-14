import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	
	static StreamTokenizer	cin		= new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
	static PrintWriter			cout	= new PrintWriter(new OutputStreamWriter(System.out));
	
	private static Boolean isprime(int x) {
		if (x <= 1) return false;
		for (int i = 2; i * i <= x; i++)
			if (x % i == 0) return false;
		return true;
	}
	
	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(System.in);
		
		while (in.hasNext()) {
			BigInteger a = in.nextBigInteger();
			BigInteger b = BigInteger.ONE;
			int i = 2;
			while (b.multiply(BigInteger.valueOf(i)).compareTo(a) <= 0) {
				b = b.multiply(BigInteger.valueOf(i));
				for (i++; !isprime(i); i++);
			}
			System.out.println(b);
		}
		in.close();
		cout.flush();
	}
	
	static int nextInt() throws IOException {
		cin.nextToken();
		return (int) cin.nval;
	}
}
