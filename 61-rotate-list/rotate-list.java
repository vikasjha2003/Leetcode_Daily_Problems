class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if(head == null) return head;
        ListNode temp = head;
        int n = 1;
        while(temp.next != null) {
            n++;
            temp = temp.next;
        }

        k = k%n;

        ListNode temp1 = head;

        for(int i = 1; i<n-k; i++) temp1 = temp1.next;

        temp.next = head;
        temp = temp1.next;
        temp1.next = null;

        return temp;
    }
}