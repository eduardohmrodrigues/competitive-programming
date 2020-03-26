
/*
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};
*/
    int getHeight(Node* node){
        if(!node) return 0;
        int lh = 0, rh = 0;

        if(node->left) lh = 1 + getHeight(node->left);
        if(node->right) rh = 1 + getHeight(node->right);
        
        return lh > rh ? lh : rh;
    }

    void printLevel(Node* node, int height){
        if(height == 0){
            cout << node->data << " ";
            return;
        }

        if(node->left){
            printLevel(node->left, height-1);
        }

        if(node->right){
            printLevel(node->right, height-1);
        }
    }

    void levelOrder(Node * root) {
        int height = getHeight(root);
        
        for(int i=0; i<=height; ++i){
            printLevel(root, i);
        }
    }


