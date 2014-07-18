import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.math.BigDecimal;
import java.util.Scanner;

public class Main {
	
	static StreamTokenizer	cin		= new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
	static PrintWriter			cout	= new PrintWriter(new OutputStreamWriter(System.out));
	
	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(System.in);
		String s;
		while (in.hasNext()) {
			s = in.next();
			BigDecimal e = BigDecimal.ONE;
			BigDecimal ans = BigDecimal.ZERO;
			for (int i = 2; i < s.length(); i++) {
				int x = s.charAt(i) - '0';
				e = e.divide(BigDecimal.valueOf(8));
				ans = ans.add(e.multiply(BigDecimal.valueOf(x)));
			}
			cout.println(s + " [8] = " + ans + " [10]");
		}
		in.close();
		cout.flush();
	}
	
	static int nextInt() throws IOException {
		cin.nextToken();
		return (int) cin.nval;
	}
}
