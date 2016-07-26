import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Main {
    public static BigInteger getsqrt(BigInteger n) {
        if (n.compareTo(BigInteger.ZERO) <= 0) return n;
        BigInteger x, xx, txx;        xx = x = BigInteger.ZERO;
        for (int t = n.bitLength() / 2; t >= 0; t--) {
            txx = xx.add(x.shiftLeft(t + 1)).add(BigInteger.ONE.shiftLeft(t + t));
            if (txx.compareTo(n) <= 0) {
                x = x.add(BigInteger.ONE.shiftLeft(t));   xx = txx;
            }
        }
        return x;
    }
    public void Solve() throws IOException {
        BigInteger n=nextBigInteger();
        boolean flag=true;
        for(int i=0;i<=5;i++){
            if(n.equals(BigInteger.ONE)){
                writer.println(i);
                flag=false;
                break;
            }
            n=getsqrt(n);
        }
        if(flag)writer.println("TAT");
        writer.flush();
    }
    
    public static void main(String[] args) throws IOException {
        new Main().run();
    }
    
    BufferedReader reader;
    StringTokenizer tokenizer;
    PrintWriter writer;
    
    public void run() {
        try {
            reader = new BufferedReader(new InputStreamReader(System.in));
            writer = new PrintWriter(System.out);
            // reader = new BufferedReader(new InputStreamReader(new FileInputStream(".in")));
            // writer = new PrintWriter(new FileOutputStream(".out"));
            tokenizer = null;
            while(hasNext()){
                Solve();
            }
            reader.close();
            writer.flush();
            writer.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }
    
    boolean hasNext() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            String nextLine = reader.readLine();
            if (nextLine == null) return false;
            tokenizer = new StringTokenizer(nextLine);
        }
        return true;
    }
    
    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }
    
    long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }
    
    double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }
    
    BigInteger nextBigInteger() throws IOException {
        return new BigInteger(nextToken());
    }
    
    String nextLine() throws IOException {
        return reader.readLine();
    }
    
    String nextToken() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens())
            tokenizer = new StringTokenizer(reader.readLine());
        return tokenizer.nextToken();
    }
}