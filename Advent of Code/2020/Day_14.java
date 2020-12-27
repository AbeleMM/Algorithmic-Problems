import java.util.*;
import java.io.*;

public class Day_14 {

    static Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));

    static String mask;
    static Map<Long, Long> mem = new HashMap<>();
    static long loc, val;

    static StringBuilder nrToBinPadded(long nr) {
        StringBuilder ret = new StringBuilder(Long.toBinaryString(nr));
        while (ret.length() != 36) {
            ret.insert(0, '0');
        }
        return ret;
    }

    static long solve(Runnable runnable) {
        String line;
        while (!(line = in.nextLine()).isBlank()) {
            if (line.matches("mask = \\S{36}")) {
                mask = line.substring(7);
            }
            else {
                line = line.replaceAll("[^\\d|=]","");
                int indexOfEq = line.indexOf('=');
                loc = Long.parseLong(line.substring(0, indexOfEq));
                val = Long.parseLong(line.substring(indexOfEq + 1));
                runnable.run();
            }
        }

        long res = 0;
        for (Long val : mem.values()) {
            res += val;
        }

        return res;
    }

    static class PartOne {
        public static void main(String[] args) {
            System.out.println(solve(() -> {
                StringBuilder valBin = nrToBinPadded(val);

                StringBuilder finalValBin = new StringBuilder();

                for (int i = 0; i < 36; i++) {
                    finalValBin.append(mask.charAt(i) == 'X' ? valBin.charAt(i) : mask.charAt(i));
                }

                mem.put(loc, Long.valueOf(finalValBin.toString(), 2));
            }));
        }
    }

    static class PartTwo {
        static void fillFloating(StringBuilder locBin, int ind, long val) {
            if (ind == locBin.length()) {
                mem.put(Long.valueOf(locBin.toString(), 2), val);
            }
            else if (locBin.charAt(ind) == 'X') {
                StringBuilder newStrBuilder = new StringBuilder(locBin);
                newStrBuilder.setCharAt(ind, '1');
                fillFloating(newStrBuilder, ind + 1, val);
                newStrBuilder.setCharAt(ind, '0');
                fillFloating(newStrBuilder, ind + 1, val);
            }
            else {
                fillFloating(locBin, ind + 1, val);
            }
        }

        public static void main(String[] args) {
            System.out.println(solve(() -> {
                StringBuilder locBin = nrToBinPadded(loc);

                StringBuilder finalLocBin = new StringBuilder();

                for (int i = 0; i < 36; i++) {
                    finalLocBin.append(mask.charAt(i) == '0' ? locBin.charAt(i) : mask.charAt(i));
                }
                fillFloating(finalLocBin, 0, val);
            }));
        }
    }

}
