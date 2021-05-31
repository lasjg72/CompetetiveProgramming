import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Queue;
import java.util.Scanner;

//import java.util.*;

public class Main {
    public static int f (int x){
        
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.next());
        int m = Integer.parseInt(sc.next());
        //ArrayList<ArrayList<Integer>> g = new ArrayList<ArrayList<Integer>[n]>();
        
        ArrayList<Integer>[] g = new ArrayList[n];
        ArrayList<Integer>[] in = new ArrayList[n];

        for(int i = 0; i < n; i++){
            g[i] = new ArrayList<Integer>();
            in[i] = new ArrayList<Integer>();
        }

        for(int i = 0; i < m; i++){
            int x = Integer.parseInt(sc.next());
            int y = Integer.parseInt(sc.next());
            x--; y--;
            g[x].add(y);
            in[y].add(x);
        }

        sc.close();
        
    }
}