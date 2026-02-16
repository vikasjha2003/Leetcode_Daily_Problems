class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* dummy = new ListNode(-1);
        ListNode* t1 = dummy;
        int carry = 0;
        while(temp1 || temp2 || carry) {
            if(temp1) {
                carry += temp1->val;
                temp1 = temp1->next;
            }
            if(temp2) {
                carry += temp2 -> val;
                temp2 = temp2 -> next;
            }
            ListNode* Node = new ListNode(carry%10);
            t1 -> next = Node;
            t1 = Node;
            carry /= 10;
        }
        return dummy -> next;
    }
};