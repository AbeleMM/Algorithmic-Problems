import java.util.*;
import java.io.*;

public class Day_17 {

    static class Pos {
        int x, y, z,w;

        public Pos(int x, int y, int z, int w) {
            this.x = x;
            this.y = y;
            this.z = z;
            this.w = w;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Pos pos = (Pos) o;
            return x == pos.x &&
                    y == pos.y &&
                    z == pos.z &&
                    w == pos.w;
        }

        @Override
        public int hashCode() {
            return Objects.hash(x, y, z, w);
        }
    }

    static Set<Pos> readIn() {
        Set<Pos> set = new HashSet<>();

        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        String line;
        int x = 0;
        while (!(line = in.nextLine()).isBlank()) {
            char[] lineArr = line.toCharArray();
            for (int i = 0; i < lineArr.length; i++) {
                if (lineArr[i] == '#') {
                    set.add(new Pos(x, i, 0, 0));
                }
            }
            x++;
        }

        return set;
    }

    static int solve(Set<Pos> active, boolean fourD) {
        Set<Pos> oldActive = new HashSet<>();

        for (int it = 0; it < 6; it++) {
            oldActive.clear();
            for (Pos pos : active) {
                oldActive.add(new Pos(pos.x, pos.y, pos.z, pos.w));
            }

            for (Pos t : oldActive) {
                Set<Pos> neighbours = getNeighbours(t, fourD);

                int nr = 0;
                for (Pos neighbour : neighbours) {
                    if (oldActive.contains(neighbour)) {
                        nr++;
                    }
                    else {

                        Set<Pos> otherNeighbours = getNeighbours(neighbour, fourD);
                        int otherNr = 0;
                        for (Pos otherNeighbour: otherNeighbours) {
                            if (oldActive.contains(otherNeighbour)) {
                                otherNr++;
                            }
                        }
                        if (otherNr == 3) {
                            active.add(neighbour);
                        }

                    }
                }
                if (nr < 2 || nr > 3) {
                    active.remove(t);
                }

            }
        }

        return active.size();
    }

    private static Set<Pos> getNeighbours(Pos t, boolean fourD) {
        Set<Pos> res = new HashSet<>();
        for (int i = t.x - 1; i < t.x + 2; i++) {
            for (int j = t.y - 1; j < t.y + 2; j++) {
                for (int k = t.z - 1; k < t.z + 2; k++) {

                    if (fourD) {
                        for (int l = t.w - 1; l < t.w + 2; l++) {
                            if (i != t.x || j != t.y || k != t.z || l != t.w) {
                                res.add(new Pos(i, j, k, l));
                            }
                        }
                    }
                    else {
                        if (i != t.x || j != t.y || k != t.z) {
                            res.add(new Pos(i, j, k, 0));
                        }
                    }

                }
            }
        }
        return res;
    }

    static class PartOne {
        public static void main(String[] args) {
            Set<Pos> active = readIn();
            System.out.println(solve(active, false));
        }
    }

    static class PartTwo {
        public static void main(String[] args) {
            Set<Pos> active = readIn();
            System.out.println(solve(active, true));
        }
    }

}
