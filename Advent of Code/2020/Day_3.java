import java.util.*;
import java.io.*;

public class Day_3 {

    static Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
    static String line;


    static class PartOne {
        public static void main(String[] args) {

            int pos = 0, trees = 0;

            while (!(line = in.nextLine()).isBlank()) {
                if (line.charAt(pos) == '#') {
                    trees++;
                }
                pos = (pos + 3) % line.length();
            }

            System.out.println(trees);
        }
    }

    static class PartTwo {
        public static void main(String[] args) {

            int pos1 = 0, pos3 = 0, pos5 = 0, pos7 = 0, pos1_2 = 0;
            long trees1 = 0, trees3 = 0, trees5 = 0, trees7 = 0, trees1_2 = 0;
            boolean even = true;

            while (!(line = in.nextLine()).isBlank()) {
                trees1 += line.charAt(pos1) == '#' ? 1 : 0;
                trees3 += line.charAt(pos3) == '#' ? 1 : 0;
                trees5 += line.charAt(pos5) == '#' ? 1 : 0;
                trees7 += line.charAt(pos7) == '#' ? 1 : 0;

                pos1 = (pos1 + 1) % line.length();
                pos3 = (pos3 + 3) % line.length();
                pos5 = (pos5 + 5) % line.length();
                pos7 = (pos7 + 7) % line.length();

                if (even) {
                    trees1_2 += line.charAt(pos1_2) == '#' ? 1 : 0;
                    pos1_2 = (pos1_2 + 1) % line.length();
                }
                even = !even;
            }

            System.out.println(trees1 * trees3 * trees5 * trees7 * trees1_2);
        }
    }

}
