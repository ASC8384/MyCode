import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    static String str1 = null, str2 = null;
    static int n;
    static BigInteger a, b, c;
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            str1 = sc.next();
            str2 = sc.next();
            a = new BigInteger(str1);
            b = new BigInteger(str2);
            System.out.println(a.gcd(b));
        }
        // sc.close();
    }
}