// Complete the findMergeNode function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    while(head1 != NULL){
        SinglyLinkedListNode* curr = head2;

        while(curr != NULL){
            if(head1 == curr) return curr->data;
            curr = curr->next;
        }
        head1 = head1->next;
    }

    return -1;
}
