// Complete the reverse function below.

/*
 * For your reference:
 *
 * DoublyLinkedListNode {
 *     int data;
 *     DoublyLinkedListNode* next;
 *     DoublyLinkedListNode* prev;
 * };
 *
 */
DoublyLinkedListNode* reverse(DoublyLinkedListNode* head) {
    DoublyLinkedListNode* backup;
    while(head->next != NULL) {
        backup = head->next;
        head->next = head->prev;
        head->prev = backup;
        head = head->prev;
    }

    head->next = head->prev;
    return head;
}
