import java.io.*;
import java.util.*;
public class Graph {
  int V;
  LinkedList<Integer> adj[];
  Graph(int v){
    V=v;
    adj=new LinkedList[v]; //allocating memory for the adjacency list.
    for(int j=0;j<v;j++){
      adj[j]= new LinkedList<>();
    }
  }

  void addEdge(int v,int w){
    adj[v].add(w); // adding a edge 
  }

  void DFSUtil(int v, boolean visited[]){
     visited[v]= true; // we use a visited array to keep track of what vertices have already been visited.
     System.out.println(v+" ");

     Iterator<Integer> i = adj[v].listIterator();
     while(i.hasNext()){
        int x =i.next();
        if(!visited[x]){
           DFSUtil(x, visited); 
        }
     }
  }
 

  void DFS(int v){
    boolean visited[] = new boolean[V];
    DFSUtil(v,visited);
  }

  public static void main(String[] args) {
    Scanner scan =new Scanner(System.in);
    int n = scan.nextInt(); // n-> no of vertices in the graph.
    Graph g =new Graph(n);  
    int ne = scan.nextInt(); //ne -> no of edges in the graph.
    int start,end;
    for(int i=0;i<ne;i++){
      start= scan.nextInt(); // start vertex of the edge
      end= scan.nextInt();  // end vertex of the edge
      g.addEdge(start,end);
    }
    int node = scan.nextInt(); // reading the node where to start dfs from.
    g.DFS(node);
  }
}
