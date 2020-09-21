// Complete the sortedInsert function below.

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
DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* head, int data) {
    DoublyLinkedListNode* head_backup = head;
    while(head->data < data && head->next != NULL){
        head = head->next;
    }
    
    DoublyLinkedListNode* new_node = new DoublyLinkedListNode(data);
    if(head->data < data){
        head->next = new_node;
    }else{
        new_node->prev = head->prev;
        if(new_node->prev != NULL) new_node->prev->next = new_node;

        new_node->next = head;
        head->prev = new_node;
    }

    if(head_backup->prev != NULL) return head_backup->prev;
    else return head_backup;
}
