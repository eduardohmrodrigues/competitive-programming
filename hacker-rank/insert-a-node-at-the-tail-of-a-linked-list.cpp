/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) {
    if(!head) head = new SinglyLinkedListNode(data);
    else{
        SinglyLinkedListNode* next = &(*head);
        while(next->next) next = next->next;
        next->next = new SinglyLinkedListNode(data);
    }

    return head;
}
