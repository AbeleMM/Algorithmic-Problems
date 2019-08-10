import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Solution {
    private static char[] a;
    private static char[] b;
    private static int nr;

    public static void main(String[] args) {
        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int t = in.nextInt();
        for (int i = 1; i <= t; i++) {
            solve(in.next().toCharArray());
            System.out.println("Case #" + i + ": " + new String(a) + " " + new String(b));
        }
    }

    private static void solve(char[] n) {
        nr = 0;
        a = new char[n.length];
        b = new char[n.length];
        for (char c : n) {
            if (c == '4') {
                a[nr] = '3';
                b[nr] = '1';
            }
            else {
                a[nr] = n[nr];
                b[nr] = '0';
            }
            nr = nr + 1;
        }
    }
}
