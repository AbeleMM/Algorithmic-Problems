import java.util.*;
import java.io.*;

public class Day_10 {

    static List<Integer> readIn() {
        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        in.useDelimiter("\n");
        List<Integer> values = new ArrayList<>();

        while (in.hasNextInt()) {
            values.add(in.nextInt());
        }
        Collections.sort(values);
        return values;
    }

    static List<Integer> in = readIn();

    static class PartOne {
        public static void main(String[] args) {
            int nrOne = 1, nrThree = 1;

            for (int i = 1; i < in.size(); i++) {
                int diff = in.get(i) - in.get(i - 1);
                if (diff == 1) {
                    nrOne++;
                }
                if (diff == 3) {
                    nrThree++;
                }
            }

            System.out.println(nrOne * nrThree);
        }
    }

    static class PartTwo {
        public static void main(String[] args) {
            long[][] mat = new long[in.size()][in.size()];

            for (int i = 0; i < in.size(); i++) {
                if (in.get(i) < 4) {
                    mat[i][0] = 1;
                }

                for (int j = i - 1; j >= 0 && in.get(i) - in.get(j) < 4; j--) {
                    for (int k = 0; k <= j; k++) {
                        mat[i][k + 1] += mat[j][k];
                    }
                }
            }

            long sum = 0;
            for (int i = 0; i < in.size(); i++) {
                sum += mat[in.size() - 1][i];
            }

            System.out.println(sum);
        }
    }

}
