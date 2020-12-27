import java.util.*;
import java.io.*;

public class Day_25 {

    static long cardPubKey, doorPubKey;
    static final long defaultSubjectNr = 7, mod = 20201227;

    static void getPKs() {
        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        cardPubKey = in.nextLong();
        doorPubKey = in.nextLong();
        in.close();
    }

    static long calcLoopSize(long pk) {
        long val = 1, loopSize = 0;

        while (val != pk) {
            val *= defaultSubjectNr;
            val %= mod;
            loopSize++;
        }

        return loopSize;
    }

    static long calcEncryptionKey(long subjectNr, long loopSize) {
        long val = 1;
        for (long i = 0; i < loopSize; i++) {
            val *= subjectNr;
            val %= mod;
        }

        return val;
    }

    static class PartOne {
        public static void main(String[] args) {
            getPKs();

            long cardLoopSize = calcLoopSize(cardPubKey);
            System.out.println(calcEncryptionKey(doorPubKey, cardLoopSize));
        }
    }

    static class PartTwo {
        public static void main(String[] args) {

        }
    }

}
