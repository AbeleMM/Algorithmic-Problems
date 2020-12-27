import java.util.*;
import java.io.*;
import java.util.function.BiFunction;

public class Day_18 {


    static long solveAll(BiFunction<Character, Character, Boolean> hasPrecedence) {
        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        String exp;
        long res = 0;
        
        while (!(exp = in.nextLine()).isBlank()) {
            res += solve(exp.toCharArray(), hasPrecedence);
        }

        return res;
    }

    static long solve(char[] tokens, BiFunction<Character, Character, Boolean> hasPrecedence) {
        Stack<Long> values = new Stack<>();

        Stack<Character> ops = new Stack<>();

        for (int i = 0; i < tokens.length; i++)
        {
            if (tokens[i] >= '0' && tokens[i] <= '9') {
                StringBuilder sb = new StringBuilder();

                while (i < tokens.length && tokens[i] >= '0' && tokens[i] <= '9')
                    sb.append(tokens[i++]);

                values.push(Long.parseLong(sb.toString()));

                i--;
            }

            else if (tokens[i] == '(')
                ops.push(tokens[i]);

            else if (tokens[i] == ')') {
                while (ops.peek() != '(')
                    values.push(applyOp(ops.pop(), values.pop(), values.pop()));

                ops.pop();
            }

            else if (tokens[i] == '+' || tokens[i] == '*') {
                while (!ops.empty() && hasPrecedence.apply(tokens[i], ops.peek()))
                    values.push(applyOp(ops.pop(), values.pop(), values.pop()));

                ops.push(tokens[i]);
            }
        }

        while (!ops.empty())
            values.push(applyOp(ops.pop(), values.pop(), values.pop()));

        return values.pop();
    }

    public static long applyOp(char op, long b, long a) {
        switch (op) {
            case '+':
                return a + b;
            case '*':
                return a * b;
        }
        return 0;
    }

    static class PartOne {
        public static void main(String[] args) {
            BiFunction<Character, Character, Boolean> precedenceFunc = (a, b) -> b != '(' && b != ')';
            System.out.println(solveAll(precedenceFunc));
        }
    }

    static class PartTwo {
        public static void main(String[] args) {
            BiFunction<Character, Character, Boolean> precedenceFunc = (a, b) -> {
                if (b == '(' || b == ')')
                    return false;
                return a != '+' || b != '*';
            };
            System.out.println(solveAll(precedenceFunc));
        }
    }

}
