import java.io.IOException;
import java.math.BigInteger;

public class Main {
    BigInteger []x=new BigInteger[5000];
    BigInteger []y=new BigInteger[5000];
    BigInteger []P=new BigInteger[5000];
    BigInteger []Q=new BigInteger[5000];
    BigInteger []A=new BigInteger[5000];
    BigInteger Pell(long d){
        long rt=(long)Math.sqrt((double)d);
        P[0]=BigInteger.ZERO;Q[0]=BigInteger.ONE;
        A[0]=BigInteger.valueOf(rt);
        x[0]=BigInteger.ONE;x[1]=BigInteger.valueOf(rt);
        y[0]=BigInteger.ZERO;y[1]=BigInteger.ONE;
        for(int i=1;;i++){
            //System.out.println(x[i]+" "+y[i]);
            BigInteger fun=x[i].multiply(x[i])
                    .subtract(BigInteger.valueOf(d).multiply(y[i]).multiply(y[i]))
                    .subtract(BigInteger.ONE);
            if(fun.equals(BigInteger.ZERO))
                return x[i];
            P[i]=A[i-1].multiply(Q[i-1]).subtract(P[i-1]);
            Q[i]=BigInteger.valueOf(d).subtract(P[i].multiply(P[i])).divide(Q[i-1]);
            A[i]=P[i].add(BigInteger.valueOf(rt)).divide(Q[i]);
            x[i+1]=x[i].multiply(A[i]).add(x[i-1]);
            y[i+1]=y[i].multiply(A[i]).add(y[i-1]);
        }
    }
    void run(){
    }
    public static void main(String[] args) throws IOException {
        new Main().run();
    }
}
