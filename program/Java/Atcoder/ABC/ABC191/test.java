// May The Father of Understanding Guide Us
import java.util.*;
import java.io.*;
public class test
{
  static int nmax = (int)2e5 + 10;
  static ArrayList<Integer> [] arr = new ArrayList[nmax];
  static boolean [] visited = new boolean[nmax];
  static int [] dist = new int[nmax];
  static void dfs(int u)
  {
    visited[u] = true;
    for(Integer i: arr[u])
    {
      if(!visited[i])
      {
        dfs(i);
      }
      
      dist[u] = Math.max(dist[u], dist[i]+1);
    }
  }
  
  public static void main(String[] args) throws IOException
  {
    Scanner read = new Scanner(System.in);
    
    int n = read.nextInt();
    int m = read.nextInt();
    for(int i = 0; i<n+1; i++)
    {
      arr[i] = new ArrayList<Integer>();
    }
    
    for(int i = 0; i<m; i++)
    {
      int u = read.nextInt();
      int v = read.nextInt();
      
      arr[u].add(v);
    }

    for(int i = 1; i<=n; i++)
    {
      if(!visited[i])
      {
        dfs(i);
      }
    }
    
    Arrays.sort(dist);
    System.out.println(dist[nmax-1]);
  }
}