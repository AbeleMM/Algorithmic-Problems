import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Day_24 {

    static class Tile {
        int v, h;

        public Tile(int v, int h) {
            this.v = v;
            this.h = h;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Tile tile = (Tile) o;
            return v == tile.v &&
                    h == tile.h;
        }

        @Override
        public int hashCode() {
            return Objects.hash(v, h);
        }
    }

    static Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));

    static Set<Tile> getBlackTiles() {
        String line;
        Set<Tile> blackTiles = new HashSet<>();

        while (!(line = in.nextLine()).isBlank()) {
            int vDir = 0, hDir = 0;
            int i = 0;
            while (i < line.length()) {
                switch (line.charAt(i)) {
                    case 'n':
                        vDir--;
                        i++;
                        hDir += line.charAt(i) == 'e' ? 1 : -1;
                        break;
                    case 'e':
                        hDir += 2;
                        break;
                    case 's':
                        vDir++;
                        i++;
                        hDir += line.charAt(i) == 'e' ? 1 : -1;
                        break;
                    case 'w':
                        hDir -= 2;
                        break;
                }
                i++;
            }

            Tile tile = new Tile(vDir, hDir);
            if (blackTiles.contains(tile)) {
                blackTiles.remove(tile);
            }
            else {
                blackTiles.add(tile);
            }
        }

        return blackTiles;
    }

    static class PartOne {
        public static void main(String[] args) {
            Set<Tile> blackTiles = getBlackTiles();
            System.out.println(blackTiles.size());
        }
    }

    static class PartTwo {
        static Set<Tile> getNeighbours(Tile tile) {
            return new HashSet<>(Arrays.asList(
                    new Tile(tile.v - 1, tile.h - 1),
                    new Tile(tile.v - 1, tile.h + 1),
                    new Tile(tile.v, tile.h - 2),
                    new Tile(tile.v, tile.h + 2),
                    new Tile(tile.v + 1, tile.h - 1),
                    new Tile(tile.v + 1, tile.h + 1)
            ));
        }

        static int countBlackTiles(Set<Tile> tiles, Set<Tile> blackTiles) {
            int res = 0;
            for (Tile tile : tiles) {
                res += blackTiles.contains(tile) ? 1 : 0;
            }
            return res;
        }

        public static void main(String[] args) {
            Set<Tile> blackTiles = getBlackTiles(), newBlackTiles;

            for (int it = 0; it < 100; it++) {
                newBlackTiles = new HashSet<>();

                for (Tile t : blackTiles) {
                    Set<Tile> neighbours = getNeighbours(t);
                    long nrBlackNeighbours = countBlackTiles(neighbours, blackTiles);

                    if (nrBlackNeighbours != 0 && nrBlackNeighbours <= 2) {
                        newBlackTiles.add(t);
                    }

                    for (Tile neighbour : neighbours) {
                        if (!blackTiles.contains(neighbour)) {
                            nrBlackNeighbours = countBlackTiles(getNeighbours(neighbour), blackTiles);

                            if (nrBlackNeighbours == 2) {
                                newBlackTiles.add(neighbour);
                            }
                        }
                    }
                }

                blackTiles = newBlackTiles;
            }

            System.out.println(blackTiles.size());
        }
    }

}
