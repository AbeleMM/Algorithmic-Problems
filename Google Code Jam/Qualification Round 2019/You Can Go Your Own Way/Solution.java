import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Solution {

//    private static int n;
    private static char[] maze;

    private static Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));

    public static void main(String[] args) {
        int t = in.nextInt();
        for (int i = 1; i <= t; i++) {
            solve();
            System.out.println("Case #" + i + ": " + new String(maze));
        }
    }

    private static void solve() {
        in.nextInt();
        maze = in.next().toCharArray();

        for (int i = 0; i < maze.length; i++)
            maze[i] = maze[i] == 'E' ? 'S' : 'E';
    }
}
