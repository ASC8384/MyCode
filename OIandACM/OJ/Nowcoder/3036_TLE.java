import java.math.BigInteger;
import java.util.Scanner;
 
public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        BigInteger p, n, x, ans;
        int t = cin.nextInt();
        while (cin.hasNext()) {
            ans = new BigInteger("1");
            p = cin.nextBigInteger();
            n = cin.nextBigInteger();
            n = n.mod(p.subtract(ans));
            x = p.subtract(new BigInteger("1"));
            while (n.compareTo(new BigInteger("0")) > 0) {
                if (n.mod(BigInteger.valueOf(2)).compareTo(BigInteger.ONE) == 0) // if(n%2==1)
                    ans = ans.multiply(x).mod(p); // sq=(sq*p)%m;
                x = x.multiply(x).mod(p); // p=(p*p)%m;
                n = n.divide(BigInteger.valueOf(2));
            }
            System.out.println(ans);
        }
    }
}