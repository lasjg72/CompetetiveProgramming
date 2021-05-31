import java.io.InputStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

public class Graph {

    public int[][] adj;
    //public ArrayList<Integer>[] g;
    public ArrayList<Boolean> flag;
    public ArrayList<Integer> dp;
    public int n;

    Graph (InputStream in){
        Scanner sc = new Scanner(in);
        n = Integer.parseInt(sc.next());
        int m = Integer.parseInt(sc.next());
        ArrayList<Integer>[] g = new ArrayList[n];
        // ArrayList<Boolean> flag = new ArrayList<>(Collections.nCopies(n, Boolean.FALSE));
        // ArrayList<Integer> dp = new ArrayList<>(Collections.nCopies(n, 0));
        
        dp = new ArrayList<>(n);
        flag = new ArrayList<>(n);
        for(int i = 0; i < n; i++){
            g[i] = new ArrayList<>();
        }

        //Scanner sc1 = new Scanner(System.in);
        for(int i = 0; i < m; i++){
            int x = Integer.parseInt(sc.next());
            int y = Integer.parseInt(sc.next());
            // System.out.println("x: " + x);
            // System.out.println("y: " + y);
            x--; y--;
            g[x].add(y);
        }
        sc.close();

        adj = new int[n][];
        for(int j = 0; j < n; j++){
            adj[j] = g[j].stream().mapToInt(i->i).toArray();
            //adj[i] = Arrays.copyOf(g[i], g[i].size());
        }

        System.out.println(g[0].get(0));
    
    }

    public static int f(int x, ArrayList<Boolean> flag, ArrayList<Integer> dp, int[][] adj){
        if(flag.get(x).booleanValue()) return dp.get(x).intValue();
        flag.set(x, Boolean.TRUE);
        int fans = 0;
        for(int to : adj[x]){
            fans = Math.max(fans, f(to, flag, dp, adj)+1);
        }
        dp.set(x, fans);
        return dp.get(x).intValue();
    }

    public int cal(ArrayList<Boolean> flag, ArrayList<Integer> dp, int[][] adj){
        int ans = 0;
        for(int i = 0; i < n; i++) ans = Math.max(ans, Graph.f(i, flag, dp, adj));
        return ans;
    }
}
