import java.util.*;
import java.io.*;
import java.util.stream.Collectors;

public class Day_6 {

    static Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));

    static Collection<Character> stringToCollection(String s) {
        return s.chars().mapToObj(c -> (char) c).collect(Collectors.toList());
    }

    static int sum = 0;
    static String line;
    static Set<Character> groupAns = new HashSet<>();

    static class PartOne {
        public static void main(String[] args) {

            do {
                groupAns.clear();
                while (!(line = in.nextLine()).isBlank()) {
                    groupAns.addAll(stringToCollection(line));
                }

                sum += groupAns.size();
            } while (!groupAns.isEmpty());

            System.out.println(sum);
        }
    }

    static class PartTwo {
        public static void main(String[] args) {
            Set<Character> personAns = new HashSet<>();

            while (!(line = in.nextLine()).isBlank()) {
                groupAns.clear();
                groupAns.addAll(stringToCollection(line));

                while (!(line = in.nextLine()).isBlank()) {
                    personAns.clear();
                    personAns.addAll(stringToCollection(line));
                    groupAns.retainAll(personAns);
                }

                sum += groupAns.size();
            }

            System.out.println(sum);
        }
    }

}
