import java.util.*;
import java.io.*;

public class Day_4 {

    static Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));

    static Map<String, String> getNext() {
        Map<String, String> res = new HashMap<>();

        String line;

        while (!(line = in.nextLine()).isBlank()) {
            for (String s : line.split(" ")) {
                String[] entry = s.split(":");
                res.put(entry[0], entry[1]);
            }
        }

        return res;
    }

    static int sol = 0;
    static Map<String, String> map;

    static class PartOne {
        public static void main(String[] args) {

            while (!(map = getNext()).isEmpty()) {
                if (map.containsKey("byr") && map.containsKey("iyr") && map.containsKey("eyr") &&
                        map.containsKey("hgt") && map.containsKey("hcl") && map.containsKey("ecl")
                        && map.containsKey("pid")) {
                    sol++;
                }
            }

            System.out.println(sol);
        }
    }

    static class PartTwo {
        public static void main(String[] args) {

            while (!(map = getNext()).isEmpty()) {
                try {
                    boolean ok;

                    ok = map.get("byr").matches("19[2-9]\\d|200[0-2]");
                    ok &= map.get("iyr").matches("201\\d|2020");
                    ok &= map.get("eyr").matches("202\\d|2030");
                    ok &= map.get("hgt").matches("1[5-8]\\dcm|19[0-3]cm|59in|6\\din|7[0-6]in");
                    ok &= map.get("hcl").matches("#[0-9a-f]{6}");
                    ok &= map.get("ecl").matches("amb|blu|brn|gry|grn|hzl|oth");
                    ok &= map.get("pid").matches("\\d{9}");

                    if (ok) {
                        sol++;
                    }
                }
                catch (NullPointerException ignored) {}
            }

            System.out.println(sol);
        }
    }

}
