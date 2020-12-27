import java.util.*;
import java.io.*;

public class Day_11 {

    static char[][] readIn() {
        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));

        String line;
        List<char[]> charArrList = new ArrayList<>();

        while(!(line = in.nextLine()).isBlank()) {
            charArrList.add(line.toCharArray());
        }

        return charArrList.toArray(new char[charArrList.size()][]);
    }

    static char[][] mat = readIn();


    static int getRes(char[][] mat, boolean lookFar) {
        char[][] oldMat = new char[mat.length][mat[0].length];
        boolean chaos;

        int[] xDir = new int[]{-1, -1, -1, 0, 0, 1, 1, 1};
        int[] yDir = new int[]{-1, 0, 1, -1, 1, -1, 0, 1};

        do {
            chaos = false;
            for (int i = 0; i < mat.length; i++) {
                System.arraycopy(mat[i], 0, oldMat[i], 0, mat[i].length);
            }

            for (int i = 0; i < mat.length; i++) {
                for (int j = 0; j < mat[i].length; j++) {
                    int nrOccupied = 0;

                    for (int k = 0; k < xDir.length; k++) {
                        int x = i, y = j;
                        do {
                            x += xDir[k];
                            y += yDir[k];

                            if (x < 0 || x >= mat.length || y < 0 || y >= mat[i].length) {
                                break;
                            }
                            if (oldMat[x][y] == '#') {
                                nrOccupied++;
                            }
                        } while (lookFar && oldMat[x][y] == '.');
                    }

                    if (mat[i][j] == 'L' && nrOccupied == 0) {
                        chaos = true;
                        mat[i][j] = '#';
                    }
                    else if (mat[i][j] == '#' && nrOccupied > 3 + (lookFar ? 1 : 0)) {
                        chaos = true;
                        mat[i][j] = 'L';
                    }
                }
            }
        } while(chaos);

        int res = 0;
        for (char[] chars : mat) {
            for (char aChar : chars) {
                res += aChar == '#' ? 1 : 0;
            }
        }

        return res;
    }

    static class PartOne {
        public static void main(String[] args) {
            System.out.println(getRes(mat, false));
        }
    }

    static class PartTwo {
        public static void main(String[] args) {
            System.out.println(getRes(mat, true));
        }
    }

}
