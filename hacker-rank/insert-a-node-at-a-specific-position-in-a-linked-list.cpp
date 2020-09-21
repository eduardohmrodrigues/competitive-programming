// Complete the insertNodeAtPosition function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position) {
    SinglyLinkedListNode* actual_head = head;
    while(position != 0){
        head = head->next;
        --position;
    }
    
    SinglyLinkedListNode* new_next = new SinglyLinkedListNode(head->data);
    new_next->next = head->next;
    head->data = data;
    head->next = new_next;

    return actual_head;
}
