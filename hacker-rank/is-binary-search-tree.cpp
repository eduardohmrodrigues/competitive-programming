/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
	struct Node {
		int data;
		Node* left;
		Node* right;
	}
*/
bool checkBST(Node* root, bool treeHasTopLimit, int treeTopLimit, bool treeHasBottomLimit, int treeBottomLimit){
	bool isBST = true;
	
	if(root->left != NULL) {
		isBST = isBST && root->left->data < root->data;
		isBST = isBST && (!treeHasBottomLimit || root->left->data > treeBottomLimit);
		
		isBST = isBST && checkBST(root->left, true, root->data, treeHasBottomLimit, treeBottomLimit);
	}
	
	if(isBST && root->right != NULL) {
		isBST = isBST && root->right->data > root->data;
		isBST = isBST && (!treeHasTopLimit || root->right->data < treeTopLimit);
		
		isBST = isBST && checkBST(root->right, treeHasTopLimit, treeTopLimit, true, root->data);
	}
	
	return isBST;
}

bool checkBST(Node* root) {
	return checkBST(root, false, 0, false, 0);
}
