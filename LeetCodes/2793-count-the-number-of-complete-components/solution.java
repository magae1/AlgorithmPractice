class Solution {

    class Vertex implements Comparable<Vertex> {
        public final int n;

        private Set<Vertex> nearest = new HashSet<>();

        public Vertex(int n) {
            this.n = n;
        }

        public void addNear(Vertex vertex) {
            nearest.add(vertex);
        }

        public List<Vertex> getNearest() {
            return List.copyOf(nearest);
        }
        
        public int getNumOfNears() {
            return this.nearest.size();
        }
        
        @Override
        public int compareTo(Vertex o) {
            return Integer.compare(this.n, o.n);
        }
    }

    private int[] parent;

    private Vertex[] vertices;

    public int countCompleteComponents(int n, int[][] edges) {        
        parent = new int[n];
        vertices = new Vertex[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            vertices[i] = new Vertex(i);
        }

        for (int[] edge: edges) {
            union(edge);
            vertices[edge[0]].addNear(vertices[edge[1]]);
            vertices[edge[1]].addNear(vertices[edge[0]]);
        }

        Map<Vertex, Set<Vertex>> group = new HashMap<>();
        for (int i = 0; i < n; i++) {
            int p = find(i);
            group.computeIfAbsent(vertices[p], v -> new HashSet<>()).add(vertices[i]);
        }

        int answer = 0;
        for (Map.Entry<Vertex, Set<Vertex>> groupEntry : group.entrySet()) {
            Vertex keyVertex = groupEntry.getKey();
            Set<Vertex> valueSet = groupEntry.getValue();
            int size = valueSet.size();
            boolean isCompleted = true;
            for (Vertex v : valueSet) {
                if (v.getNumOfNears() + 1 != size) {
                    isCompleted = false;
                    break;
                }
            }
            if (isCompleted) {
                answer += 1;
            }
        }

        return answer;
    }

    private void union(int[] edge) {
        int a = find(edge[0]);
        int b = find(edge[1]);

        if (a == b) return;
        if (a > b) {
            parent[a] = b;
        } else {
            parent[b] = a;
        }
    }

    private int find(int n) {
        if (parent[n] == n) {
            return n;
        }
        parent[n] = find(parent[n]);
        return parent[n];
    }

}
