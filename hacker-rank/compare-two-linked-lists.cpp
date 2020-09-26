// Complete the compare_lists function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
bool compare_lists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    bool areEqual = true;
    while(areEqual && head1 != NULL && head2 != NULL) {
        areEqual &= head1->data == head2->data;
        head1 = head1->next; head2 = head2->next;
    }

    areEqual &= head1 == NULL && head2 == NULL;
    return areEqual;
}
