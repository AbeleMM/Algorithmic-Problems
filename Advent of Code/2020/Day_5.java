import java.util.*;
import java.io.*;

public class Day_5 {

    static Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));

    static class Seat {
        int row, column;

        public Seat(int row, int column) {
            this.row = row;
            this.column = column;
        }
    }

    static Seat getNext() {
        String line = in.nextLine();

        if (!line.isBlank()) {
            line = line.replace('F','0');
            line = line.replace('B', '1');
            line = line.replace('L', '0');
            line = line.replace('R', '1');
            return new Seat(Integer.parseInt(line.substring(0,7), 2), Integer.parseInt(line.substring(7), 2));
        }

        return null;
    }

    static int max = 0;
    static Seat seat;

    static class PartOne {
        public static void main(String[] args) {

            while ((seat = getNext()) != null) {
                max = Integer.max(max, seat.row * 8 + seat.column);
            }

            System.out.println(max);
        }
    }

    static class PartTwo {
        public static void main(String[] args) {
            int min = 127 * 8 + 7;
            HashSet<Integer> seatSet = new HashSet<>();

            while ((seat = getNext()) != null) {
                int seatId = seat.row * 8 + seat.column;
                min = Integer.min(min, seatId);
                max = Integer.max(max, seatId);
                seatSet.add(seatId);
            }

            for (int i = min; i <= max; i++) {
                if (!seatSet.contains(i)) {
                    System.out.println(i);
                    break;
                }
            }
        }
    }

}
