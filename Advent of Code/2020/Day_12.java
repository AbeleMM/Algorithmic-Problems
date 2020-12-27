import java.util.*;
import java.io.*;

public class Day_12 {

    static Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));

    static class Coords {
        int N, E;
        char dir;

        public Coords(int n, int e, char dir) {
            N = n;
            E = e;
            this.dir = dir;
        }
    }

    static class PartOne {
        static List<Character> dirArr = Arrays.asList('N', 'E', 'S', 'W');

        static void doAction(Coords ship, char act, int len) {
            switch (act) {
                case 'E':
                    ship.E += len;
                    break;
                case 'N':
                    ship.N += len;
                    break;
                case 'W':
                    ship.E -= len;
                    break;
                case 'S':
                    ship.N -= len;
                    break;
                case 'F':
                    doAction(ship, ship.dir, len);
                    break;
                case 'L':
                    ship.dir = dirArr.get(Math.floorMod(dirArr.indexOf(ship.dir) - len / 90, dirArr.size()));
                    break;
                case 'R':
                    ship.dir = dirArr.get(Math.floorMod(dirArr.indexOf(ship.dir) + len / 90, dirArr.size()));
                    break;
            }
        }

        public static void main(String[] args) {
            Coords ship = new Coords(0, 0, 'E');

            String line;
            while (!(line = in.nextLine()).isBlank()) {
                doAction(ship, line.charAt(0), Integer.parseInt(line.substring(1)));
            }
            System.out.println(Math.abs(ship.N) + Math.abs(ship.E));
        }
    }

    static class PartTwo {
        public static void main(String[] args) {
            long shipN = 0, shipE = 0, wpN = 1, wpE = 10;

            String line;
            while (!(line = in.nextLine()).isBlank()) {
                char c = line.charAt(0);
                int len = Integer.parseInt(line.substring(1));

                switch (c) {
                    case 'N':
                        wpN += len;
                        break;
                    case 'E':
                        wpE += len;
                        break;
                    case 'S':
                        wpN -= len;
                        break;
                    case 'W':
                        wpE -= len;
                        break;
                    case 'F':
                        shipN += wpN * len;
                        shipE += wpE * len;
                        break;
                    // x - E, y - N
                    case 'L':
                        for (int i = 0; i < len / 90; i++) {
                            long aux = wpE;
                            wpE = -wpN;
                            wpN = aux;
                        }
                        break;
                    case 'R':
                        for (int i = 0; i < len / 90; i++) {
                            long aux = -wpE;
                            wpE = wpN;
                            wpN = aux;
                        }
                        break;
                }
            }

            System.out.println(Math.abs(shipN) + Math.abs(shipE));
        }
    }

}
