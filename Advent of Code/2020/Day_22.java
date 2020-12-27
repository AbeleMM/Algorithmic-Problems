import java.util.*;
import java.io.*;

public class Day_22 {

    static class DeckPair {
        LinkedList<Integer> p1, p2;

        public DeckPair(LinkedList<Integer> p1, LinkedList<Integer> p2) {
            this.p1 = p1;
            this.p2 = p2;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            DeckPair deckPair = (DeckPair) o;
            return p1.equals(deckPair.p1) &&
                    p2.equals(deckPair.p2);
        }

        @Override
        public int hashCode() {
            return Objects.hash(p1, p2);
        }
    }

    static DeckPair readIn() {
        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        String line;

        in.nextLine();
        LinkedList<Integer> p1 = new LinkedList<>();
        while (!(line = in.nextLine()).isBlank()) {
            p1.add(Integer.valueOf(line));
        }
        in.nextLine();
        LinkedList<Integer> p2 = new LinkedList<>();
        while (!(line = in.nextLine()).isBlank()) {
            p2.add(Integer.valueOf(line));
        }

        return new DeckPair(p1, p2);
    }

    static DeckPair pair = readIn();

    static int calcScore(Queue<Integer> deck) {
        int res = 0, ind = deck.size();
        for (Integer card : deck) {
            res += ind * card;
            ind--;
        }
        return res;
    }

    static class PartOne {
        public static void main(String[] args) {

            while(!pair.p1.isEmpty() && !pair.p2.isEmpty()) {
                //noinspection ConstantConditions
                int p1Card = pair.p1.poll(), p2Card = pair.p2.poll();

                if (p1Card > p2Card) {
                    pair.p1.add(p1Card);
                    pair.p1.add(p2Card);
                }
                else {
                    pair.p2.add(p2Card);
                    pair.p2.add(p1Card);
                }
            }

            System.out.println(calcScore(pair.p1) + calcScore(pair.p2));
        }
    }

    static class PartTwo {

        // If p1 wins, return -p1_score, else return p2_score
        static int playRecGame(DeckPair currPair) {
            Set<DeckPair> prevPairs = new HashSet<>();

            while (!currPair.p1.isEmpty() && !currPair.p2.isEmpty()) {
                if (prevPairs.contains(currPair)) {
                    return -calcScore(currPair.p1);
                }
                else {
                    prevPairs.add(new DeckPair(new LinkedList<>(currPair.p1), new LinkedList<>(currPair.p2)));
                    //noinspection ConstantConditions
                    int p1Card = currPair.p1.poll(), p2Card = currPair.p2.poll();

                    if (currPair.p1.size() >= p1Card  && currPair.p2.size() >= p2Card) {
                        LinkedList<Integer> newP1 = new LinkedList<>(), newP2 = new LinkedList<>();
                        Iterator<Integer> itP1 = currPair.p1.iterator(), itP2 = currPair.p2.iterator();

                        for (int i = 0; i < p1Card; i++) {
                            newP1.add(itP1.next());
                        }
                        for (int i = 0; i < p2Card; i++) {
                            newP2.add(itP2.next());
                        }

                        int res = playRecGame(new DeckPair(newP1, newP2));
                        if (res < 0) {
                            currPair.p1.add(p1Card);
                            currPair.p1.add(p2Card);
                        }
                        else {
                            currPair.p2.add(p2Card);
                            currPair.p2.add(p1Card);
                        }
                    }
                    else {
                        if (p1Card > p2Card) {
                            currPair.p1.add(p1Card);
                            currPair.p1.add(p2Card);
                        }
                        else {
                            currPair.p2.add(p2Card);
                            currPair.p2.add(p1Card);
                        }
                    }
                }
            }

            return -calcScore(currPair.p1) + calcScore(currPair.p2);
        }

        public static void main(String[] args) {
            int winnerScore = playRecGame(pair);

            System.out.println(winnerScore < 0 ? -winnerScore : winnerScore);
        }
    }

}
