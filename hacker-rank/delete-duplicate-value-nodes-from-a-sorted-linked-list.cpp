// Complete the removeDuplicates function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* head) {
    SinglyLinkedListNode* curr = head;
    while(curr != NULL){
        if(curr->next != NULL && curr->data == curr->next->data) {
            curr->next = curr->next->next;
        }else{
            curr = curr->next;
        }
    }

    return head;
}
