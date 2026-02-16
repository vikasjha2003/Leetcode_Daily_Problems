class Solution {
public:
    ListNode* add(ListNode* l1, ListNode* l2) {
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