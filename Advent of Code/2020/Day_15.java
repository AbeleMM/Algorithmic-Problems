import java.util.*;
import java.io.*;

public class Day_15 {

    static int[] readIn() {
        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));

        String[] nrs = in.nextLine().split(",");
        int[] arr = new int[nrs.length];
        for (int i = 0; i < nrs.length; i++) {
            arr[i] = Integer.parseInt(nrs[i]);
        }

        return arr;
    }

    static int[] arr = readIn();

    static int solve(int[] arr, int target) {
        Map<Integer, Integer> lastMap = new HashMap<>();
        int count = 1, nr = 0, lastNr = arr[arr.length - 1];

        while (count <= arr.length) {
            lastMap.put(arr[count - 1], count);
            count++;
        }

        while (count <= target) {
            if (lastMap.containsKey(lastNr)) {
                nr = (count - 1) - lastMap.get(lastNr);
            }
            else {
                nr = 0;
            }
            lastMap.put(lastNr, count - 1);
            lastNr = nr;

            count++;
        }

        return nr;
    }

    static class PartOne {
        public static void main(String[] args) {
            System.out.println(solve(arr, 2020));
        }
    }

    static class PartTwo {
        public static void main(String[] args) {
            System.out.println(solve(arr, 30000000));
        }
    }

}
