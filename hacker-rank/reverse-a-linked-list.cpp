// Complete the reverse function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* reverse(SinglyLinkedListNode* head) {
    SinglyLinkedListNode* ret = new SinglyLinkedListNode(head->data);

    while(head->next != NULL){
        head = head->next;
        SinglyLinkedListNode* aux = new SinglyLinkedListNode(head->data);
        aux->next = ret;
        ret = aux;
    }

    return ret;
}
