// Complete the mergeLists function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode* otp = new SinglyLinkedListNode(0);
    SinglyLinkedListNode* curr = otp;

    while(head1 != NULL || head2 != NULL) {
        if(head1 != NULL && head2 != NULL){
            if(head1->data < head2->data){
                curr->data = head1->data;
                head1 = head1->next;
            }else{
                curr->data = head2->data;
                head2 = head2->next;
            }
        }else if(head1 != NULL){
                curr->data = head1->data;
                head1 = head1->next;
        }else{
                curr->data = head2->data;
                head2 = head2->next;
        }
        
        if(head1 != NULL || head2 != NULL){
            curr->next = new SinglyLinkedListNode(0);
            curr = curr->next;
        }
    }

    return otp;
}
