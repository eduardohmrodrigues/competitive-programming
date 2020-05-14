/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* head, int position) {
    if(!head) return head;
    else if(position == 0) return head->next;
    
    SinglyLinkedListNode* bkp = &(*head);
    --position;
    while(position && head){
        head = head->next;
        --position;
    }

    if(head && head->next) head->next = head->next->next;
    return bkp;
}
