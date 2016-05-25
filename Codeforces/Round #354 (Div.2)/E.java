import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Main {
    public void Solve() throws IOException {
        int n = nextInt();
        int k = nextInt();
        int[] a = new int[n + 1];
        boolean[] is = new boolean[n + 1];
        int cnt = 0;
        for (int i = 0; i <= n; i++) {
            String s = nextToken();
            if (s.charAt(0) == '?') {
                is[i] = false;
            } else {
                is[i] = true;
                a[i] = Integer.parseInt(s);
                cnt++;
            }
        }
        if (cnt == n + 1) {
            BigInteger tp=BigInteger.ONE;
            boolean allzero=true;
            for(int t=1;t<=20;t++){
                BigInteger mod=tp.add(BigInteger.valueOf(7));
                BigInteger tmp = BigInteger.valueOf(a[n]);
                for (int i = n - 1; i >= 0; i--) {
                    BigInteger next = BigInteger.valueOf(a[i]).add(tmp.multiply(BigInteger.valueOf(k)));
                    tmp = next.mod(mod);
                }
                if(!tmp.equals(BigInteger.ZERO)){
                    allzero=false;
                    break;
                }
                tp=tp.multiply(BigInteger.TEN);
            }
            if (allzero)
                writer.println("Yes");
            else writer.println("No");
        } else {
            if (k == 0) {
                if (is[0]) {
                    if (a[0] == 0) writer.println("Yes");
                    else writer.println("No");
                } else {
                    if (cnt % 2 == 0)
                        writer.println("No");
                    else writer.println("Yes");
                }
            } else {
                if (n % 2 == 0) {
                    writer.println("No");
                } else writer.println("Yes");
            }
        }
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
            while (hasNext()) Solve();
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
