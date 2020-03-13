/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* fromInt(int x){
        if(x == 0) return NULL;
        ListNode* ln = new ListNode(x%10);
        x /= 10;

        ln->next = fromInt(x);
        return ln;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum=0;
        bool skip = false;
        ListNode* ln = new ListNode(0);
        ln->next = new ListNode(0);
        ListNode* curr = ln->next;

        while(l1 != NULL || l2 != NULL || sum != 0){
            if(skip) curr = curr->next;

            if(l1 != NULL){
                sum += l1->val;
                l1 = l1->next;
            }

            if(l2 != NULL){
                sum += l2->val;
                l2 = l2->next;
            }

            curr->val = sum%10;
            sum /= 10;
            curr->next = new ListNode(0);
            skip = true;
        }

        curr->next = NULL;
        return ln->next;
    }
};
