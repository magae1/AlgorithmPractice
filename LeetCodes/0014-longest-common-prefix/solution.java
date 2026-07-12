class Solution {

    class Node {
        public final char ch;

        private final Set<Node> nextSet = new HashSet<>();

        public Node() {
            this.ch = Character.MIN_VALUE;
        }

        public Node(char ch) {
            this.ch = ch;
        }
        
        public Node getNext(char ch) {
            for (Node n : nextSet) {
                if (n.ch == ch) {
                    return n;
                }
            }
            return null;
        }

        public void addNext(Node node) {
            nextSet.add(node);
        }

        public boolean hasNext() {
            return nextSet.size() == 1;
        }

        public Node getNext() {
            return nextSet.stream().findFirst().orElse(null);
        }

        @Override
        public String toString() {
            return "Node: " + ch;
        }
    }
    
    public String longestCommonPrefix(String[] strs) {
        Node root = new Node();
        int length = Integer.MAX_VALUE;
        for (String str : strs) {
            if (str.isBlank()) {
                return "";
            }

            length = Math.min(length, str.length());
            Node currentNode = root;
            for (char ch : str.toCharArray()) {
                Node next = currentNode.getNext(ch);
                if (next == null) {
                    Node newOne = new Node(ch);
                    currentNode.addNext(newOne);
                    currentNode = newOne;
                } else {
                    currentNode = next;
                }
            }
        }

        StringBuilder sb = new StringBuilder();
        Node currentNode = root;
        while(currentNode.hasNext() && length > 0) {
            System.out.println(currentNode);
            currentNode = currentNode.getNext();
            sb.append(currentNode.ch);
            length--;
        }

        return sb.toString();
    }
}
