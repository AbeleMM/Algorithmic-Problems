import java.util.*;
import java.io.*;

public class Day_7 {

    static Map<String, Map<String, Integer>> getInput() {
        Map<String, Map<String, Integer>> res = new HashMap<>();

        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        String line;

        while (!(line = in.nextLine()).isBlank()) {
            line = line.replaceAll("bags?|contain|,|[.]|no|other", "");
            String[] tokens = line.split("\\s+");

            Map<String, Integer> rule = new HashMap<>();

            for (int i = 2; i < tokens.length; i += 3) {
                rule.put(tokens[i + 1] + " " + tokens[i + 2], Integer.valueOf(tokens[i]));
            }

            res.put(tokens[0] + " " + tokens[1], rule);
        }

        return res;
    }

    static Map<String, Map<String, Integer>> res = getInput();

    static class PartOne {
        public static void main(String[] args) {
            Queue<String> q = new ArrayDeque<>();
            Set<String> visited = new HashSet<>();
            q.add("shiny gold");

            while (!q.isEmpty()) {
                String elem = q.poll();

                for (String key : res.keySet()) {
                    if (res.get(key).containsKey(elem)) {
                        q.add(key);
                        visited.add(key);
                    }
                }
            }

            System.out.println(visited.size());
        }
    }

    static class PartTwo {
        static int dfs(String str) {
            Map<String, Integer> strMap = res.get(str);
            int sum = 0;

            for (String s : strMap.keySet()) {
                sum += strMap.get(s) * (dfs(s) + 1);
            }

            return sum;
        }

        public static void main(String[] args) {
            System.out.println(dfs("shiny gold"));
        }
    }

}
