import java.util.*;
import java.io.*;

public class Day_23 {
    static final int n = 9;

    static int[] readIn() {
        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        String line = in.nextLine();

        int[] arr = new int[n];
        for (int i = 0; i < arr.length; i++) {
            arr[i] = line.charAt(i) - '0';
        }
        return arr;
    }

    static int[] getLinks(int[] initLayout, int maxN) {
        int[] ret = new int[maxN + 1];
        int maxFound = Arrays.stream(initLayout).max().orElse(0);

        for (int i = 0; i < initLayout.length; i++) {
            ret[initLayout[i]] = initLayout[Math.floorMod(i + 1, initLayout.length)];
        }
        if (maxN > maxFound) {
            ret[initLayout[initLayout.length - 1]] = maxFound + 1;
            if (maxN - maxFound > 1) {
                ret[maxFound + 1] = maxFound + 2;
                for (int i = maxFound + 2; i < maxN; i++) {
                    ret[i] = i + 1;
                }
                ret[maxN] = initLayout[0];
            }
            else {
                ret[maxFound + 1] = initLayout[0];
            }
        }
        return ret;
    }

    // returns first cup (clockwise) after 1
    static int playRounds(int nrRounds, int[] links, int firstCup) {
        int maxN = links.length - 1, currCup = firstCup;

        for (int nr = 0; nr < nrRounds; nr++) {
            int pickedUp1 = links[currCup],
                    pickedUp2 = links[pickedUp1],
                    pickedUp3 = links[pickedUp2];

            int afterPickedUp = links[pickedUp3];
            links[currCup] = afterPickedUp;

            int dest = currCup > 1 ? currCup - 1 : maxN;
            while (pickedUp1 == dest || pickedUp2 == dest || pickedUp3 == dest) {
                dest = dest > 1 ? dest - 1 : maxN;
            }

            int afterDest = links[dest];
            links[dest] = pickedUp1;
            links[pickedUp3] = afterDest;

            currCup = links[currCup];
        }

        return links[1];
    }

    static class PartOne {
        static final int nrRounds = 100;
        public static void main(String[] args) {
            int[] arr = readIn();
            int[] links = getLinks(arr, n);
            int elem = playRounds(nrRounds, links, arr[0]);

            while (elem != 1) {
                System.out.print(elem);
                elem = links[elem];
            }
        }
    }

    static class PartTwo {
        static final int nrRounds = 10000000, maxN = 1000000;
        public static void main(String[] args) {
            int[] arr = readIn();
            int[] links = getLinks(arr, maxN);
            int elem = playRounds(nrRounds, links, arr[0]);

            System.out.println((long) elem * links[elem]);
        }
    }

}
