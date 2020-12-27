import java.util.*;
import java.io.*;

public class Day_19 {

    static Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));

    static Map<Integer, String> getRules() {
        Map<Integer, String> map = new HashMap<>();
        String line;
        while (!(line = in.nextLine()).isBlank()) {
            int ind = line.indexOf(':');
            map.put(Integer.valueOf(line.substring(0, ind)), line.substring(ind + 2));
        }
        return map;
    }

    static Set<String> getValid(Map<Integer, String> map, String rule, int maxLen) {
        Set<String> valid = new HashSet<>();
        int ind;

        if (maxLen > 0 && rule.equals(map.get(8))) {
            Set<String> l = getValid(map, map.get(42), 0);

            StringBuilder init = new StringBuilder("(");
            for (String s : l) {
                init.append(s).append("|");
            }
            init.replace(init.length() - 1, init.length(), ")+");

            valid.add(init.toString());
        }
        else if (maxLen > 0 && rule.equals(map.get(11))) {
            Set<String> l = getValid(map, map.get(42), 0), r = getValid(map, map.get(31), 0);

            StringBuilder initL = new StringBuilder("(");
            for (String s : l) {
                initL.append(s).append("|");
            }
            initL.replace(initL.length() - 1, initL.length(), ")");

            StringBuilder initR = new StringBuilder("(");
            for (String s : r) {
                initR.append(s).append("|");
            }
            initR.replace(initR.length() - 1, initR.length(), ")");

            for (int i = 1; i < maxLen; i++) {
                valid.add(initL + "{" + i + "}" + initR + "{" + i + "}");
            }
        }
        else if (rule.matches("\"([ab])\"")) {
            valid.add(Character.toString(rule.charAt(1)));
        }
        else if (rule.matches("\\d+")) {
            valid.addAll(getValid(map, map.get(Integer.valueOf(rule)), maxLen));
        }
        else if ((ind = rule.indexOf("|")) != -1) {
            valid.addAll(getValid(map, rule.substring(0, ind - 1), maxLen));
            valid.addAll(getValid(map, rule.substring(ind + 2), maxLen));
        }
        else {
            ind = rule.indexOf(" ");
            Set<String> pre = getValid(map, rule.substring(0, ind), maxLen),
                    post = getValid(map, rule.substring(ind + 1), maxLen);

            for (String s : pre) {
                for (String t : post) {
                    valid.add(s + t);
                }
            }
        }

        return valid;
    }

    static class PartOne {
        public static void main(String[] args) {
            Map<Integer, String> map = getRules();
            Set<String> valid = getValid(map, map.get(0), 0);

            String line;
            int res = 0;
            while(!(line = in.nextLine()).isBlank()) {
                if (valid.contains(line)) {
                    res++;
                }
            }

            System.out.println(res);
        }
    }

    static class PartTwo {
        public static void main(String[] args) {
            Map<Integer, String> map = getRules();

            List<String> msgList = new ArrayList<>();
            int maxLen = 0, res = 0;
            String line;
            while(!(line = in.nextLine()).isBlank()) {
                if (line.length() > maxLen) {
                    maxLen = line.length();
                }
                msgList.add(line);
            }

            Set<String> valid = getValid(map, map.get(0), maxLen);
            for (String msg : msgList) {
                for (String exp : valid) {
                    if (msg.matches(exp)) {
                        res++;
                        break;
                    }
                }
            }

            System.out.println(res);
        }
    }

}
