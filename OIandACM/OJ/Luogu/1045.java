import java.util.*;
import java.math.*;

public class Main {
    public static BigInteger mod = BigInteger.TEN.pow(500);

    public static BigInteger qpow(BigInteger x, int t) {
        BigInteger ret = BigInteger.ONE;
        while (t > 0) {
            if ((t & 1) == 1)
                ret = ret.multiply(x).mod(mod);
            x = x.multiply(x).mod(mod);
            t >>= 1;
        }
        return ret;
    }

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int n = cin.nextInt();
        // BigInteger mod = BigInteger.TEN.pow(500);
        BigInteger s = BigInteger.valueOf(2).modPow(BigInteger.valueOf(n), mod).subtract(BigInteger.ONE);
        // BigInteger s = qpow(BigInteger.valueOf(2), n);
        System.out.println((int) (n * Math.log10(2)) + 1);
        // long startTime = System.currentTimeMillis();
        // for (int i = 1; i <= 12345; i++) {
        // // BigInteger ss = qpow(BigInteger.valueOf(n), n).subtract(BigInteger.ONE);
        // BigInteger ss = BigInteger.valueOf(n).modPow(BigInteger.valueOf(n),
        // mod).subtract(BigInteger.ONE);
        // }
        // long endTime = System.currentTimeMillis();
        // System.out.println((endTime - startTime) + "ms");

        String ans = s.toString();
        n = ans.length();

        int num = 500 - n;
        for (int i = 1; i <= num; i++) {
            System.out.printf("%d", 0);
            if (i % 50 == 0)
                System.out.println();
        }
        for (int i = num + 1; i <= 500; i++) {
            System.out.print(ans.charAt(i - 1 - num));
            if (i % 50 == 0)
                System.out.println();
        }
    }
}