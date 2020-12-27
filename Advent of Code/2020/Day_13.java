import java.util.*;
import java.io.*;

public class Day_13 {

    static Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));

    static int ts;
    static List<Integer> busses = new ArrayList<>();

    static void readIn() {
        ts = Integer.parseInt(in.nextLine());
        String[] lineItems = in.nextLine().split(",");
        for (String s : lineItems) {
            if (!s.equals("x")) {
                busses.add(Integer.valueOf(s));
            }
            else {
                busses.add(-1);
            }
        }
    }

    static class PartOne {
        public static void main(String[] args) {
            readIn();
            int busId = 0, nrMin = Integer.MAX_VALUE;

            for (Integer bus : busses) {
                if (bus != -1) {
                    int departTime = (ts / bus + (ts % bus != 0 ? 1 : 0)) * bus;
                    if (departTime < nrMin) {
                        nrMin = departTime;
                        busId = bus;
                    }
                }
            }

            System.out.println(busId * (nrMin - ts));
        }
    }

    static class PartTwo {
        public static void main(String[] args) {
            readIn();

            // Chinese Remainder Theorem
            long busProduct = 1, ans = 0;
            for (Integer bus : busses) {
                if (bus != -1) {
                    busProduct *= bus;
                }
            }

            for (int i = 0; i < busses.size(); i++) {
                int bus = busses.get(i);
                if (bus != -1) {
                    long nI = busProduct / bus;
                    long xI = 0;
                    while ((nI * xI) % bus != 1) {
                        xI++;
                    }

                    ans = (ans + Math.floorMod(bus - i, bus) * nI * xI) % busProduct;
                }
            }

            System.out.println(ans);
        }
    }

}
