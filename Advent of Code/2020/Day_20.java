import java.io.*;
import java.util.*;

public class Day_20 {
    static final int n = 10;

    static Map<Integer, char[][]> getIn() {
        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        Map<Integer, char[][]> map = new HashMap<>();
        String line;
        while (!(line = in.nextLine()).isBlank()) {
            int key = Integer.parseInt(line.replaceAll("\\D", ""));
            char[][] val = new char[n][];
            for (int i = 0; i < n; i++) {
                val[i] = in.nextLine().toCharArray();
            }
            map.put(key, val);
            in.nextLine();
        }
        return map;
    }

    static char[][] rotate(char[][] tile) {
        int n = tile.length, m = tile[0].length;
        char[][] res = new char[m][n];
        int newCol, newRow = 0;

        for (int oldCol = m - 1; oldCol >= 0; oldCol--) {
            newCol = 0;
            for (char[] chars : tile) {
                res[newRow][newCol] = chars[oldCol];
                newCol++;
            }
            newRow++;
        }

        return res;
    }

    static char[][] flip(char[][] tile) {
        int n = tile.length, m = tile[0].length;
        char[][] res = new char[n][m];

        for (int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                res[i][m - j - 1] = tile[i][j];
            }
        }

        return res;
    }

    static char[][][] getVariants(char[][] tile) {
        final int n = 8;
        char[][] lastVariant = tile;
        char[][][] variants = new char[n][][];
        variants[0] = lastVariant;

        for (int i = 1; i < n; i++) {
            if (i == n / 2) {
                lastVariant = flip(lastVariant);
            }
            else {
                lastVariant = rotate(lastVariant);
            }
            variants[i] = lastVariant;
        }

        return variants;
    }

    static Map<Integer, char[][]> map = getIn();

    // 0 - TOP, 1 - RIGHT, 2 - BOTTOM, 3 - LEFT
    static char[][] getBorders(char[][] tile) {
        int n = tile[0].length;
        char[][] borders = new char[4][n];

        for (int i = 0; i < n; i++) {
            borders[0][i] =tile[0][i];
            borders[1][i] = tile[i][n - 1];
            borders[2][i] = tile[n - 1][i];
            borders[3][i] = tile[i][0];
        }
        return borders;
    }

    static boolean check(char[] border, char[] otherBorder, boolean okReverse) {
        boolean ok = true;
        for (int i = 0; i < border.length && (ok || okReverse); i++) {
            if (ok && border[i] != otherBorder[i]) {
                ok = false;
            }
            if (okReverse && border[i] != otherBorder[otherBorder.length - 1 - i]) {
                okReverse = false;
            }
        }
        return ok || okReverse;
    }

    static boolean checkAny(char[][] one, char[][] other) {
        char[][] bordersOne = getBorders(one), bordersOther = getBorders(other);
        for (char[] border : bordersOne) {
            for (char[] borderOther : bordersOther) {
                if (check(border, borderOther, true)) {
                    return true;
                }
            }
        }
        return false;
    }

    static Map<Integer, List<Integer>> getNeighMap(Map<Integer, char[][]> map) {
        Map<Integer, List<Integer>> neighMap = new HashMap<>();

        for (Integer key : map.keySet()) {
            List<Integer> neighs = new ArrayList<>();
            for (Integer otherKey : map.keySet()) {
                if (!key.equals(otherKey)) {
                    if (checkAny(map.get(key), map.get(otherKey))) {
                        neighs.add(otherKey);
                    }
                }
            }
            neighMap.put(key, neighs);
        }

        return neighMap;
    }

    static Map<Integer, List<Integer>> neighMap = getNeighMap(map);

    static class PartOne {
        public static void main(String[] args) {
            long res = 1;
            for (Integer key : neighMap.keySet()) {
                res *= neighMap.get(key).size() == 2 ? key : 1;
            }
            System.out.println(res);
        }
    }

    static class PartTwo {
        static class Tile {
            int id;
            char[][] mat;

            public Tile(int id, char[][] mat) {
                this.id = id;
                this.mat = mat;
            }
        }

        enum Border {RGT, BOT}

        static char[][] getFit(char[][] one, char[][] other, Border border) {
            char[][][] variantsOther = getVariants(other);
            char[][] bordersOne = getBorders(one), bordersOther;

            for (char[][] variant : variantsOther) {
                bordersOther = getBorders(variant);
                if ((border == Border.RGT && check(bordersOne[1], bordersOther[3], false)) ||
                        (border == Border.BOT && check(bordersOne[2], bordersOther[0], false))) {
                    return variant;
                }
            }

            return null;
        }

        public static void main(String[] args) {
            int len = 1;
            while (len * len != map.size()) {
                len++;
            }
            Tile[][] img = new Tile[len][len];

            for (Integer key : neighMap.keySet()) {
                List<Integer> neighIds = neighMap.get(key);
                if (neighIds.size() == 2) {
                    char[][][] variants = getVariants(map.get(key));
                    for (char[][] variant : variants) {
                        char[][] neighOne = map.get(neighIds.get(0)),
                                neighOther = map.get(neighIds.get(1));
                        if (getFit(variant, neighOne, Border.RGT) != null &&
                            getFit(variant, neighOther, Border.BOT) != null) {
                            img[0][0] = new Tile(key, variant);
                            break;
                        }
                    }
                    break;
                }
            }

            for (int x = 1; x < len; x++) {
                // new last (right) column
                for (int i = 0; i < x; i++) {
                    List<Integer> lftNeighIds = neighMap.get(img[i][x - 1].id);
                    boolean found = false;
                    for (Iterator<Integer> it = lftNeighIds.iterator(); it.hasNext() && !found; ) {
                        Integer neighId = it.next();
                        char[][] neigh = map.get(neighId);
                        char[][] tmp = getFit(img[i][x - 1].mat, neigh, Border.RGT);
                        if (tmp != null) {
                            img[i][x] = new Tile(neighId, tmp);
                            found = true;
                        }
                    }
                }

                // new last (bottom) row
                for (int i = 0; i <= x; i++) {
                    List<Integer> topNeighIds = neighMap.get(img[x - 1][i].id);
                    boolean found = false;
                    for (Iterator<Integer> it = topNeighIds.iterator(); it.hasNext() && !found; ) {
                        Integer neighId = it.next();
                        char[][] neigh = map.get(neighId);
                        char[][] tmp = getFit(img[x - 1][i].mat, neigh, Border.BOT);
                        if (tmp != null) {
                            img[x][i] = new Tile(neighId, tmp);
                            found = true;
                        }
                    }
                }
            }

            char[][] stitched = new char[(n - 2) * len][(n - 2) * len];
            for (int imgV = 0; imgV < img.length; imgV++) {
                for (int imgH = 0; imgH < img[imgV].length; imgH++) {
                    char[][] mat = img[imgV][imgH].mat;
                    for (int i = 1; i < mat.length - 1; i++) {
                        System.arraycopy(mat[i], 1, stitched[imgV * (n - 2) + i - 1],
                                imgH * 8 + 1 - 1, mat[i].length - 1 - 1);
                    }
                }
            }

            final char[][] monster = new char[][]{
                    "                  # ".toCharArray(),
                    "#    ##    ##    ###".toCharArray(),
                    " #  #  #  #  #  #   ".toCharArray()
            };
            int initCount = 0, monsterChars = 0;
            for (char[] chars : monster) {
                for (char aChar : chars) {
                    monsterChars += aChar == '#' ? 1 : 0;
                }
            }
            for (char[] chars : stitched) {
                for (char aChar : chars) {
                    initCount += aChar == '#' ? 1 : 0;
                }
            }

            for (char[][] monsterVariant : getVariants(monster)) {
                int monsterCount = 0;

                for (int i = 0; i < stitched.length - monsterVariant.length; i++) {
                    for (int j = 0; j < stitched[i].length - monsterVariant[0].length; j++) {
                        boolean ok = true;
                        for (int k = 0; k < monsterVariant.length && ok; k++) {
                            for (int l = 0; l < monsterVariant[k].length && ok; l++) {
                                if (monsterVariant[k][l] == '#') {
                                    ok = stitched[i + k][j + l ] == monsterVariant[k][l];
                                }
                            }
                        }
                        monsterCount += ok ? 1 : 0;
                    }
                }

                if (monsterCount > 0) {
                    System.out.println(initCount - monsterChars * monsterCount);
                    return;
                }
            }
        }
    }

}
