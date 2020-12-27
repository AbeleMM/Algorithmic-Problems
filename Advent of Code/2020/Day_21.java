import java.util.*;
import java.io.*;

public class Day_21 {

    static Map<Set<String>, Set<String>> readIn() {
        Map<Set<String>, Set<String>> map = new HashMap<>();
        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        String line;

        while (!(line = in.nextLine()).isBlank()) {
            int ind = line.indexOf('(');
            String[] ingredients = line.substring(0, ind - 1).split(" ");
            String[] allergens = line.substring(ind + 10, line.length() - 1).split(", ");
            map.put(new HashSet<>(Arrays.asList(ingredients)), new HashSet<>(Arrays.asList(allergens)));
        }

        return map;
    }

    static Map<Set<String>, Set<String>> map = readIn();

    static Map<String, String> allergenToIngredient(Map<Set<String>, Set<String>> map) {
        Map<String, Set<String>> allergenToIngredients = new HashMap<>();
        for (Map.Entry<Set<String>, Set<String>> entry : map.entrySet()) {
            for (String s : entry.getValue()) {
                Set<String> tempSet;
                if (allergenToIngredients.containsKey(s)) {
                    tempSet = allergenToIngredients.get(s);
                    tempSet.retainAll(entry.getKey());
                }
                else {
                    tempSet = new HashSet<>(entry.getKey());
                    allergenToIngredients.put(s, tempSet);
                }
            }
        }

        Map<String, String> allergenToIngredient = new HashMap<>();

        boolean doing = true;
        while (doing) {
            doing = false;
            for (String s : allergenToIngredients.keySet()) {
                Set<String> val = allergenToIngredients.get(s);
                if (val.size() == 1) {
                    allergenToIngredient.put(s, val.iterator().next());
                    for (String otherS : allergenToIngredients.keySet()) {
                        if (!s.equals(otherS)) {
                            doing = allergenToIngredients.get(otherS).removeAll(val) || doing;
                        }
                    }
                }
            }
        }

        return allergenToIngredient;
    }

    static Map<String,String> allergenToIngredient = allergenToIngredient(map);

    static class PartOne {
        public static void main(String[] args) {
            Map<String, Integer> ingredientCount = new HashMap<>();
            int sol = 0;
            for (Set<String> key :map.keySet()) {
                for (String s : key) {
                    ingredientCount.put(s, ingredientCount.getOrDefault(s, 0) + 1);
                }
            }

            for (String key : ingredientCount.keySet()) {
                boolean found = false;
                for (String otherKey : allergenToIngredient.keySet()) {
                    if (allergenToIngredient.get(otherKey).equals(key)) {
                        found = true;
                        break;
                    }
                }
                sol += found ? 0 : ingredientCount.get(key);
            }

            System.out.println(sol);
        }
    }

    static class PartTwo {
        public static void main(String[] args) {
            Map<String, String> sortedDeadlyIngredients = new TreeMap<>(allergenToIngredient);
            Iterator<String> it = sortedDeadlyIngredients.keySet().iterator();

            while (it.hasNext()) {
                String next = it.next();
                System.out.print(sortedDeadlyIngredients.get(next) + (it.hasNext() ? "," : ""));
            }
        }
    }

}
