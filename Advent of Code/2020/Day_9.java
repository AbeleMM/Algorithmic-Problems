import java.util.*;
import java.io.*;

public class Day_9 {

    static List<Long> readIn() {
        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        List<Long> values = new ArrayList<>();
        in.useDelimiter("\n");

        while (in.hasNextLong()) {
            values.add(in.nextLong());
        }

        return values;
    }

    static List<Long> list = readIn();

    static long getInvalid(List<Long> list) {
        final int nrPrev = 25;

        for (int i = nrPrev; i < list.size(); i++) {
            boolean ok = false;
            for (int j = i - nrPrev; j < i && !ok; j++) {
                for (int k = j + 1; k < i; k++) {
                    if (list.get(i) == list.get(j) + list.get(k)) {
                        ok = true;
                        break;
                    }
                }
            }
            if (!ok) {
                return list.get(i);
            }
        }

        return -1;
    }

    static class PartOne {
        public static void main(String[] args) {
            System.out.println(getInvalid(list));
        }
    }

    static class PartTwo {
        public static void main(String[] args) {
            long invalid = getInvalid(list);

            long currSum = list.get(0) + list.get(1);
            int l = 0, r = 2;

            while (currSum != invalid || r - l <= 1) {
                if (currSum > invalid) {
                    currSum -= list.get(l);
                    l++;

                }
                else {
                    currSum += list.get(r);
                    r++;
                }
            }

            long mn = Long.MAX_VALUE, mx = Long.MIN_VALUE;
            for (int i = l; i < r; i++) {
                mn = list.get(i) < mn ? list.get(i) : mn;
                mx = list.get(i) > mx ? list.get(i) : mx;
            }

            System.out.println(mn + mx);
        }
    }

}
