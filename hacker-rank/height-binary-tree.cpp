
/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
    int height(Node* root) {
        // Write your code here.
        int lh = 0, rh = 0;

        if(root->left != NULL){
            lh = 1 + height(root->left);
        }
        if(root->right != NULL){
            rh = 1 + height(root->right);
        }

        return lh > rh ? lh : rh;
    }

