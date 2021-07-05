import java.util.*;

class Solution {
    Map<Node, Node> nodes = new HashMap<Node, Node>();
    public Node cloneGraph(Node node) {
        if(node == null) {
            return null;
        }

        if(nodes.containsKey(node)) {
            return nodes.get(node);
        }


        Node cloneNode = new Node(node.val, new ArrayList<>());
        nodes.put(node, cloneNode);

        for (Node neighbor : node.neighbors) {
            cloneNode.neighbors.add(cloneGraph(neighbor));
        }

        return cloneNode;
    }
}