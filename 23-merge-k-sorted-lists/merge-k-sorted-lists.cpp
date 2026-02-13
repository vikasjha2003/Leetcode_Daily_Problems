class Solution {
public:
    ListNode* mergeTwoLists(ListNode* &list1, ListNode* &list2) {
        ListNode* dummy = new ListNode(-101);
        ListNode* temp = dummy;
        while(list1 && list2) {
            if(list1 -> val <= list2 -> val) {
                temp -> next = list1;
                list1 = list1 -> next;
            } else {
                temp -> next = list2;
                list2 = list2 -> next;
            }
            temp = temp -> next;
        }
        if (list1) temp -> next = list1;
        else temp -> next = list2; 
        return dummy -> next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        if(lists.size() == 1) return lists[0];
        while(lists.size()>1) {
            ListNode* temp1 = lists[0];
            lists.erase(lists.begin());
            ListNode* temp2 = lists[0];
            lists.erase(lists.begin());
            ListNode *newlist = mergeTwoLists(temp1,temp2);
            lists.push_back(newlist);
        }
        return lists[0];
    }
};