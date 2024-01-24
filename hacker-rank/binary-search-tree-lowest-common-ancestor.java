/*
class Node 
    int data;
    Node left;
    Node right;
*/
public static Node lca(Node root, int v1, int v2) {
    int curr = root.data;
    int minV = Math.min(v1, v2);
    int maxV = Math.max(v1, v2);
    
    if (minV < curr && maxV < curr) {
        return lca(root.left, v1, v2);
    } else if (minV > curr && maxV > curr) {
        return lca(root.right, v1, v2);
    }

    return root;
}