class Node{
public:
    int data;
    long height;
    Node* left;
    Node* right;
};

void populateChild(vector<Node*>* search, vector<vector<int>> indexes){
    if(search->size() == 0) return;

    Node* node = search->at(0);
    search->erase(search->begin());

    if(indexes[0][0] > 0) {
        node->left = new Node();
        node->left->data = indexes[0][0];
        node->left->height = node->height+1;
        search->push_back(node->left);
    }

    if(indexes[0][1] > 0) {
        node->right = new Node();
        node->right->data = indexes[0][1];
        node->right->height = node->height+1;
        search->push_back(node->right);
    }

    indexes.erase(indexes.begin());
    populateChild(search, indexes);
}

void swypeNode(vector<Node*>* search, int height) {
    if(search->size() == 0) return;

    Node* node = search->at(0);
    search->erase(search->begin());
    if(node->left != NULL) search->push_back(node->left);
    if(node->right != NULL) search->push_back(node->right);

    if(node->height%height == 0){
        Node* aux = node->left;
        node->left = node->right;
        node->right = aux;
    }

    swypeNode(search, height);
}

vector<int> traversal(Node* node){
    vector<int> otp; otp.clear();
    if(node == NULL) return otp;

    vector<int> left = traversal(node->left);
    vector<int> right = traversal(node->right);
    otp.insert(otp.end(), left.begin(), left.end());
    otp.push_back(node->data);
    otp.insert(otp.end(), right.begin(), right.end());

    return otp;
}
/*
 * Complete the swapNodes function below.
 */
vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries) {
    /*
     * Write your code here.
     */
    Node* head = new Node();
    head->data = 1; head->height = 1;
    vector<Node*> search; search.push_back(head);
    populateChild(&search, indexes);

    vector<vector<int>> output;

    for(int i=0; i<queries.size(); ++i) {            
        search.clear(); search.push_back(head);
        swypeNode(&search, queries[i]);
        output.push_back(traversal(head));
    }

    return output;
}
