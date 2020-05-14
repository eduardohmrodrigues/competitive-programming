/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
bool has_cycle(SinglyLinkedListNode* head) {
    set<SinglyLinkedListNode*> pointers;
    while(head){
        if(pointers.find(head) != pointers.end()){
            return true;
        }

        pointers.insert(head);
        head = head->next;
    }
    return false;
}
