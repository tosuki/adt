import java.util.HashMap;

class Vertex {
  public String name;
  public String[] parents;

  public Vertex (String name) {
    this.name = name;
    this.parents = new String[0];
  }

  public Vertex(String name, String ...parents) {
    this.name = name;
    this.parents = parents;
  }
}

class PathFindingAlgorithm {
  private HashMap<String, Vertex> vertexes;

  public PathFindingAlgorithm() {
    this.vertexes = new HashMap<String, Vertex>();
  }

  public PathFindingAlgorithm(HashMap<String, Vertex> vertexes) {
    this.vertexes = vertexes;
  }

  public void addVertex(Vertex vertex) {
    if (this.vertexes.containsKey(vertex.name)) {
      return;
    }

    this.vertexes.put(vertex.name, vertex);
  }

  public String[] getVertexParents(String vertexName) {
    Vertex vertex = this.vertexes.get(vertexName);

    if (vertex == null) {
      return new String[0];
    }

    return vertex.parents;
  }
}

public class Dijkstra {
  public static void main(String[] args) {
    PathFindingAlgorithm algorithm = new PathFindingAlgorithm();
    
    algorithm.addVertex(new Vertex("Carlos", "Victor", "Barbara"));
    algorithm.addVertex(new Vertex("Victor", "Barbara"));
    algorithm.addVertex(new Vertex("Barbara"));

    System.out.printf("Parents: %s\n", String.join(", ", algorithm.getVertexParents("Victor")));
  }
}