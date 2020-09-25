/* 
The structure of the node is

typedef struct node {

	int freq;
    char data;
    node * left;
    node * right;
    
} node;

*/


void decode_huff(node * root, string s) {
    node* curr = root;
    for(int i=0; i<s.length(); ++i){
        if(s[i] == '1'){
            curr = curr->right;
        }else{
            curr = curr->left;
        }

        if(curr->right == NULL && curr->left == NULL){
            cout << curr->data;
            curr = root;
        }
    }

    cout << endl;
}
