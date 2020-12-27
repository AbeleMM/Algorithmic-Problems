import java.util.*;
import java.io.*;

public class Day_16 {

    static void readIn() {
        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        String line;

        while (!(line = in.nextLine()).isBlank()) {
            int colonInd = line.indexOf(":");
            String[] nrs = line.substring(colonInd + 2).split(" or |-");
            int[] val = new int[nrs.length];
            for (int i = 0; i < nrs.length; i++) {
                val[i] = Integer.parseInt(nrs[i]);
            }
            fieldMap.put(line.substring(0, colonInd), val);
        }

        in.nextLine();
        line = in.nextLine();
        for (String nr : line.split(",")) {
            myTicket.add(Integer.valueOf(nr));
        }

        in.nextLine();
        in.nextLine();
        while (!(line = in.nextLine()).isBlank()) {
            List<Integer> ticket = new ArrayList<>();
            for (String nr : line.split(",")) {
                ticket.add(Integer.valueOf(nr));
            }
            tickets.add(ticket);
        }
    }

    static Map<String, int[]> fieldMap = new HashMap<>();
    static List<Integer> myTicket = new ArrayList<>();
    static List<List<Integer>> tickets = new ArrayList<>();

    static class PartOne {
        public static void main(String[] args) {
            readIn();

            int sum = 0;
            for (List<Integer> ticket : tickets) {
                for (Integer field : ticket) {
                    boolean valid = false;
                    for (String key : fieldMap.keySet()) {
                        int[] val = fieldMap.get(key);
                        if ((val[0] <= field && field <= val[1]) || (val[2] <= field && field <= val[3])) {
                            valid = true;
                            break;
                        }
                    }
                    if (!valid) {
                        sum += field;
                    }
                }
            }

            System.out.println(sum);
        }
    }

    static class PartTwo {
        public static void main(String[] args) {
            readIn();

            Iterator<List<Integer>> it = tickets.iterator();
            while (it.hasNext()) {
                List<Integer> ticket = it.next();
                boolean validTicket = true;

                for (Integer field : ticket) {
                    boolean validField = false;
                    for (String key : fieldMap.keySet()) {
                        int[] val = fieldMap.get(key);
                        if ((val[0] <= field && field <= val[1]) || (val[2] <= field && field <= val[3])) {
                            validField = true;
                            break;
                        }
                    }
                    if (!validField) {
                        validTicket = false;
                        break;
                    }
                }

                if (!validTicket) {
                    it.remove();
                }
            }

            Map<String, List<Integer>> order = new HashMap<>();
            for (String key : fieldMap.keySet()) {
                int[] mapVal = fieldMap.get(key);
                List<Integer> list = new ArrayList<>();
                // for each ticket index
                for (int i = 0; i < tickets.get(0).size(); i++) {
                    boolean ok = true;
                    // check all tickets
                    for (List<Integer> ticket : tickets) {
                        int ticketIndI = ticket.get(i);
                        if ((mapVal[0] > ticketIndI || ticketIndI > mapVal[1]) && (mapVal[2] > ticketIndI || ticketIndI > mapVal[3])) {
                            ok = false;
                            break;
                        }
                    }
                    if (ok) {
                        list.add(i);
                    }
                }
                order.put(key, list);
            }

            boolean loop;
            do {
                loop = false;
                for (List<Integer> val : order.values()) {
                    if (val.size() == 1) {
                        for (List<Integer> otherVal : order.values()) {
                            if (otherVal != val) {
                                otherVal.remove(val.get(0));
                            }
                        }
                    }
                    else {
                        loop = true;
                    }
                }
            } while (loop);

            long res = 1;
            for (String key : order.keySet()) {
                if (key.matches("departure.*")) {
                    res *= myTicket.get(order.get(key).get(0));
                }
            }
            System.out.println(res);
        }
    }

}
