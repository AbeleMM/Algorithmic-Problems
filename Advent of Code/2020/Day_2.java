import java.util.*;
import java.io.*;

public class Day_2 {

    static class Policy {
        int min, max;
        char letter;
        String pwd;

        public Policy(int min, int max, char letter, String pwd) {
            this.min = min;
            this.max = max;
            this.letter = letter;
            this.pwd = pwd;
        }
    }

    static Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));

    static Policy readNext() {
        String line;

        if (!(line = in.nextLine()).isBlank()) {
            String[] lineItems = line.split("[- :]+");

            return new Policy(
                    Integer.parseInt(lineItems[0]),
                    Integer.parseInt(lineItems[1]),
                    lineItems[2].charAt(0),
                    lineItems[3]
            );
        }

        return null;
    }

    static Policy policy;
    static int sol = 0;

    static class PartOne {
        public static void main(String[] args) {

            while ((policy = readNext()) != null) {
                int count = 0;

                for (int i = 0; i < policy.pwd.length(); i++) {
                    if (policy.pwd.charAt(i) == policy.letter) {
                        count++;
                    }
                }

                if (policy.min <= count && count <= policy.max) {
                    sol++;
                }
            }

            System.out.println(sol);
        }
    }

    static class PartTwo {
        public static void main(String[] args) {

            while ((policy = readNext()) != null) {
                if (policy.pwd.charAt(policy.min - 1) == policy.letter ^
                        policy.pwd.charAt(policy.max - 1) == policy.letter) {
                    sol++;
                }
            }

            System.out.println(sol);
        }
    }

}
