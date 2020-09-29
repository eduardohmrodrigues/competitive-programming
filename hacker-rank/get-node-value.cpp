// Complete the getNode function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
int getNode(SinglyLinkedListNode* head, int positionFromTail) {
    SinglyLinkedListNode* curr = head;
    int sz = 0;
    while(curr != NULL) {
        curr = curr->next;
        ++sz;
    }

    int it = sz - positionFromTail - 1;
    while(it > 0){
        head = head->next;
        --it;
    }

    return head->data;
}
