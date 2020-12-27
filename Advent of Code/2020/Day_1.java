import java.util.*;
import java.io.*;

public class Day_1 {

    static List<Integer> readIn() {
        List<Integer> values = new ArrayList<>();
        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        String line;

        while (!(line = in.nextLine()).isBlank()) {
            values.add(Integer.valueOf(line));
        }

        return values;
    }

    static List<Integer> values = readIn();

    static class PartOne {
        public static void main(String[] args) {

            for (int i = 0; i < values.size(); i++) {
                for (int j = i + 1; j < values.size(); j++) {
                    if (values.get(i) + values.get(j) == 2020) {
                        System.out.println(values.get(i) * values.get(j));
                        return;
                    }
                }
            }
        }
    }

    static class PartTwo {
        public static void main(String[] args) {

            for (int i = 0; i < values.size(); i++) {
                for (int j = i + 1; j < values.size(); j++) {
                    for (int k = j + 1; k < values.size(); k++) {
                        if (values.get(i) + values.get(j)  + values.get(k) == 2020) {
                            System.out.println(values.get(i) * values.get(j) * values.get(k));
                            return;
                        }
                    }
                }
            }
        }
    }

}
