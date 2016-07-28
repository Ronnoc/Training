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
    BigInteger modPow(BigInteger a,long m,long p){
        long x=a.mod(BigInteger.valueOf(p)).longValue();
        long ret=1;
        while(m>0){
            if(m%2==1)ret=ret*x%p;
            x=x*x%p;
            m/=2;
        }
        return BigInteger.valueOf(ret);
    }
    long fun(long a,long m,long x){
        if(a<0)return 0;
        long ret=a/m;
        a%=m;
        if(a>=x)ret++;
        return ret;
    }
    public void Solve() throws IOException {
        int T=nextInt();
        for(int CA=1;CA<=T;CA++){
            int n=nextInt();
            long le=nextLong();
            long re=nextLong();
            long []B=new long[n];
            long []M=new long[n];
            for(int i=0;i<n;i++){
                M[i]=nextLong();
                B[i]=nextLong();
            }
            long ans=0;
            for(int mask=0;mask<1<<n;mask++) {
                BigInteger x=BigInteger.valueOf(0);
                BigInteger m=BigInteger.valueOf(7);
                int cnt=0;
                for(int i=0;i<n;i++)if((mask>>i&1)==1) {
                    cnt++;
                    BigInteger a = m;
                    BigInteger b = BigInteger.valueOf(B[i]).subtract(x);
                    BigInteger t = b.multiply(modPow(a, M[i] - 2, M[i])).mod(BigInteger.valueOf(M[i]));
                    x = x.add(m.multiply(t));
                    m = m.multiply(BigInteger.valueOf(M[i]));
                    x = x.mod(m);
                }
                long now=0;
                if(m.compareTo(BigInteger.valueOf(re))>=0){
                    if(x.compareTo(BigInteger.valueOf(re))<=0)
                        if(x.compareTo(BigInteger.valueOf(le))>=0)
                            now=1;
                }else {
                    long tx=x.longValue();
                    long tm=m.longValue();
                    now=fun(re,tm,tx)-fun(le-1,tm,tx);
                }
                if(cnt%2==1)ans-=now;
                else ans+=now;
            }
            writer.println("Case #"+CA+": "+ans);
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
