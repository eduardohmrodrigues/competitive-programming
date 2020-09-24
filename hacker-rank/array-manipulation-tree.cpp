class Node { 
public: 
    int a;
    int b;
    long k;
    Node* next; 
}; 

// Complete the arrayManipulation function below.
long arrayManipulation(int n, vector<vector<int>> queries) {
    Node* base = new Node();
    long biggest = 0;
    base->a = 1; base->b = n; base->k = 0;

    for(int i=0; i<queries.size(); ++i){
        int a = queries[i][0], b = queries[i][1], k = queries[i][2];

        Node* curr = base;
        while(curr != NULL){
            if(a <= curr->b){
                if(a > curr->a){
                    Node* newNext = new Node();
                    newNext->a = a;
                    newNext->b = curr->b;
                    newNext->k = curr->k;
                    curr->b = a-1;
                    newNext->next = curr->next;
                    curr->next = newNext;

                    curr = curr->next;
                }

                if(b < curr->b){
                    Node* newNext = new Node();
                    newNext->a = b+1;
                    newNext->b = curr->b;
                    newNext->k = curr->k;
                    curr->b = b;
                    newNext->next = curr->next;
                    curr->next = newNext;
                    curr->k += k;

                    biggest = biggest > curr->k ? biggest : curr->k;
                    curr = NULL;
                }else if(b == curr->b){
                    curr->k += k;
                    biggest = biggest > curr->k ? biggest : curr->k;
                    curr = NULL;
                }else{
                    curr->k += k;
                    a = curr->b+1;
                    biggest = biggest > curr->k ? biggest : curr->k;
                    curr = curr->next;
                }
            }else{
                curr = curr->next;
            }
        }
    }

    return biggest;
}
