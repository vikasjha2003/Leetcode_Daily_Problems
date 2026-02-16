class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* h1 = l1;
        ListNode* h2 = l2;
        stack<int> st1;
        stack<int> st2;
        while(h1 || h2) {
            if(h1) {
                st1.push(h1->val);
                h1 = h1->next;
            }
            if(h2) {
                st2.push(h2->val);
                h2 = h2 -> next;
            }
        }
        int carry = 0;
        ListNode* head = NULL;
        while(!st1.empty() || !st2.empty() || carry) {
            if(!st1.empty()) {
                carry += st1.top();
                st1.pop();
            }
            if(!st2.empty()) {
                carry += st2.top();
                st2.pop();
            }
            ListNode* Node = new ListNode(carry%10);
            Node -> next = head;
            head = Node;
            carry /= 10;
        }
        return head;
    }
};