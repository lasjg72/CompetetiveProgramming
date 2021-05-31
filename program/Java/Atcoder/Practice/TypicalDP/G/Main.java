

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Queue;
import java.util.Scanner;

public class Main {
    
    // public static ArrayList<Boolean> flag;
    // public static ArrayList<Integer> dp;
    // static ArrayList<Integer>[] g;

    public static int calc(int x, ArrayList<Boolean> flag, ArrayList<Integer> dp, ArrayList<Integer>[] g){
        if(flag.get(x).booleanValue()) return dp.get(x).intValue();
        flag.set(x, Boolean.TRUE);
        int fans = 0;
        for(int to : g[x]){
            //System.out.println("to: " + to);
            fans = Math.max(fans, calc(to, flag, dp, g)+1);
        }
        dp.set(x, fans);
        return dp.get(x).intValue();
    }

    public static void main(String[] args) {

        //Scanner sc = new Scanner(System.in);
        
        //sc.close();
        // ArrayList<Integer>[] g = new ArrayList[n];
        // ArrayList<Boolean> flag = new ArrayList<>(Collections.nCopies(n, Boolean.FALSE));
        // ArrayList<Integer> dp = new ArrayList<>(Collections.nCopies(n, 0));

        // for(int i = 0; i < n; i++){
        //     g[i] = new ArrayList<>();
        // }

        // //System.out.println(dp.get(0));

        // for(int i = 0; i < m; i++){
        //     int x = Integer.parseInt(sc.next());
        //     int y = Integer.parseInt(sc.next());
        //     x--; y--;
        //     g[x].add(y);
        // }
        
        Graph gra = new Graph(System.in);
        // System.out.println("main: " + gra.dp.get(0));
        System.out.println("main: " + gra.adj[0][0]);
        //sc.close();
        System.out.println(gra.cal(gra.flag, gra.dp, gra.adj));
    }
}